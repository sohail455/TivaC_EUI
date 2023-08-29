################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
APP/Periodic_Test/%.obj: ../APP/Periodic_Test/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/EUI materials/Tiva C/Timers" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GE6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --check_misra="1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,-19.4,20" --preproc_with_compile --preproc_dependency="APP/Periodic_Test/$(basename $(<F)).d_raw" --obj_directory="APP/Periodic_Test" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


