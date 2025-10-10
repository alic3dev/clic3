name=clic3

directory_include=include
directory_library=library
directory_objects=objects
directory_sources=sources
directory_unit_tests=unit_tests
directory_output_unit_tests=${directory_unit_tests}/output

file_library_object=${directory_library}/${name}.o
file_library_dylib=${directory_library}/${name}.dylib
file_library_dynamic=${directory_library}/${name}.so
file_library_static=${directory_library}/${name}.a

files_sources=${wildcard ${directory_sources}/*.c}
files_objects=${patsubst ${directory_sources}/%.c,${directory_objects}/%.o,${files_sources}}

cc=gcc
c_flags=-O3 -I${directory_include}

ar=ar
ar_flags=cqS

ld=ld
ld_flags=-S -x

${name}: ${file_library_dylib} ${file_library_dynamic} ${file_library_object} ${file_library_static}

${name}_objects: ${files_objects}

${name}_dylib: ${file_library_dylib}
${name}_dynamic: ${file_library_dynamic}
${name}_object: ${file_library_object}
${name}_static: ${file_library_static}

all: ${name} rebuild_unit_tests run_unit_tests

${file_library_dylib}: ${files_objects}
	mkdir -p ${directory_library}
	${cc} -dynamiclib ${files_objects} -o ${file_library_dylib}

${file_library_dynamic}: ${files_objects}
	mkdir -p ${directory_library}
	${cc} -shared ${files_objects} -o ${file_library_dynamic}

${file_library_object}: ${files_objects}
	mkdir -p ${directory_library}
	${ld} ${ld_flags} -r ${files_objects} -o ${file_library_object}

${file_library_static}: ${files_objects}
	mkdir -p ${directory_library}
	${ar} ${ar_flags} ${file_library_static} ${files_objects}

${directory_objects}/%.o: ${directory_sources}/%.c
	mkdir -p ${directory_objects}
	${cc} ${c_flags} -c $< -o $@

unit_tests: ${file_library_object}
	cd ${directory_unit_tests} && make

unit_tests_rebuild:
	cd ${directory_unit_tests} && make rebuild

unit_tests_run:
	cd ${directory_unit_tests} && make test

clean_all: clean clean_unit_tests

clean: clean_objects clean_library

clean_objects:
	-rm -r ${directory_objects}/* 2> /dev/null

clean_library:
	-rm -r ${directory_library} 2> /dev/null

clean_unit_tests:
	cd ${directory_unit_tests} && make clean
