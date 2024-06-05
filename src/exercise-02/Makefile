CC ?= gcc

CFLAGS	?= -std=c11 -Wall -Wextra -Wpedantic -Werror -g
LDFLAGS ?= -Wl,--as-needed -Wl,--no-undefined

OUTPUT_DIR ?= .

SRCS		= main.c functions.c
OBJS		= $(SRCS:.c=.o)
TARGET		= $(OUTPUT_DIR)/exercise-02

TEST_SRCS	= test.c functions.c
TEST_OBJS	= $(TEST_SRCS:.c=.o)
TEST_TARGET = $(OUTPUT_DIR)/exercise-02_test

all: $(TARGET) test

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(TARGET): $(OBJS)
	# 在这里指定 TARGET 的构建命令
	$(CC) $(LDFLAGS) -o $@ $^


$(TEST_TARGET): $(TEST_OBJS)
	# 在这里指定 TEST_TARGET 的构建命令
	$(CC) $(LDFLAGS) -o $@ $^


%.o: %.c
	# 在这里指定所有 C 文件的编译命令
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(TEST_TARGET)
	$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJS) $(TEST_OBJS)
