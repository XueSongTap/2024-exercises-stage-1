CC ?= gcc

CFLAGS	= -std=c11 -Wall -Wextra -Wpedantic -Werror -g
LDFLAGS = -Wl,--as-needed -Wl,--no-undefined # -fsanitize=address -fsanitize=undefined

OUTPUT_DIR ?= .

SRCS		= main.c
OBJS		= $(SRCS:.c=.o)
TARGET		= $(OUTPUT_DIR)/exercise-05

LIB_NAME	= libfunctions.so
LIB_TARGET	= $(OUTPUT_DIR)/$(LIB_NAME)
LIB_SRC		= functions.c
LIB_OBJ		= $(LIB_SRC:.c=.o)
RPATH		=  -Wl,-rpath,'$$ORIGIN'

TEST_SRCS	= test.c functions.c
TEST_OBJS	= $(TEST_SRCS:.c=.o)
TEST_TARGET = $(OUTPUT_DIR)/exercise-05_test

all: $(TARGET) test

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(LIB_OBJ): $(LIB_SRC)
	# 在这里指定如何编译 libfunctions.o

$(LIB_TARGET): $(LIB_OBJ)
	# 在这里指定如何生成 libfunctions.so

$(TARGET): $(OBJS) $(LIB_TARGET)
	# 在这里指定如何链接 libfunctions.so 来生成 TARGET

$(TEST_TARGET): $(TEST_OBJS) $(LIB_TARGET)
	# 在这里指定如何链接 libfunctions.so 来生成 TEST_TARGET

%.o: %.c
	# 在这里指定如何编译所有 C 文件

test: $(TEST_TARGET)
	$(TEST_TARGET)

clean:
	rm -f $(LIB_TARGET) $(TARGET) $(TEST_TARGET) $(OBJS) $(LIB_OBJ) $(TEST_OBJS)
