name=clic3

directory_include=include
directory_library=library
directory_objects=objects
directory_sources=sources
directory_unit_tests=unit_tests
directory_output_unit_tests=${directory_unit_tests}/output

file_library=${directory_library}/${name}.o

files_sources=${wildcard ${directory_sources}/*.c}
files_objects=${patsubst ${directory_sources}/%.c,${directory_objects}/%.o,${files_sources}}

cc=gcc
c_flags=-O3 -I${directory_include}

ld=ld
ld_flags=

strip=strip
strip_flags=-x

${name}: ${file_library}

all: ${file_library} ${directory_unit_tests} rebuild_unit_tests run_unit_tests

${file_library}: ${directory_library} ${files_objects}
	${ld} ${ld_flags} -r ${files_objects} -o $@
	${strip} ${strip_flags} ${file_library}

${directory_objects}/%.o: ${directory_sources}/%.c ${directory_objects}
	${cc} ${c_flags} -c $< -o $@

${directory_unit_tests}: ${file_library} .force
	cd ${directory_unit_tests} && make

rebuild_unit_tests: 
	cd ${directory_unit_tests} && make rebuild

run_unit_tests: ${directory_unit_tests}
	cd ${directory_unit_tests} && make test

directories: ${directory_library} ${directory_objects}

${directory_library}:
	mkdir -p ${directory_library}

${directory_objects}:
	mkdir -p ${directory_objects}

clean:
	-rm ${directory_objects}/* 2> /dev/null
	-rm ${file_library} 2> /dev/null

clean_unit_tests:
	cd ${directory_unit_tests} && make clean

clean_all: clean clean_unit_tests

.force:
