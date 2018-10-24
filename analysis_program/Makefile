
CXX           = g++ -Wno-write-strings -Wno-pragmas
ObjSuf        = o
SrcSuf        = cxx
ExeSuf        =
DllSuf        = so

ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs)
ROOTGLIBS    := $(shell root-config --glibs)
ROOTINCLUDE  := -I$(shell root-config --incdir)



all:
	make Dictationarys
	make h10tot21

h10tot21: h10tot21.$(ObjSuf) MyMainFrame.$(ObjSuf) MyMainFrameDict.$(ObjSuf)  global.$(ObjSuf)  output.$(ObjSuf) cuts_data.$(ObjSuf) cuts_dataDict.$(ObjSuf)   cuts_sim.$(ObjSuf) cuts_simDict.$(ObjSuf) mom_corr.$(ObjSuf) mom_corrDict.$(ObjSuf)
	$(CXX) -g -o h10tot21 $^ $(ROOTGLIBS)

	
Dictationarys:
	rootcint -f MyMainFrameDict.cxx -c -I`root-config --incdir` MyMainFrame.h 
	rootcint -f mom_corrDict.cxx -c -I`root-config --incdir` mom_corr.h
	rootcint -f cuts_dataDict.cxx -c -I`root-config --incdir` cuts_data.h
	rootcint -f cuts_simDict.cxx -c -I`root-config --incdir` cuts_sim.h
	

%.$(ObjSuf): %.$(SrcSuf)
	$(CXX) -g -c $(ROOTINCLUDE) -c $<

clean:
	rm -f *.o
	rm -f *Dict.*
	rm -f *Dict_rdict*	
	rm -f G__*
	rm h10tot21
	

