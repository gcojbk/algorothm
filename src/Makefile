BASE=test_sort

all: compile

compile:
	clang++ test_sort.cc sort.cc -o ${BASE} -g

test:
	./${BASE}

clean:
	rm ${BASE}