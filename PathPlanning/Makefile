# Where are the source files
src_dir = src

# Where the object files go
obj_dir = obj

# The name of the executable file
elf_name = PathPlanner 

CC = g++
CFLAGS = -O0 -g
CPPFLAGS = -std=c++11

# Tell the directory to search for the library to use
LDFLAGS =  -I /usr/include/python2.7    
# Tell the lib name
LDLIBS =-lpython2.7#-lboost_program_options


# All the source files ended in '.c' in $(src_dir) directory
srcs := $(wildcard $(src_dir)/*.cpp)

# Get the corresponding object file of each source file
objs := $(patsubst $(src_dir)/%.cpp,$(obj_dir)/%.o,$(srcs))

# Get the dependency file of each source file
deps := $(patsubst $(src_dir)/%.cpp,$(obj_dir)/%.d,$(srcs))


all : $(obj_dir)/$(elf_name) 

$(obj_dir)/$(elf_name) : $(objs)
	$(CC) -o $@ $(objs) $(LDLIBS)  $(LDFLAGS) 
	@echo
	@echo $(elf_name) build success!
	@echo

$(obj_dir)/%.o : $(src_dir)/%.cpp | $(obj_dir)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<  $(LDLIBS)  $(LDFLAGS) 

$(obj_dir)/%.d : $(src_dir)/%.cpp | $(obj_dir)
	$(CC) -MM $(CFLAGS) $(CPPFLAGS) -MF $@ -MT $(@:.d=.o) $<  $(LDLIBS)  $(LDFLAGS)

-include $(deps)

$(obj_dir) :
	@echo 'Creating obj_dir ...'
	@mkdir $(obj_dir)
	@echo obj_dir created!

.PHONY: clean
clean : 
	@echo 'cleanning...'
	-rm -rf $(obj_dir)
	@echo "clean done!"


PREFIX = ./

.PHONY: install
install:$(obj_dir)/$(elf_name)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/$(elf_name)

.PHONY: uninstall
uninstall:
	rm -rf $(obj_dir)
	rm -f $(DESTDIR)$(PREFIX)/bin/$(elf_name)
	rm -rf $(DESTDIR)$(PREFIX)/bin

