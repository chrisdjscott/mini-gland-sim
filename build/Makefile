###########################################################################################
##
## target platforms: mahuika or iMac
##
## mahuika assumes:   CHECK VERSION???
##   ml gimkl/2017a
##   ml Eigen/3.3.4
##   ml SUNDIALS/4.0.0-gimkl-2017a
##
## notes 
##    source code formating: clang-format -i ./src/*
##    to execute on iMac: mpiexec -n 8 ./psim_coupled
##
###########################################################################################
## C++
CPP_DEFS = -std=c++17 -fopenmp 
CPP = gcc

###########################################################################################
## NOTE: uncomment block for ONE of debug, profile or optimised

## debug
#CPP_FLAGS =  $(CPP_DEFS) -m64 -Og -Wall -Wextra

## profile
#CPP_FLAGS =  $(CPP_DEFS) -m64 -O3 -pg 

## optimised
CPP_FLAGS =  $(CPP_DEFS) -m64 -O3 -march=native -mtune=native -Wall -Wpedantic -g
#CPP_FLAGS =  $(CPP_DEFS) -m64 -Og -Wextra -march=native -mtune=native -Wall -Wpedantic -g

###########################################################################################
## NOTE: uncomment lines for ONE platform
#CPP_INCLUDES = -I/usr/include  # mahuika 
#CPP_INCLUDES = -I/usr/local/include/eigen3 -I/usr/local/Cellar/boost/1.75.0_2/include -I/usr/local/Cellar/boost/1.75.0_2/lib # iMac

#CPP_LIBS = -lsundials_cvodes
#CPP_LIBS = -l/usr/local/Cellar/boost/1.75.0_2/lib  # iMac
#CPP_LIBS = -lboost_system
CPP_LIBS = -lstdc++

###########################################################################################

EXE = ../run/mini-gland-sim
OBJS = main.o utils.o cMiniGlandDuct.o cDuctSegment.o  cDuctSegmentAcinus.o cDuctSegmentIntercalated.o cDuctSegmentStriated.o cCell.o cCellAcinus.o cCellIntercalated.o cCellStriated.o
SRC = ./src

all: $(EXE)

main.o: $(SRC)/main.cpp $(SRC)/global_defs.hpp $(SRC)/cMiniGlandDuct.hpp
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

utils.o: $(SRC)/utils.cpp $(SRC)/utils.hpp $(SRC)/global_defs.hpp
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

cMiniGlandDuct.o: $(SRC)/cMiniGlandDuct.cpp $(SRC)/cMiniGlandDuct.hpp $(SRC)/utils.hpp $(SRC)/global_defs.hpp
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

cDuctSegment.o: $(SRC)/cDuctSegment.cpp $(SRC)/cDuctSegment.hpp $(SRC)/utils.hpp $(SRC)/global_defs.hpp
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

cDuctSegmentAcinus.o: $(SRC)/cDuctSegmentAcinus.cpp $(SRC)/cDuctSegment.hpp 
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

cDuctSegmentIntercalated.o: $(SRC)/cDuctSegmentIntercalated.cpp $(SRC)/cDuctSegment.hpp 
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

cDuctSegmentStriated.o: $(SRC)/cDuctSegmentStriated.cpp $(SRC)/cDuctSegmentStriated.hpp 
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

cCell.o: $(SRC)/cCell.cpp $(SRC)/cCell.hpp $(SRC)/utils.hpp $(SRC)/global_defs.hpp
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

cCellAcinus.o: $(SRC)/cCellAcinus.cpp $(SRC)/cCell.hpp 
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

cCellIntercalated.o: $(SRC)/cCellIntercalated.cpp $(SRC)/cCell.hpp 
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

cCellStriated.o: $(SRC)/cCellStriated.cpp $(SRC)/cCellStriated.hpp 
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<


#cLumen.o: $(SRC)/cLumen.cpp $(SRC)/cLumen.hpp $(SRC)/utils.hpp $(SRC)/global_defs.hpp 
#	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

#cLumenTree.o: $(SRC)/cLumenTree.cpp $(SRC)/cLumenTree.hpp
#	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

#cCVodes.o: $(SRC)/cCVodes.cpp $(SRC)/cCVodes.hpp
#	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

#cCell_flow.o: $(SRC)/cCell_flow.cpp $(SRC)/cCell_flow.hpp
#	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

#cCell_calcium.o: $(SRC)/cCell_calcium.cpp $(SRC)/cCell_calcium.hpp $(SRC)/cCellMesh.hpp $(SRC)/utils.hpp $(SRC)/global_defs.hpp
#	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

#cCellMesh.o: $(SRC)/cCellMesh.cpp $(SRC)/cCellMesh.hpp $(SRC)/cCell_calcium.hpp $(SRC)/utils.hpp $(SRC)/global_defs.hpp
#	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -o $@ -c $<

$(EXE): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(CPP_LIBS) -o $@ $+

clean:
	rm *.o
