CC ?= gcc

CFLAGS	= -std=c11 -Wall -Wextra -Wpedantic -Werror -g
LDFLAGS = -Wl,--as-needed -Wl,--no-undefined

OUTPUT_DIR ?= .

SRCS		= main.c
OBJS		= $(SRCS:.c=.o)
TARGET		= $(OUTPUT_DIR)/exercise-21

LIB_NAME	= libtask_queue.so
LIB_TARGET	= $(OUTPUT_DIR)/$(LIB_NAME)
LIB_SRC		= task_queue.c
LIB_OBJ		= $(LIB_SRC:.c=.o)
RPATH		=  -Wl,-rpath,'$$ORIGIN'

all: $(TARGET)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB_TARGET): $(LIB_OBJ)
	$(CC) -shared -o $@ $^

$(TARGET): $(OBJS) $(LIB_TARGET)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(OUTPUT_DIR) -ltask_queue $(RPATH)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(LIB_TARGET) $(TARGET) $(OBJS) $(LIB_OBJ)
