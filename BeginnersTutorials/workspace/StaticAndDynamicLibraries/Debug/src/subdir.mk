################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/StaticAndDynamicLibraries.cpp 

OBJS += \
./src/StaticAndDynamicLibraries.o 

CPP_DEPS += \
./src/StaticAndDynamicLibraries.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/GeorgeQuentin/Dev/Cpp/LearningCppFromCaveOfProgramming/BeginnersTutorials/workspace/animals/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


