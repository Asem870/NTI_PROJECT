################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AFIO_prog.c \
../Src/DC_motor.c \
../Src/GPIO_prog.c \
../Src/RCC_prog.c \
../Src/RUNNING_TASK.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/AFIO_prog.o \
./Src/DC_motor.o \
./Src/GPIO_prog.o \
./Src/RCC_prog.o \
./Src/RUNNING_TASK.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/AFIO_prog.d \
./Src/DC_motor.d \
./Src/GPIO_prog.d \
./Src/RCC_prog.d \
./Src/RUNNING_TASK.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/AFIO_prog.cyclo ./Src/AFIO_prog.d ./Src/AFIO_prog.o ./Src/AFIO_prog.su ./Src/DC_motor.cyclo ./Src/DC_motor.d ./Src/DC_motor.o ./Src/DC_motor.su ./Src/GPIO_prog.cyclo ./Src/GPIO_prog.d ./Src/GPIO_prog.o ./Src/GPIO_prog.su ./Src/RCC_prog.cyclo ./Src/RCC_prog.d ./Src/RCC_prog.o ./Src/RCC_prog.su ./Src/RUNNING_TASK.cyclo ./Src/RUNNING_TASK.d ./Src/RUNNING_TASK.o ./Src/RUNNING_TASK.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

