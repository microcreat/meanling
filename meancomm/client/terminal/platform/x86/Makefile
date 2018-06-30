PRO_PATH ?=

CC:=$(CROSS_COMPILE)gcc
CPP:=$(CROSS_COMPILE)g++
AR:=$(CROSS_COMPILE)ar

target = client
csrc = terminal.c $(PRO_PATH)/3rdparty/cJSON/cJSON.c 
cobjs = $(csrc:.c=.o) 
	
.PHONY:all clean
all:$(target)
$(target):$(cobjs)
	$(CC) -o $@ $^

%.o:%.c  
	$(CC) -o $@ -c $< 	
	
clean:
	-rm -rf *.o $(target) *.d