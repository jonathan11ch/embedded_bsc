#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/StartupProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/StartupProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MemMang/heap_4.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/port.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/portasm_dsPIC.S /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/croutine.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/event_groups.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/list.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/queue.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/stream_buffer.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/tasks.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/timers.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/640507261/heap_4.o ${OBJECTDIR}/_ext/2031935396/port.o ${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o ${OBJECTDIR}/_ext/2074250202/croutine.o ${OBJECTDIR}/_ext/2074250202/event_groups.o ${OBJECTDIR}/_ext/2074250202/list.o ${OBJECTDIR}/_ext/2074250202/queue.o ${OBJECTDIR}/_ext/2074250202/stream_buffer.o ${OBJECTDIR}/_ext/2074250202/tasks.o ${OBJECTDIR}/_ext/2074250202/timers.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/_ext/640507261/heap_4.o.d ${OBJECTDIR}/_ext/2031935396/port.o.d ${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o.d ${OBJECTDIR}/_ext/2074250202/croutine.o.d ${OBJECTDIR}/_ext/2074250202/event_groups.o.d ${OBJECTDIR}/_ext/2074250202/list.o.d ${OBJECTDIR}/_ext/2074250202/queue.o.d ${OBJECTDIR}/_ext/2074250202/stream_buffer.o.d ${OBJECTDIR}/_ext/2074250202/tasks.o.d ${OBJECTDIR}/_ext/2074250202/timers.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/640507261/heap_4.o ${OBJECTDIR}/_ext/2031935396/port.o ${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o ${OBJECTDIR}/_ext/2074250202/croutine.o ${OBJECTDIR}/_ext/2074250202/event_groups.o ${OBJECTDIR}/_ext/2074250202/list.o ${OBJECTDIR}/_ext/2074250202/queue.o ${OBJECTDIR}/_ext/2074250202/stream_buffer.o ${OBJECTDIR}/_ext/2074250202/tasks.o ${OBJECTDIR}/_ext/2074250202/timers.o

# Source Files
SOURCEFILES=main.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MemMang/heap_4.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/port.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/portasm_dsPIC.S /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/croutine.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/event_groups.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/list.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/queue.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/stream_buffer.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/tasks.c /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/timers.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/StartupProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128MC802
MP_LINKER_FILE_OPTION=,--script="/../home/jonathan/MPLABXProjects/StartupProject.X/p33FJ128MC802.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/dbc73e8bc33854c95b1b8d43c0a0f1b40fe1b9b0 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/640507261/heap_4.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MemMang/heap_4.c  .generated_files/flags/default/766163af71a0604c2c2f191c7f21c1914a3b2e35 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/640507261" 
	@${RM} ${OBJECTDIR}/_ext/640507261/heap_4.o.d 
	@${RM} ${OBJECTDIR}/_ext/640507261/heap_4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MemMang/heap_4.c  -o ${OBJECTDIR}/_ext/640507261/heap_4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/640507261/heap_4.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2031935396/port.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/port.c  .generated_files/flags/default/b6034645facb500fca6844cae7c2ec52f262d162 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2031935396" 
	@${RM} ${OBJECTDIR}/_ext/2031935396/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/2031935396/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/port.c  -o ${OBJECTDIR}/_ext/2031935396/port.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2031935396/port.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/croutine.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/croutine.c  .generated_files/flags/default/5402af124ffd2a48974d1d0ea779c2e4ec3afad5 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/croutine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/croutine.c  -o ${OBJECTDIR}/_ext/2074250202/croutine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/croutine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/event_groups.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/event_groups.c  .generated_files/flags/default/16555a22aa2102ef650097a2bc40b55e4b398b6 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/event_groups.c  -o ${OBJECTDIR}/_ext/2074250202/event_groups.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/event_groups.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/list.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/list.c  .generated_files/flags/default/97629b7386e2c06d860dce0a20bc4e4316ef2109 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/list.c  -o ${OBJECTDIR}/_ext/2074250202/list.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/list.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/queue.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/queue.c  .generated_files/flags/default/c5505b902eb6c920d2d5a33df5d883d6a0063571 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/queue.c  -o ${OBJECTDIR}/_ext/2074250202/queue.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/queue.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/stream_buffer.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/stream_buffer.c  .generated_files/flags/default/43b76cb020c27e2f8889afb5ca8fb989d6a8da9c .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/stream_buffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/stream_buffer.c  -o ${OBJECTDIR}/_ext/2074250202/stream_buffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/stream_buffer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/tasks.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/tasks.c  .generated_files/flags/default/4b66cfc46ea6eca5b1b5cf46bbf9fd53ff3a19bc .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/tasks.c  -o ${OBJECTDIR}/_ext/2074250202/tasks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/tasks.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/timers.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/timers.c  .generated_files/flags/default/7f9411f3ad8db712e2947989bef6aa15a1461b03 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/timers.c  -o ${OBJECTDIR}/_ext/2074250202/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/timers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/840cd89ce26fb25e2fb9622153d433bfbd43d727 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/640507261/heap_4.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MemMang/heap_4.c  .generated_files/flags/default/fdb2c58ade95fd6ea5ea9091aafd8e3e7c1dabeb .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/640507261" 
	@${RM} ${OBJECTDIR}/_ext/640507261/heap_4.o.d 
	@${RM} ${OBJECTDIR}/_ext/640507261/heap_4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MemMang/heap_4.c  -o ${OBJECTDIR}/_ext/640507261/heap_4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/640507261/heap_4.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2031935396/port.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/port.c  .generated_files/flags/default/cd1e0b0a20aedf098b8dc93912a9b594093b47b2 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2031935396" 
	@${RM} ${OBJECTDIR}/_ext/2031935396/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/2031935396/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/port.c  -o ${OBJECTDIR}/_ext/2031935396/port.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2031935396/port.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/croutine.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/croutine.c  .generated_files/flags/default/f55727eb73d430254917dc8d78003d11ec85e4cc .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/croutine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/croutine.c  -o ${OBJECTDIR}/_ext/2074250202/croutine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/croutine.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/event_groups.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/event_groups.c  .generated_files/flags/default/a0d39774b1a5d723f3081c429b0efd7501382a46 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/event_groups.c  -o ${OBJECTDIR}/_ext/2074250202/event_groups.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/event_groups.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/list.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/list.c  .generated_files/flags/default/eb91fe780e3a1a45cb9e627f72c2ebd39abed6c1 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/list.c  -o ${OBJECTDIR}/_ext/2074250202/list.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/list.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/queue.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/queue.c  .generated_files/flags/default/11d322a657e4fed2ea4268db990db716ec4ece39 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/queue.c  -o ${OBJECTDIR}/_ext/2074250202/queue.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/queue.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/stream_buffer.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/stream_buffer.c  .generated_files/flags/default/549f2a6b7cb2e0914e81175eac3898440e422686 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/stream_buffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/stream_buffer.c  -o ${OBJECTDIR}/_ext/2074250202/stream_buffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/stream_buffer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/tasks.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/tasks.c  .generated_files/flags/default/d0dfa62b3fbd3e5a3f72392628886c921d572012 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/tasks.c  -o ${OBJECTDIR}/_ext/2074250202/tasks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/tasks.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2074250202/timers.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/timers.c  .generated_files/flags/default/2c302b8c94699ffae24402a13279fb60baa3385b .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2074250202" 
	@${RM} ${OBJECTDIR}/_ext/2074250202/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074250202/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/timers.c  -o ${OBJECTDIR}/_ext/2074250202/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2074250202/timers.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/portasm_dsPIC.S  .generated_files/flags/default/5b3b51d96629653e2c23f338375221a65602f760 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2031935396" 
	@${RM} ${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/portasm_dsPIC.S  -o ${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -Wa,-MD,"${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o: /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/portasm_dsPIC.S  .generated_files/flags/default/edd651bd6cf0aad1279d91e02d0215eda59c9ebd .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/2031935396" 
	@${RM} ${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /../home/jonathan/MPLABXProjects/StartupProject.X/FreeRTOS/portable/MPLAB/PIC24_dsPIC/portasm_dsPIC.S  -o ${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o.d"  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -Wa,-MD,"${OBJECTDIR}/_ext/2031935396/portasm_dsPIC.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/StartupProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    /../home/jonathan/MPLABXProjects/StartupProject.X/p33FJ128MC802.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/StartupProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X"     -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/StartupProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   /../home/jonathan/MPLABXProjects/StartupProject.X/p33FJ128MC802.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/StartupProject.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/include" -I"/opt/FreeRTOSv202012.00/FreeRTOS/Source/portable/MPLAB/PIC24_dsPIC" -I"/home/jonathan/MPLABXProjects/StartupProject.X" -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/StartupProject.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
