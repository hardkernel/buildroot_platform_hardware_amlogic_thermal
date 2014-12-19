#
#Makefile for the thermal dirver
#
obj-$(CONFIG_AMLOGIC_THERMAL)+= aml_thermal.o

aml_thermal-objs =
aml_thermal-objs += amlogic_thermal.o 
aml_thermal-objs += amlogic_thermal_module.o



