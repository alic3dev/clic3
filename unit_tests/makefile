name=unit_tests
name_clic3=clic3

directory_binary=binary
directory_clic3_include=../include
directory_clic3_library=../library
directory_include=include
directory_objects=objects
directory_sources=sources

file_binary=${directory_binary}/${name}
file_object_clic3=${directory_clic3_library}/${name_clic3}.o

files_sources=${wildcard ${directory_sources}/*.c}
files_objects=${patsubst ${directory_sources}/%.c,${directory_objects}/%.o,${files_sources}}

cc=gcc
c_flags=-O3 -I${directory_include} -I${directory_clic3_include}

${name}: ${file_binary}

${file_binary}: ${files_objects} ${directory_binary}
	${cc} ${c_flags} ${files_objects} ${file_object_clic3} -o ${file_binary}

${directory_objects}/%.o: ${directory_sources}/%.c ${directory_objects}
	${cc} ${c_flags} -c $< -o $@

${directory_binary}:
	mkdir -p ${directory_binary}

${directory_objects}:
	mkdir -p ${directory_objects}

clean:
	-rm -r ${directory_binary} 2> /dev/null
	-rm -r ${directory_objects} 2> /dev/null

