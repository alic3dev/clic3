name=unit_tests
name_clic3=clic3

directory_output=output
directory_clic3_include=../include
directory_clic3_library=../library
directory_include=include
directory_objects=objects
directory_sources=sources

file_output=${directory_output}/${name}
file_object_clic3=${directory_clic3_library}/${name_clic3}.o

files_sources=${wildcard ${directory_sources}/*.c}
files_objects=${patsubst ${directory_sources}/%.c,${directory_objects}/%.o,${files_sources}}

cc=gcc
c_flags=-O3 -I${directory_include} -I${directory_clic3_include}

${name}: ${file_output}

rebuild: clean_output ${file_output}

test: ${file_output}
	./${file_output}

${file_output}: ${files_objects} ${directory_output}
	${cc} ${c_flags} ${files_objects} ${file_object_clic3} -o ${file_output}

${directory_objects}/%.o: ${directory_sources}/%.c ${directory_objects}
	${cc} ${c_flags} -c $< -o $@

${directory_output}:
	mkdir -p ${directory_output}

${directory_objects}:
	mkdir -p ${directory_objects}

clean: clean_output
	-rm -r ${directory_objects} 2> /dev/null

clean_output:
	-rm -r ${directory_output} 2> /dev/null

