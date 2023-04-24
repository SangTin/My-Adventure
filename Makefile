SHELL := pwsh.exe

TARGET = MyAdventure

CC = g++
CFLAGS = -std=c++20 -Wall -pedantic -MMD -MP

OUTDIR = .
DATADIR = ./data
SUBDIR = semihost stream arg_parser
DIR_OBJ = ./obj
DIR_SRC = ./obj

SDL2_PATH = D:/Tools/libraries/SDL2/x86_64-w64-mingw32

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

INCS = 
SRC = $(call rwildcard,src,*.cpp)
#NODIR_SRC = $(notdir $(SRC))
OBJS = $(addprefix $(DIR_OBJ)/, $(SRC:cpp=o)) # obj/xxx.o obj/folder/xxx .o
INC_DIRS = -Ilibraries -I$(SDL2_PATH)/include -Iheader

LIBS = 
LIB_DIRS = 
#* SDL flags
LIB_DIRS += -L$(SDL2_PATH)/lib
LIBS     += -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lstdc++fs 


#* GLM flags
.PHONY: all 
all: compile run

.PHONY: compile
compile: $(TARGET) 


.PHONY: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $(OUTDIR)/$@ $(OBJS) $(LIB_DIRS) $(LIBS)

DEPS=$(OBJS:.o=.d)
-include $(DEPS)

$(DIR_OBJ)/%.o: %.cpp 
	powershell mkdir -Force $(subst /,\,$(@D))
	$(CC) -o $@ $(CFLAGS) -c $< $(INC_DIRS)
	@echo "$(patsubst %.o,%.d,$@)"



.PHONY: clean
clean:
	powershell rm -r -Force $(subst /,\,$(DIR_OBJ))\src

.PHONY: echo
echo:
	@echo "INC files: $(INCS)"
	@echo "SRC files: $(SRC)"
	@echo "OBJ files: $(OBJS)"
	@echo "LIB files: $(LIBS)"
	@echo "INC DIR: $(INC_DIRS)"
	@echo "LIB DIR: $(LIB_DIRS)"
	@echo "DEP files: $(DEPS)"

.PHONY: run
run: 
	$(OUTDIR)/$(TARGET)