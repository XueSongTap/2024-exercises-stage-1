CC ?= gcc

CFLAGS	= -std=c11 -Wall -Wextra -Wpedantic -Werror -g
LDFLAGS = -Wl,--as-needed -Wl,--no-undefined

OUTPUT_DIR ?= .

SRCS		= main.c
OBJS		= $(SRCS:.c=.o)
TARGET		= $(OUTPUT_DIR)/exercise-04

LIB_NAME	= libfunctions.a
LIB_TARGET	= $(OUTPUT_DIR)/$(LIB_NAME)
LIB_SRC		= functions.c
LIB_OBJ		= $(LIB_SRC:.c=.o)

TEST_SRCS	= test.c functions.c
TEST_OBJS	= $(TEST_SRCS:.c=.o)
TEST_TARGET = $(OUTPUT_DIR)/exercise-04_test

all: $(TARGET) test

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(LIB_OBJ): $(LIB_SRC)
	# 在这里指定如何编译 functions.o
	$(CC) $(CFLAGS) -c -o $@ $<


$(LIB_TARGET): $(LIB_OBJ)
	# 在这里指定如何生成静态链接库
	# ar rcs $@ $^ 是用来创建静态库的命令，其中：
	# ar 是创建、修改和提取从静态库（归档文件）中的文件的工具。
	# r 标志表示插入文件或替换文件到归档文件中。
	# c 标志表示创建新的归档文件。
	# s 标志表示索引归档文件，以便更快地访问（添加符号表）。
	# $@ 和 $^ 是Makefile中的自动化变量：
	# $@ 表示规则的目标，即生成的文件名。
	# $^ 表示所有的依赖文件列表。
	# 具体来说，ar rcs $@ $^ 命令将依赖文件（对象文件）打包成一个静态库文件。
	ar rcs $@ $^

$(TARGET): $(OBJS) $(LIB_TARGET)
	# 在这里指定如何链接 libfunctions.a 来生成 TARGET
	$(CC) $(LDFLAGS) -o $@ $^ -L$(OUTPUT_DIR) -lfunctions

$(TEST_TARGET): $(TEST_OBJS) $(LIB_TARGET)
	# 在这里指定如何链接 libfunctions.a 来生成 TEST_TARGET
	$(CC) $(LDFLAGS) -o $@ $^ -L$(OUTPUT_DIR) -lfunctions

%.o: %.c
	# 在这里指定所有 C 文件的编译命令
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(TEST_TARGET)
	$(TEST_TARGET)

clean:
	rm -f $(LIB_TARGET) $(TARGET) $(TEST_TARGET) $(OBJS) $(LIB_OBJ) $(TEST_OBJS)
