# Makefile to build queeg, quasi-elastic ed scattering event generator
#
# only supports linux os
#
# original author - Jeff Lachniet (2006)
# updated and options added - gpg (2014), gilfoyle@jlab.org

# paths to keep binaries and objects
PTH		= $(TOP_DIR)/bin
OPTH		= $(TOP_DIR)/obj

#libraries
ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS	:= $(ROOTGLIBS) -lMinuit $(shell root-config --libs)  -L/usr/lib64 -L/u/home/gleb/lib/LinuxRHFC8 -lpid -ltag -llac -lseb -lst -lclasutil -lsc -lc_bos_io -ldc -lec -lcc -ltrk -ldc -lc_bos_io -lsc -lmapmanager -lfputil -lfpack -lrecutl -lonline_dummy -lc_cern -lclasutil -lbos -lfpack -lbankdefs -L/u/home/gleb/cern/2005/lib -lpacklib -lkernlib -lnsl -lgfortran -lmathlib -lpacklib -lkernlib -lpawlib $(ROOTGLIBS)  -lEG
ROOTGLIBS	:= $(shell root-config --glibs)
ROOTINCLUDE  := -I$(shell root-config --incdir)

#includes
ROOTINCS        := $(shell root-config --incdir)
INCLUDES	:= -I$(TOP_DIR)/src/includes -I$(TOP_DIR)/src/CLAS6includes -I$(ROOTINCS)

#compiler and flags.  -Wall turns on warnings. -g and -ggdb are for debugging. 
CXX		= gcc -DBOS -O2 -Wno-write-strings -Wno-pragmas -I$(CLAS_BUILD)/packages/include -g -o $@ $^ -L/usr/lib64 -L/u/home/gleb/lib/LinuxRHFC8 -lpid -ltag -llac -lseb -lst -lclasutil -lsc -lc_bos_io -ldc -lec -lcc -ltrk -ldc -lc_bos_io -lsc -lmapmanager -lfputil -lfpack -lrecutl -lonline_dummy -lc_cern -lclasutil -lbos -lfpack -lbankdefs -L/u/home/gleb/cern/2005/lib -lpacklib -lkernlib -lnsl -lgfortran -lmathlib -lpacklib -lkernlib -lpawlib $(ROOTGLIBS)  -lEG
CXXFLAGS	= -Wall -g -ggdb

#linker and flags
LD		= gcc
LDFLAGS		= -Wall

#objects and dependencies
OBJS		= $(OPTH)/queeg.o $(OPTH)/Jqe_ana_calc.o $(OPTH)/vector3.o

#compile and link
NAME		= queeg
PROGRAM		= $(PTH)/$(NAME)

all:		obj exe

obj:
	@echo "Compiling $(OPTH)/queeg.o..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c queeg.cpp -o $(OPTH)/queeg.o

	@echo "Compiling $(OPTH)/Jqe_ana_calc.o..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Jqe_ana_calc.cpp -o $(OPTH)/Jqe_ana_calc.o

	@echo "Compiling $(OPTH)/vector3.o..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c vector3.c -o $(OPTH)/vector3.o

exe:
	@echo "Linking $(PROGRAM)..."
	@rm -f $(PROGRAM)
	-@mkdir -p $(PTH)

	$(LD) $(LDFLAGS) -o $(PROGRAM) $(OBJS) $(ROOTLIBS) 
	@echo "$(NAME) done"
	@echo "You should have an executable $(NAME) in directory $(PTH)"

clean:
	rm -f *.o
	rm -f *Dict.*
	rm -f G__*
	rm -f ../../obj/*.o 
	rm ../../bin/queeg
