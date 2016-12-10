################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bitmap.cpp \
../src/FractalGenerator.cpp \
../src/Mandelbrot.cpp \
../src/RGB.cpp \
../src/Screen.cpp \
../src/ZoomList.cpp \
../src/main.cpp 

OBJS += \
./src/Bitmap.o \
./src/FractalGenerator.o \
./src/Mandelbrot.o \
./src/RGB.o \
./src/Screen.o \
./src/ZoomList.o \
./src/main.o 

CPP_DEPS += \
./src/Bitmap.d \
./src/FractalGenerator.d \
./src/Mandelbrot.d \
./src/RGB.d \
./src/Screen.d \
./src/ZoomList.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/local/include/SDL2 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


