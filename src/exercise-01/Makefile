CC ?= gcc

CFLAGS	?= -std=c11 -Wall -Wextra -Wpedantic -Werror -g
LDFLAGS ?= -Wl,--as-needed -Wl,--no-undefined -fsanitize=address -fsanitize=undefined

OUTPUT_DIR ?= .

SRCS	= main.c functions.c
OBJS	= $(SRCS:.c=.o)
TARGET	= $(OUTPUT_DIR)/exercise-01

all: $(TARGET)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(TARGET): $(OBJS)
	# 在这里指定 TARGET 的构建命令


%.o: %.c
	# 在这里指定 C 文件的编译命令

clean:
	rm -f $(TARGET) $(OBJS)
