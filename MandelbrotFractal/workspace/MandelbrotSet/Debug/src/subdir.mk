################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Screen.cpp \
../src/mandel.cpp \
../src/save_image.cpp \
../src/utils.cpp 

OBJS += \
./src/Screen.o \
./src/mandel.o \
./src/save_image.o \
./src/utils.o 

CPP_DEPS += \
./src/Screen.d \
./src/mandel.d \
./src/save_image.d \
./src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/local/include/SDL2 -I/opt/local/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

