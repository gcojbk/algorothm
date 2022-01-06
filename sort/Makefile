BASE=test_sort

all: compile

compile:
	clang++ test_sort.cc bubble_sort.cc select_sort.cc insert_sort.cc merge_sort.cc -o ${BASE}

test:
	./${BASE}

clean:
	rm ${BASE}