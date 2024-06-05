CC ?= gcc

CFLAGS	?= -std=c11 -Wall -Wextra -Wpedantic -Werror -g
LDFLAGS ?= -Wl,--as-needed -Wl,--no-undefined

OUTPUT_DIR ?= .

SRCS	= main.c functions.c
OBJS	= $(SRCS:.c=.o)
TARGET	= $(OUTPUT_DIR)/exercise-01

all: $(TARGET)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(TARGET): $(OBJS)
	# 在这里指定 TARGET 的构建命令
	# $@：表示当前规则的目标文件
	# $^：表示当前规则的所有依赖文件
	# $(CC) $(LDFLAGS) -o $@ $^ 展开后等同于 gcc $(LDFLAGS) -o exercise-01 main.o functions.o
	$(CC) $(LDFLAGS) -o $@ $^


%.o: %.c
	# 在这里指定 C 文件的编译命令
	# $<：表示当前规则的第一个依赖文件（常用于编译源文件）。
	#  gcc $(CFLAGS) -c -o functions.o functions.c。
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f $(TARGET) $(OBJS)
