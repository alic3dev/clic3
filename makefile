name=clic3

ifndef target_device
target_device=mac
endif

ifeq (${target_device},mac)
target_os=macos
endif

ifeq (${target_device},iphone)
target_os=ios
name:=${name}_${target_os}
endif

version_major=0
version_minor=1
version_patch=0
version_major_minor=${version_major}.${version_minor}
version=${version_major}.${version_minor}.${version_patch}

directory_air_base=air
directory_metalar_base=metalar
directory_objects_base=objects
directory_library_base=library

directory_air=${directory_air_base}/${target_os}
directory_library=${directory_library_base}/${target_os}/release
directory_metalar=${directory_metalar_base}/${target_os}
directory_objects=${directory_objects_base}/${target_os}/release

ifeq (${debug}, 1)
name:=${name}_debug
directory_objects=${directory_objects_base}/${target_os}/debug
directory_library=${directory_library_base}/${target_os}/debug
endif

directory_include=include
directory_sources=sources
directory_unit_tests=unit_tests
directory_output_unit_tests=${directory_unit_tests}/output

directory_install=/System/Volumes/Preboot/Cryptexes

file_library_object=${directory_library}/${name}.o

name_library_dylib_major=${name}.${version_major}.dylib
file_library_dylib=${directory_library}/${name}.dylib
file_library_dylib_major=${directory_library}/${name_library_dylib_major}

file_install=${directory_install}/OS${name}.dylib
file_install_major=${directory_install}/OS${name_library_dylib_major}

name_library_dynamic_major=${name}.${version_major}.so
file_library_dynamic=${directory_library}/${name}.so
file_library_dynamic_major=${directory_library}/${name_library_dynamic_major}

file_library_static=${directory_library}/${name}.a

files_sources=${wildcard ${directory_sources}/*.c}
files_air=${patsubst ${directory_sources}/%.c, ${directory_air}/%.air, ${files_sources}}
files_metalar=${patsubst ${directory_air}/%.air, ${directory_metalar}/%.metalar, ${files_air}}
files_objects=${patsubst ${directory_sources}/%.c,${directory_objects}/%.o,${files_sources}}

ifndef target_device_version
target_device_version=26.1
endif

ifndef target_metal_version
target_metal_version=${target_device_version}
endif

ifndef target_metal_standard
target_metal_standard=metal4.0
endif

ifeq (${target_os},macos)
target_platform=arm64-apple-macos${target_device_version}
target_platform_metal=air64-apple-macos${target_metal_version}

directory_sdk=${shell xcrun --sdk macosx${target_device_version} --show-sdk-path}
endif

ifeq (${target_os},ios)
files_objects:=${patsubst ${directory_objects}/%.o,${directory_objects}/%_${target_os}.o,${files_objects}}

target_platform=arm64-apple-ios${target_device_version}
target_platform_metal=air64-apple-ios${target_metal_version}

directory_sdk=${shell xcrun --sdk iphoneos${target_device_version} --show-sdk-path}
endif

cc=clang
c_flags_platform=-target ${target_platform} -isysroot ${directory_sdk}
c_flags=-I${directory_include} ${c_flags_platform}

ifeq (${debug}, 1)
c_flags:=${c_flags} -O0 -g -v
else
c_flags:=${c_flags} -O3
endif

ar=ar
ar_flags=cqS

ld=ld
ld_flags=

strip=strip
strip_flags=-x

metal=xcrun -sdk macosx metal
metal_ar=xcrun -sdk macosx metal-ar
metallib=xcrun -sdk macosx metallib
metal_flags_common=-target ${target_platform_metal} -std=${target_metal_standard}

metal_flags=${metal_flags_common} -I${directory_include} -isysroot ${directory_sdk} -x metal

ifneq (${disable_metal_fast_options}, 1)
metal_flags:=${metal_flags} -fmetal-math-mode\=fast -fmetal-math-fp32-functions\=fast
endif

metal_flags_output=

${name}: ${file_library_dylib} ${file_library_dynamic} ${file_library_object} ${file_library_static} ${files_air} ${files_metalar} ${file_library_metallib}

${name}_air: ${files_air}
${name}_metalar: ${files_metalar}
${name}_metallib: ${file_library_metallib}

${name}_objects: ${files_objects}

${name}_dylib: ${file_library_dylib}
${name}_dynamic: ${file_library_dynamic}
${name}_object: ${file_library_object}
${name}_static: ${file_library_static}

all: ${name} unit_tests_rebuild unit_tests_run

install: ${file_library_dylib}
	mkdir -p "${directory_install}"
	dd if="${file_library_dylib_major}" of="${file_install_major}"
	ln -s "${file_install_major}" "${file_install}"

${file_library_dylib}: ${files_objects}
	mkdir -p ${directory_library}
	${cc} -dynamiclib ${c_flags_platform} -install_name ${name_library_dylib_major} -current_version ${version} -compatibility_version ${version_major_minor} ${files_objects} -o ${file_library_dylib_major}
ifneq (${debug}, 1)
	${strip} ${strip_flags} ${file_library_dylib_major}
endif
	-rm ${file_library_dylib}
	ln -s ${name_library_dylib_major} ${file_library_dylib}

${file_library_dynamic}: ${files_objects}
	mkdir -p ${directory_library}
	${cc} -shared ${c_flags_platform} -install_name ${name_library_dynamic_major} -current_version ${version} -compatibility_version ${version_major_minor} ${files_objects} -o ${file_library_dynamic_major}
ifneq (${debug}, 1)
	${strip} ${strip_flags} ${file_library_dynamic_major}
endif
	-rm ${file_library_dynamic}
	ln -s ${name_library_dynamic_major} ${file_library_dynamic}

${file_library_object}: ${files_objects}
	mkdir -p ${directory_library}
	${ld} ${ld_flags} -r ${files_objects} -o ${file_library_object}
ifneq (${debug}, 1)
	${strip} ${strip_flags} ${file_library_object}
endif

${file_library_static}: ${files_objects}
	mkdir -p ${directory_library}
	${ar} ${ar_flags} ${file_library_static} ${files_objects}

${directory_objects}/%.o: ${directory_sources}/%.c
	mkdir -p ${directory_objects}
	${cc} ${c_flags} -c $< -o $@

${directory_objects}/%_ios.o: ${directory_sources}/%.c
	mkdir -p ${directory_objects}
	${cc} ${c_flags} -c $< -o $@

${file_library_metallib}: ${files_metalar}
	mkdir -p "${dir $@}"
	${metallib} ${metal_flags_output} ${files_metalar} -o ${file_library_metallib}
		
${directory_metalar}/%.metalar: ${directory_air}/%.air
	mkdir -p "${dir $@}"
	if [[ -f $@ ]]; then rm $@; fi
	${metal_ar} -rc $@ $<
					
${directory_air}/%.air: ${directory_sources}/%.c
	mkdir -p "${dir $@}"
	${metal} ${metal_flags} -c $< -o $@

unit_tests: ${file_library_object} .always
	cd ${directory_unit_tests} && make target_device_version=${target_device_version}

unit_tests_rebuild:
	cd ${directory_unit_tests} && make rebuild target_device_version=${target_device_version}

unit_tests_run:
	cd ${directory_unit_tests} && make test target_device_version=${target_device_version}

clean_all: clean clean_unit_tests

clean: clean_library clean_objects

clean_library:
	-rm -r ${directory_library_base} 2> /dev/null

clean_objects:
	-rm -r ${directory_objects_base} 2> /dev/null

clean_unit_tests:
	cd ${directory_unit_tests} && make clean target_device_version=${target_device_version}

.always:
