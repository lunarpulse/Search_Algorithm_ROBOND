# Where are the source files
src_dir = src

# Where the object files go
obj_dir = obj

# The name of the executable file
elf_name = MKSK 

CC = g++
CFLAGS = -O0 -g
CPPFLAGS = -std=c++11

# Tell the directory to search for the library to use
LDFLAGS =     
# Tell the lib name
LDLIBS = #-lboost_program_options


# All the source files ended in '.c' in $(src_dir) directory
srcs := $(wildcard $(src_dir)/*.cpp)

# Get the corresponding object file of each source file
objs := $(patsubst $(src_dir)/%.cpp,$(obj_dir)/%.o,$(srcs))

# Get the dependency file of each source file
deps := $(patsubst $(src_dir)/%.cpp,$(obj_dir)/%.d,$(srcs))


all : $(obj_dir)/$(elf_name) 

$(obj_dir)/$(elf_name) : $(objs)
	$(CC) $(LDFLAGS) -o $@ $(objs) $(LDLIBS)
	@echo
	@echo $(elf_name) build success!
	@echo

$(obj_dir)/%.o : $(src_dir)/%.cpp | $(obj_dir)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

$(obj_dir)/%.d : $(src_dir)/%.cpp | $(obj_dir)
	$(CC) -MM $(CFLAGS) $(CPPFLAGS) -MF $@ -MT $(@:.d=.o) $<

-include $(deps)

$(obj_dir) :
	@echo 'Creating obj_dir ...'
	@mkdir $(obj_dir)
	@echo obj_dir created!

clean : 
	@echo 'cleanning...'
	-rm -rf $(obj_dir)
	@echo "clean done!"

.PHONY: all clean
