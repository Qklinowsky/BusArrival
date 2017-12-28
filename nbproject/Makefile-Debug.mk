#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/BusRoute.o \
	${OBJECTDIR}/BusStop.o \
	${OBJECTDIR}/DataImporter.o \
	${OBJECTDIR}/RouteSegment.o \
	${OBJECTDIR}/TimeTable.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lboost_system -pthread -DBOOST_LOG_DYN_LINK
CXXFLAGS=-lboost_system -pthread -DBOOST_LOG_DYN_LINK

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/lib -L/usr/lib -lboost_atomic -lboost_atomic -lboost_chrono -lboost_chrono -lboost_context -lboost_context -lboost_coroutine -lboost_coroutine -lboost_date_time -lboost_date_time -lboost_exception -lboost_filesystem -lboost_filesystem -lboost_graph -lboost_graph -lboost_graph_parallel -lboost_graph_parallel -lboost_iostreams -lboost_iostreams -lboost_locale -lboost_locale -lboost_log -lboost_log -lboost_log_setup -lboost_log_setup -lboost_math_c99 -lboost_math_c99 -lboost_math_c99f -lboost_math_c99f -lboost_math_c99l -lboost_math_c99l -lboost_math_tr1 -lboost_math_tr1 -lboost_math_tr1f -lboost_math_tr1f -lboost_math_tr1l -lboost_math_tr1l -lboost_mpi -lboost_mpi -lboost_mpi_python-py27 -lboost_mpi_python-py27 -lboost_mpi_python-py35 -lboost_mpi_python-py35 -lboost_mpi_python -lboost_mpi_python -lboost_prg_exec_monitor -lboost_prg_exec_monitor -lboost_program_options -lboost_program_options -lboost_python-py27 -lboost_python-py27 -lboost_python-py35 -lboost_python-py35 -lboost_python -lboost_python -lboost_random -lboost_random -lboost_regex -lboost_regex -lboost_serialization -lboost_serialization -lboost_signals -lboost_signals -lboost_system -lboost_system -lboost_test_exec_monitor -lboost_thread -lboost_thread -lboost_timer -lboost_timer -lboost_unit_test_framework -lboost_unit_test_framework -lboost_wave -lboost_wave -lboost_wserialization -lboost_wserialization

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/busarrival

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/busarrival: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/busarrival ${OBJECTFILES} ${LDLIBSOPTIONS} -DBOOST_LOG_DYN_LINK

${OBJECTDIR}/BusRoute.o: BusRoute.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BusRoute.o BusRoute.cpp

${OBJECTDIR}/BusStop.o: BusStop.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BusStop.o BusStop.cpp

${OBJECTDIR}/DataImporter.o: DataImporter.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataImporter.o DataImporter.cpp

${OBJECTDIR}/RouteSegment.o: RouteSegment.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RouteSegment.o RouteSegment.cpp

${OBJECTDIR}/TimeTable.o: TimeTable.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TimeTable.o TimeTable.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
