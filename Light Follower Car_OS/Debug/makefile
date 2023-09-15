################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./tm4c123gh6pm_startup_ccs.obj" \
"./APP/LDR_APP/LDR_APP.obj" \
"./HAL/Buttons/Buttons.obj" \
"./HAL/LCD/lcd.obj" \
"./HAL/LDR/LDR.obj" \
"./HAL/MOTORS/motors.obj" \
"./HAL/UltraSonic/Ultrasonic.obj" \
"./MCAL/ADC/ADC.obj" \
"./MCAL/GPIO/GPIO_Program.obj" \
"./MCAL/GPTM/Timer.obj" \
"./MCAL/RCC/RCC.obj" \
"./MCAL/SYSTICK/Gpt.obj" \
"./OS/Schedular.obj" \
"./Tasks/Tasks.obj" \
"../tm4c123gh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include APP/LDR_APP/subdir_vars.mk
-include HAL/Buttons/subdir_vars.mk
-include HAL/LCD/subdir_vars.mk
-include HAL/LDR/subdir_vars.mk
-include HAL/MOTORS/subdir_vars.mk
-include HAL/UltraSonic/subdir_vars.mk
-include MCAL/ADC/subdir_vars.mk
-include MCAL/GPIO/subdir_vars.mk
-include MCAL/GPTM/subdir_vars.mk
-include MCAL/RCC/subdir_vars.mk
-include MCAL/SYSTICK/subdir_vars.mk
-include OS/subdir_vars.mk
-include Tasks/subdir_vars.mk
-include subdir_rules.mk
-include APP/LDR_APP/subdir_rules.mk
-include HAL/Buttons/subdir_rules.mk
-include HAL/LCD/subdir_rules.mk
-include HAL/LDR/subdir_rules.mk
-include HAL/MOTORS/subdir_rules.mk
-include HAL/UltraSonic/subdir_rules.mk
-include MCAL/ADC/subdir_rules.mk
-include MCAL/GPIO/subdir_rules.mk
-include MCAL/GPTM/subdir_rules.mk
-include MCAL/RCC/subdir_rules.mk
-include MCAL/SYSTICK/subdir_rules.mk
-include OS/subdir_rules.mk
-include Tasks/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
New_Car_project.out \

EXE_OUTPUTS__QUOTED += \
"New_Car_project.out" \

BIN_OUTPUTS += \
New_Car_project.hex \

BIN_OUTPUTS__QUOTED += \
"New_Car_project.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "New_Car_project.out"

# Tool invocations
New_Car_project.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"New_Car_project.map" --heap_size=0 --stack_size=512 -i"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/lib" -i"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="New_Car_project_linkInfo.xml" --rom_model -o "New_Car_project.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

New_Car_project.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: Arm Hex Utility'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armhex" --diag_wrap=off -o "New_Car_project.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "tm4c123gh6pm_startup_ccs.obj" "APP\LDR_APP\LDR_APP.obj" "HAL\Buttons\Buttons.obj" "HAL\LCD\lcd.obj" "HAL\LDR\LDR.obj" "HAL\MOTORS\motors.obj" "HAL\UltraSonic\Ultrasonic.obj" "MCAL\ADC\ADC.obj" "MCAL\GPIO\GPIO_Program.obj" "MCAL\GPTM\Timer.obj" "MCAL\RCC\RCC.obj" "MCAL\SYSTICK\Gpt.obj" "OS\Schedular.obj" "Tasks\Tasks.obj" 
	-$(RM) "main.d" "tm4c123gh6pm_startup_ccs.d" "APP\LDR_APP\LDR_APP.d" "HAL\Buttons\Buttons.d" "HAL\LCD\lcd.d" "HAL\LDR\LDR.d" "HAL\MOTORS\motors.d" "HAL\UltraSonic\Ultrasonic.d" "MCAL\ADC\ADC.d" "MCAL\GPIO\GPIO_Program.d" "MCAL\GPTM\Timer.d" "MCAL\RCC\RCC.d" "MCAL\SYSTICK\Gpt.d" "OS\Schedular.d" "Tasks\Tasks.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

