name=unit_tests
name_clic3=clic3

directory_objects_base=objects
directory_objects=${directory_objects_base}/release
directory_output=output

directory_clic3_library=../library

ifeq (${debug}, 1)
	name:=${name}_debug
	name_clic3:=${name_clic3}_debug

	directory_objects=${directory_objects_base}/debug

	directory_clic3_library=../library_debug
endif

directory_include=include
directory_sources=sources

directory_clic3_include=../include

file_output=${directory_output}/${name}
file_object_clic3=${directory_clic3_library}/${name_clic3}.o

files_sources=${wildcard ${directory_sources}/*.c}
files_objects=${patsubst ${directory_sources}/%.c,${directory_objects}/%.o,${files_sources}}

cc=gcc
c_flags=-I${directory_include} -I${directory_clic3_include}

ifeq (${debug}, 1)
	c_flags:=${c_flags} -O0 -g -v -da -Q
else
	c_flags:=${c_flags} -O3
endif

${name}: ${file_output}

rebuild: clean_output_file ${file_output}

test: ${file_output}
	./${file_output}

${file_output}: ${files_objects}
	mkdir -p ${directory_output}
	${cc} ${c_flags} ${files_objects} ${file_object_clic3} -o ${file_output}

${directory_objects}/%.o: ${directory_sources}/%.c
	mkdir -p ${directory_objects}
	${cc} ${c_flags} -c $< -o $@

clean: clean_objects clean_output

clean_objects:
	-rm -r ${directory_objects_base} 2> /dev/null

clean_output:
	-rm -r ${directory_output}

clean_output_file:
	-rm file_output 2> /dev/null
