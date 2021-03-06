/*******************************************************************************
* File Name: cyfittergnu.inc
* 
* PSoC Creator  4.1 Update 1
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2017 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu_trm.inc"

/* Board_LED */
.set Board_LED__0__DM__MASK, 0x1C0
.set Board_LED__0__DM__SHIFT, 6
.set Board_LED__0__DR, CYREG_PRT0_DR
.set Board_LED__0__HSIOM, CYREG_HSIOM_PORT_SEL0
.set Board_LED__0__HSIOM_MASK, 0x00000F00
.set Board_LED__0__HSIOM_SHIFT, 8
.set Board_LED__0__INTCFG, CYREG_PRT0_INTCFG
.set Board_LED__0__INTSTAT, CYREG_PRT0_INTSTAT
.set Board_LED__0__MASK, 0x04
.set Board_LED__0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set Board_LED__0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set Board_LED__0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set Board_LED__0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set Board_LED__0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set Board_LED__0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set Board_LED__0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set Board_LED__0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set Board_LED__0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set Board_LED__0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set Board_LED__0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set Board_LED__0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set Board_LED__0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set Board_LED__0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set Board_LED__0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set Board_LED__0__PC, CYREG_PRT0_PC
.set Board_LED__0__PC2, CYREG_PRT0_PC2
.set Board_LED__0__PORT, 0
.set Board_LED__0__PS, CYREG_PRT0_PS
.set Board_LED__0__SHIFT, 2
.set Board_LED__DR, CYREG_PRT0_DR
.set Board_LED__INTCFG, CYREG_PRT0_INTCFG
.set Board_LED__INTSTAT, CYREG_PRT0_INTSTAT
.set Board_LED__MASK, 0x04
.set Board_LED__PA__CFG0, CYREG_UDB_PA0_CFG0
.set Board_LED__PA__CFG1, CYREG_UDB_PA0_CFG1
.set Board_LED__PA__CFG10, CYREG_UDB_PA0_CFG10
.set Board_LED__PA__CFG11, CYREG_UDB_PA0_CFG11
.set Board_LED__PA__CFG12, CYREG_UDB_PA0_CFG12
.set Board_LED__PA__CFG13, CYREG_UDB_PA0_CFG13
.set Board_LED__PA__CFG14, CYREG_UDB_PA0_CFG14
.set Board_LED__PA__CFG2, CYREG_UDB_PA0_CFG2
.set Board_LED__PA__CFG3, CYREG_UDB_PA0_CFG3
.set Board_LED__PA__CFG4, CYREG_UDB_PA0_CFG4
.set Board_LED__PA__CFG5, CYREG_UDB_PA0_CFG5
.set Board_LED__PA__CFG6, CYREG_UDB_PA0_CFG6
.set Board_LED__PA__CFG7, CYREG_UDB_PA0_CFG7
.set Board_LED__PA__CFG8, CYREG_UDB_PA0_CFG8
.set Board_LED__PA__CFG9, CYREG_UDB_PA0_CFG9
.set Board_LED__PC, CYREG_PRT0_PC
.set Board_LED__PC2, CYREG_PRT0_PC2
.set Board_LED__PORT, 0
.set Board_LED__PS, CYREG_PRT0_PS
.set Board_LED__SHIFT, 2

/* Button */
.set Button__0__DM__MASK, 0xE00000
.set Button__0__DM__SHIFT, 21
.set Button__0__DR, CYREG_PRT0_DR
.set Button__0__HSIOM, CYREG_HSIOM_PORT_SEL0
.set Button__0__HSIOM_MASK, 0xF0000000
.set Button__0__HSIOM_SHIFT, 28
.set Button__0__INTCFG, CYREG_PRT0_INTCFG
.set Button__0__INTSTAT, CYREG_PRT0_INTSTAT
.set Button__0__MASK, 0x80
.set Button__0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set Button__0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set Button__0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set Button__0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set Button__0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set Button__0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set Button__0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set Button__0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set Button__0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set Button__0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set Button__0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set Button__0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set Button__0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set Button__0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set Button__0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set Button__0__PC, CYREG_PRT0_PC
.set Button__0__PC2, CYREG_PRT0_PC2
.set Button__0__PORT, 0
.set Button__0__PS, CYREG_PRT0_PS
.set Button__0__SHIFT, 7
.set Button__DR, CYREG_PRT0_DR
.set Button__INTCFG, CYREG_PRT0_INTCFG
.set Button__INTSTAT, CYREG_PRT0_INTSTAT
.set Button__MASK, 0x80
.set Button__PA__CFG0, CYREG_UDB_PA0_CFG0
.set Button__PA__CFG1, CYREG_UDB_PA0_CFG1
.set Button__PA__CFG10, CYREG_UDB_PA0_CFG10
.set Button__PA__CFG11, CYREG_UDB_PA0_CFG11
.set Button__PA__CFG12, CYREG_UDB_PA0_CFG12
.set Button__PA__CFG13, CYREG_UDB_PA0_CFG13
.set Button__PA__CFG14, CYREG_UDB_PA0_CFG14
.set Button__PA__CFG2, CYREG_UDB_PA0_CFG2
.set Button__PA__CFG3, CYREG_UDB_PA0_CFG3
.set Button__PA__CFG4, CYREG_UDB_PA0_CFG4
.set Button__PA__CFG5, CYREG_UDB_PA0_CFG5
.set Button__PA__CFG6, CYREG_UDB_PA0_CFG6
.set Button__PA__CFG7, CYREG_UDB_PA0_CFG7
.set Button__PA__CFG8, CYREG_UDB_PA0_CFG8
.set Button__PA__CFG9, CYREG_UDB_PA0_CFG9
.set Button__PC, CYREG_PRT0_PC
.set Button__PC2, CYREG_PRT0_PC2
.set Button__PORT, 0
.set Button__PS, CYREG_PRT0_PS
.set Button__SHIFT, 7

/* S0 */
.set S0__0__DM__MASK, 0x7000
.set S0__0__DM__SHIFT, 12
.set S0__0__DR, CYREG_PRT0_DR
.set S0__0__HSIOM, CYREG_HSIOM_PORT_SEL0
.set S0__0__HSIOM_MASK, 0x000F0000
.set S0__0__HSIOM_SHIFT, 16
.set S0__0__INTCFG, CYREG_PRT0_INTCFG
.set S0__0__INTSTAT, CYREG_PRT0_INTSTAT
.set S0__0__MASK, 0x10
.set S0__0__OUT_SEL, CYREG_UDB_PA0_CFG10
.set S0__0__OUT_SEL_SHIFT, 8
.set S0__0__OUT_SEL_VAL, 3
.set S0__0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set S0__0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set S0__0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set S0__0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set S0__0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set S0__0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set S0__0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set S0__0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set S0__0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set S0__0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set S0__0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set S0__0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set S0__0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set S0__0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set S0__0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set S0__0__PC, CYREG_PRT0_PC
.set S0__0__PC2, CYREG_PRT0_PC2
.set S0__0__PORT, 0
.set S0__0__PS, CYREG_PRT0_PS
.set S0__0__SHIFT, 4
.set S0__DR, CYREG_PRT0_DR
.set S0__INTCFG, CYREG_PRT0_INTCFG
.set S0__INTSTAT, CYREG_PRT0_INTSTAT
.set S0__MASK, 0x10
.set S0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set S0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set S0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set S0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set S0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set S0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set S0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set S0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set S0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set S0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set S0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set S0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set S0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set S0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set S0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set S0__PC, CYREG_PRT0_PC
.set S0__PC2, CYREG_PRT0_PC2
.set S0__PORT, 0
.set S0__PS, CYREG_PRT0_PS
.set S0__SHIFT, 4

/* StripLights_B_WS2811 */
.set StripLights_B_WS2811_ctrl__0__MASK, 0x01
.set StripLights_B_WS2811_ctrl__0__POS, 0
.set StripLights_B_WS2811_ctrl__16BIT_CONTROL_AUX_CTL_REG, CYREG_UDB_W16_ACTL_02
.set StripLights_B_WS2811_ctrl__16BIT_CONTROL_CONTROL_REG, CYREG_UDB_W16_CTL_02
.set StripLights_B_WS2811_ctrl__16BIT_CONTROL_COUNT_REG, CYREG_UDB_W16_CTL_02
.set StripLights_B_WS2811_ctrl__16BIT_COUNT_CONTROL_REG, CYREG_UDB_W16_CTL_02
.set StripLights_B_WS2811_ctrl__16BIT_COUNT_COUNT_REG, CYREG_UDB_W16_CTL_02
.set StripLights_B_WS2811_ctrl__16BIT_MASK_MASK_REG, CYREG_UDB_W16_MSK_02
.set StripLights_B_WS2811_ctrl__16BIT_MASK_PERIOD_REG, CYREG_UDB_W16_MSK_02
.set StripLights_B_WS2811_ctrl__16BIT_PERIOD_MASK_REG, CYREG_UDB_W16_MSK_02
.set StripLights_B_WS2811_ctrl__16BIT_PERIOD_PERIOD_REG, CYREG_UDB_W16_MSK_02
.set StripLights_B_WS2811_ctrl__3__MASK, 0x08
.set StripLights_B_WS2811_ctrl__3__POS, 3
.set StripLights_B_WS2811_ctrl__4__MASK, 0x10
.set StripLights_B_WS2811_ctrl__4__POS, 4
.set StripLights_B_WS2811_ctrl__5__MASK, 0x20
.set StripLights_B_WS2811_ctrl__5__POS, 5
.set StripLights_B_WS2811_ctrl__CONTROL_AUX_CTL_REG, CYREG_UDB_W8_ACTL_02
.set StripLights_B_WS2811_ctrl__CONTROL_REG, CYREG_UDB_W8_CTL_02
.set StripLights_B_WS2811_ctrl__CONTROL_ST_REG, CYREG_UDB_CAT16_CTL_ST_02
.set StripLights_B_WS2811_ctrl__COUNT_REG, CYREG_UDB_W8_CTL_02
.set StripLights_B_WS2811_ctrl__COUNT_ST_REG, CYREG_UDB_CAT16_CTL_ST_02
.set StripLights_B_WS2811_ctrl__MASK, 0x39
.set StripLights_B_WS2811_ctrl__MASK_CTL_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK_02
.set StripLights_B_WS2811_ctrl__PER_CTL_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK_02
.set StripLights_B_WS2811_ctrl__PERIOD_REG, CYREG_UDB_W8_MSK_02
.set StripLights_B_WS2811_dshifter_u0__16BIT_A0_REG, CYREG_UDB_W16_A0_02
.set StripLights_B_WS2811_dshifter_u0__16BIT_A1_REG, CYREG_UDB_W16_A1_02
.set StripLights_B_WS2811_dshifter_u0__16BIT_D0_REG, CYREG_UDB_W16_D0_02
.set StripLights_B_WS2811_dshifter_u0__16BIT_D1_REG, CYREG_UDB_W16_D1_02
.set StripLights_B_WS2811_dshifter_u0__16BIT_DP_AUX_CTL_REG, CYREG_UDB_W16_ACTL_02
.set StripLights_B_WS2811_dshifter_u0__16BIT_F0_REG, CYREG_UDB_W16_F0_02
.set StripLights_B_WS2811_dshifter_u0__16BIT_F1_REG, CYREG_UDB_W16_F1_02
.set StripLights_B_WS2811_dshifter_u0__A0_A1_REG, CYREG_UDB_CAT16_A_02
.set StripLights_B_WS2811_dshifter_u0__A0_REG, CYREG_UDB_W8_A0_02
.set StripLights_B_WS2811_dshifter_u0__A1_REG, CYREG_UDB_W8_A1_02
.set StripLights_B_WS2811_dshifter_u0__D0_D1_REG, CYREG_UDB_CAT16_D_02
.set StripLights_B_WS2811_dshifter_u0__D0_REG, CYREG_UDB_W8_D0_02
.set StripLights_B_WS2811_dshifter_u0__D1_REG, CYREG_UDB_W8_D1_02
.set StripLights_B_WS2811_dshifter_u0__DP_AUX_CTL_REG, CYREG_UDB_W8_ACTL_02
.set StripLights_B_WS2811_dshifter_u0__F0_F1_REG, CYREG_UDB_CAT16_F_02
.set StripLights_B_WS2811_dshifter_u0__F0_REG, CYREG_UDB_W8_F0_02
.set StripLights_B_WS2811_dshifter_u0__F1_REG, CYREG_UDB_W8_F1_02
.set StripLights_B_WS2811_dshifter_u0__MSK_DP_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK_02
.set StripLights_B_WS2811_dshifter_u0__PER_DP_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK_02
.set StripLights_B_WS2811_pwm8_u0__16BIT_A0_REG, CYREG_UDB_W16_A0_01
.set StripLights_B_WS2811_pwm8_u0__16BIT_A1_REG, CYREG_UDB_W16_A1_01
.set StripLights_B_WS2811_pwm8_u0__16BIT_D0_REG, CYREG_UDB_W16_D0_01
.set StripLights_B_WS2811_pwm8_u0__16BIT_D1_REG, CYREG_UDB_W16_D1_01
.set StripLights_B_WS2811_pwm8_u0__16BIT_DP_AUX_CTL_REG, CYREG_UDB_W16_ACTL_01
.set StripLights_B_WS2811_pwm8_u0__16BIT_F0_REG, CYREG_UDB_W16_F0_01
.set StripLights_B_WS2811_pwm8_u0__16BIT_F1_REG, CYREG_UDB_W16_F1_01
.set StripLights_B_WS2811_pwm8_u0__A0_A1_REG, CYREG_UDB_CAT16_A_01
.set StripLights_B_WS2811_pwm8_u0__A0_REG, CYREG_UDB_W8_A0_01
.set StripLights_B_WS2811_pwm8_u0__A1_REG, CYREG_UDB_W8_A1_01
.set StripLights_B_WS2811_pwm8_u0__D0_D1_REG, CYREG_UDB_CAT16_D_01
.set StripLights_B_WS2811_pwm8_u0__D0_REG, CYREG_UDB_W8_D0_01
.set StripLights_B_WS2811_pwm8_u0__D1_REG, CYREG_UDB_W8_D1_01
.set StripLights_B_WS2811_pwm8_u0__DP_AUX_CTL_REG, CYREG_UDB_W8_ACTL_01
.set StripLights_B_WS2811_pwm8_u0__F0_F1_REG, CYREG_UDB_CAT16_F_01
.set StripLights_B_WS2811_pwm8_u0__F0_REG, CYREG_UDB_W8_F0_01
.set StripLights_B_WS2811_pwm8_u0__F1_REG, CYREG_UDB_W8_F1_01
.set StripLights_B_WS2811_StatusReg__0__MASK, 0x01
.set StripLights_B_WS2811_StatusReg__0__POS, 0
.set StripLights_B_WS2811_StatusReg__1__MASK, 0x02
.set StripLights_B_WS2811_StatusReg__1__POS, 1
.set StripLights_B_WS2811_StatusReg__16BIT_STATUS_AUX_CTL_REG, CYREG_UDB_W16_ACTL_02
.set StripLights_B_WS2811_StatusReg__16BIT_STATUS_REG, CYREG_UDB_W16_ST_02
.set StripLights_B_WS2811_StatusReg__6__MASK, 0x40
.set StripLights_B_WS2811_StatusReg__6__POS, 6
.set StripLights_B_WS2811_StatusReg__7__MASK, 0x80
.set StripLights_B_WS2811_StatusReg__7__POS, 7
.set StripLights_B_WS2811_StatusReg__MASK, 0xC3
.set StripLights_B_WS2811_StatusReg__MASK_REG, CYREG_UDB_W8_MSK_02
.set StripLights_B_WS2811_StatusReg__MASK_ST_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK_02
.set StripLights_B_WS2811_StatusReg__PER_ST_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK_02
.set StripLights_B_WS2811_StatusReg__STATUS_AUX_CTL_REG, CYREG_UDB_W8_ACTL_02
.set StripLights_B_WS2811_StatusReg__STATUS_CNT_REG, CYREG_UDB_CAT16_CTL_ST_02
.set StripLights_B_WS2811_StatusReg__STATUS_CONTROL_REG, CYREG_UDB_CAT16_CTL_ST_02
.set StripLights_B_WS2811_StatusReg__STATUS_REG, CYREG_UDB_W8_ST_02

/* StripLights_cisr */
.set StripLights_cisr__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set StripLights_cisr__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set StripLights_cisr__INTC_MASK, 0x01
.set StripLights_cisr__INTC_NUMBER, 0
.set StripLights_cisr__INTC_PRIOR_MASK, 0xC0
.set StripLights_cisr__INTC_PRIOR_NUM, 3
.set StripLights_cisr__INTC_PRIOR_REG, CYREG_CM0_IPR0
.set StripLights_cisr__INTC_SET_EN_REG, CYREG_CM0_ISER
.set StripLights_cisr__INTC_SET_PD_REG, CYREG_CM0_ISPR

/* StripLights_fisr */
.set StripLights_fisr__INTC_CLR_EN_REG, CYREG_CM0_ICER
.set StripLights_fisr__INTC_CLR_PD_REG, CYREG_CM0_ICPR
.set StripLights_fisr__INTC_MASK, 0x04
.set StripLights_fisr__INTC_NUMBER, 2
.set StripLights_fisr__INTC_PRIOR_MASK, 0xC00000
.set StripLights_fisr__INTC_PRIOR_NUM, 3
.set StripLights_fisr__INTC_PRIOR_REG, CYREG_CM0_IPR0
.set StripLights_fisr__INTC_SET_EN_REG, CYREG_CM0_ISER
.set StripLights_fisr__INTC_SET_PD_REG, CYREG_CM0_ISPR

/* Miscellaneous */
.set StripLights_HFCLK__DIVIDER_MASK, 0x0000FFFF
.set StripLights_HFCLK__ENABLE, CYREG_CLK_DIVIDER_A00
.set StripLights_HFCLK__ENABLE_MASK, 0x80000000
.set StripLights_HFCLK__MASK, 0x80000000
.set StripLights_HFCLK__REGISTER, CYREG_CLK_DIVIDER_A00
.set StripLights_StringSel_Sync_ctrl_reg__0__MASK, 0x01
.set StripLights_StringSel_Sync_ctrl_reg__0__POS, 0
.set StripLights_StringSel_Sync_ctrl_reg__1__MASK, 0x02
.set StripLights_StringSel_Sync_ctrl_reg__1__POS, 1
.set StripLights_StringSel_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG, CYREG_UDB_W16_ACTL_00
.set StripLights_StringSel_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG, CYREG_UDB_W16_CTL_00
.set StripLights_StringSel_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG, CYREG_UDB_W16_CTL_00
.set StripLights_StringSel_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG, CYREG_UDB_W16_CTL_00
.set StripLights_StringSel_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG, CYREG_UDB_W16_CTL_00
.set StripLights_StringSel_Sync_ctrl_reg__16BIT_MASK_MASK_REG, CYREG_UDB_W16_MSK_00
.set StripLights_StringSel_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG, CYREG_UDB_W16_MSK_00
.set StripLights_StringSel_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG, CYREG_UDB_W16_MSK_00
.set StripLights_StringSel_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG, CYREG_UDB_W16_MSK_00
.set StripLights_StringSel_Sync_ctrl_reg__2__MASK, 0x04
.set StripLights_StringSel_Sync_ctrl_reg__2__POS, 2
.set StripLights_StringSel_Sync_ctrl_reg__3__MASK, 0x08
.set StripLights_StringSel_Sync_ctrl_reg__3__POS, 3
.set StripLights_StringSel_Sync_ctrl_reg__32BIT_CONTROL_AUX_CTL_REG, CYREG_UDB_W32_ACTL_00
.set StripLights_StringSel_Sync_ctrl_reg__32BIT_CONTROL_REG, CYREG_UDB_W32_CTL_00
.set StripLights_StringSel_Sync_ctrl_reg__32BIT_COUNT_REG, CYREG_UDB_W32_CTL_00
.set StripLights_StringSel_Sync_ctrl_reg__32BIT_PERIOD_REG, CYREG_UDB_W32_MSK_00
.set StripLights_StringSel_Sync_ctrl_reg__CONTROL_AUX_CTL_REG, CYREG_UDB_W8_ACTL_00
.set StripLights_StringSel_Sync_ctrl_reg__CONTROL_REG, CYREG_UDB_W8_CTL_00
.set StripLights_StringSel_Sync_ctrl_reg__CONTROL_ST_REG, CYREG_UDB_CAT16_CTL_ST_00
.set StripLights_StringSel_Sync_ctrl_reg__COUNT_REG, CYREG_UDB_W8_CTL_00
.set StripLights_StringSel_Sync_ctrl_reg__COUNT_ST_REG, CYREG_UDB_CAT16_CTL_ST_00
.set StripLights_StringSel_Sync_ctrl_reg__MASK, 0x0F
.set StripLights_StringSel_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK_00
.set StripLights_StringSel_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK_00
.set StripLights_StringSel_Sync_ctrl_reg__PERIOD_REG, CYREG_UDB_W8_MSK_00
.set flex0__0__DM__MASK, 0x1C0000
.set flex0__0__DM__SHIFT, 18
.set flex0__0__DR, CYREG_PRT2_DR
.set flex0__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set flex0__0__HSIOM_MASK, 0x0F000000
.set flex0__0__HSIOM_SHIFT, 24
.set flex0__0__INTCFG, CYREG_PRT2_INTCFG
.set flex0__0__INTSTAT, CYREG_PRT2_INTSTAT
.set flex0__0__MASK, 0x40
.set flex0__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set flex0__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set flex0__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set flex0__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set flex0__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set flex0__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set flex0__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set flex0__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set flex0__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set flex0__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set flex0__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set flex0__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set flex0__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set flex0__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set flex0__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set flex0__0__PC, CYREG_PRT2_PC
.set flex0__0__PC2, CYREG_PRT2_PC2
.set flex0__0__PORT, 2
.set flex0__0__PS, CYREG_PRT2_PS
.set flex0__0__SHIFT, 6
.set flex0__DR, CYREG_PRT2_DR
.set flex0__INTCFG, CYREG_PRT2_INTCFG
.set flex0__INTSTAT, CYREG_PRT2_INTSTAT
.set flex0__MASK, 0x40
.set flex0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set flex0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set flex0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set flex0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set flex0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set flex0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set flex0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set flex0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set flex0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set flex0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set flex0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set flex0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set flex0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set flex0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set flex0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set flex0__PC, CYREG_PRT2_PC
.set flex0__PC2, CYREG_PRT2_PC2
.set flex0__PORT, 2
.set flex0__PS, CYREG_PRT2_PS
.set flex0__SHIFT, 6
.set flex1__0__DM__MASK, 0x1C0000
.set flex1__0__DM__SHIFT, 18
.set flex1__0__DR, CYREG_PRT3_DR
.set flex1__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set flex1__0__HSIOM_MASK, 0x0F000000
.set flex1__0__HSIOM_SHIFT, 24
.set flex1__0__INTCFG, CYREG_PRT3_INTCFG
.set flex1__0__INTSTAT, CYREG_PRT3_INTSTAT
.set flex1__0__MASK, 0x40
.set flex1__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set flex1__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set flex1__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set flex1__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set flex1__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set flex1__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set flex1__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set flex1__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set flex1__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set flex1__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set flex1__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set flex1__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set flex1__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set flex1__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set flex1__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set flex1__0__PC, CYREG_PRT3_PC
.set flex1__0__PC2, CYREG_PRT3_PC2
.set flex1__0__PORT, 3
.set flex1__0__PS, CYREG_PRT3_PS
.set flex1__0__SHIFT, 6
.set flex1__DR, CYREG_PRT3_DR
.set flex1__INTCFG, CYREG_PRT3_INTCFG
.set flex1__INTSTAT, CYREG_PRT3_INTSTAT
.set flex1__MASK, 0x40
.set flex1__PA__CFG0, CYREG_UDB_PA3_CFG0
.set flex1__PA__CFG1, CYREG_UDB_PA3_CFG1
.set flex1__PA__CFG10, CYREG_UDB_PA3_CFG10
.set flex1__PA__CFG11, CYREG_UDB_PA3_CFG11
.set flex1__PA__CFG12, CYREG_UDB_PA3_CFG12
.set flex1__PA__CFG13, CYREG_UDB_PA3_CFG13
.set flex1__PA__CFG14, CYREG_UDB_PA3_CFG14
.set flex1__PA__CFG2, CYREG_UDB_PA3_CFG2
.set flex1__PA__CFG3, CYREG_UDB_PA3_CFG3
.set flex1__PA__CFG4, CYREG_UDB_PA3_CFG4
.set flex1__PA__CFG5, CYREG_UDB_PA3_CFG5
.set flex1__PA__CFG6, CYREG_UDB_PA3_CFG6
.set flex1__PA__CFG7, CYREG_UDB_PA3_CFG7
.set flex1__PA__CFG8, CYREG_UDB_PA3_CFG8
.set flex1__PA__CFG9, CYREG_UDB_PA3_CFG9
.set flex1__PC, CYREG_PRT3_PC
.set flex1__PC2, CYREG_PRT3_PC2
.set flex1__PORT, 3
.set flex1__PS, CYREG_PRT3_PS
.set flex1__SHIFT, 6
.set flex2__0__DM__MASK, 0x7000
.set flex2__0__DM__SHIFT, 12
.set flex2__0__DR, CYREG_PRT3_DR
.set flex2__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set flex2__0__HSIOM_MASK, 0x000F0000
.set flex2__0__HSIOM_SHIFT, 16
.set flex2__0__INTCFG, CYREG_PRT3_INTCFG
.set flex2__0__INTSTAT, CYREG_PRT3_INTSTAT
.set flex2__0__MASK, 0x10
.set flex2__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set flex2__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set flex2__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set flex2__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set flex2__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set flex2__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set flex2__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set flex2__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set flex2__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set flex2__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set flex2__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set flex2__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set flex2__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set flex2__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set flex2__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set flex2__0__PC, CYREG_PRT3_PC
.set flex2__0__PC2, CYREG_PRT3_PC2
.set flex2__0__PORT, 3
.set flex2__0__PS, CYREG_PRT3_PS
.set flex2__0__SHIFT, 4
.set flex2__DR, CYREG_PRT3_DR
.set flex2__INTCFG, CYREG_PRT3_INTCFG
.set flex2__INTSTAT, CYREG_PRT3_INTSTAT
.set flex2__MASK, 0x10
.set flex2__PA__CFG0, CYREG_UDB_PA3_CFG0
.set flex2__PA__CFG1, CYREG_UDB_PA3_CFG1
.set flex2__PA__CFG10, CYREG_UDB_PA3_CFG10
.set flex2__PA__CFG11, CYREG_UDB_PA3_CFG11
.set flex2__PA__CFG12, CYREG_UDB_PA3_CFG12
.set flex2__PA__CFG13, CYREG_UDB_PA3_CFG13
.set flex2__PA__CFG14, CYREG_UDB_PA3_CFG14
.set flex2__PA__CFG2, CYREG_UDB_PA3_CFG2
.set flex2__PA__CFG3, CYREG_UDB_PA3_CFG3
.set flex2__PA__CFG4, CYREG_UDB_PA3_CFG4
.set flex2__PA__CFG5, CYREG_UDB_PA3_CFG5
.set flex2__PA__CFG6, CYREG_UDB_PA3_CFG6
.set flex2__PA__CFG7, CYREG_UDB_PA3_CFG7
.set flex2__PA__CFG8, CYREG_UDB_PA3_CFG8
.set flex2__PA__CFG9, CYREG_UDB_PA3_CFG9
.set flex2__PC, CYREG_PRT3_PC
.set flex2__PC2, CYREG_PRT3_PC2
.set flex2__PORT, 3
.set flex2__PS, CYREG_PRT3_PS
.set flex2__SHIFT, 4
.set flex3__0__DM__MASK, 0x07
.set flex3__0__DM__SHIFT, 0
.set flex3__0__DR, CYREG_PRT3_DR
.set flex3__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set flex3__0__HSIOM_MASK, 0x0000000F
.set flex3__0__HSIOM_SHIFT, 0
.set flex3__0__INTCFG, CYREG_PRT3_INTCFG
.set flex3__0__INTSTAT, CYREG_PRT3_INTSTAT
.set flex3__0__MASK, 0x01
.set flex3__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set flex3__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set flex3__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set flex3__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set flex3__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set flex3__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set flex3__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set flex3__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set flex3__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set flex3__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set flex3__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set flex3__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set flex3__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set flex3__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set flex3__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set flex3__0__PC, CYREG_PRT3_PC
.set flex3__0__PC2, CYREG_PRT3_PC2
.set flex3__0__PORT, 3
.set flex3__0__PS, CYREG_PRT3_PS
.set flex3__0__SHIFT, 0
.set flex3__DR, CYREG_PRT3_DR
.set flex3__INTCFG, CYREG_PRT3_INTCFG
.set flex3__INTSTAT, CYREG_PRT3_INTSTAT
.set flex3__MASK, 0x01
.set flex3__PA__CFG0, CYREG_UDB_PA3_CFG0
.set flex3__PA__CFG1, CYREG_UDB_PA3_CFG1
.set flex3__PA__CFG10, CYREG_UDB_PA3_CFG10
.set flex3__PA__CFG11, CYREG_UDB_PA3_CFG11
.set flex3__PA__CFG12, CYREG_UDB_PA3_CFG12
.set flex3__PA__CFG13, CYREG_UDB_PA3_CFG13
.set flex3__PA__CFG14, CYREG_UDB_PA3_CFG14
.set flex3__PA__CFG2, CYREG_UDB_PA3_CFG2
.set flex3__PA__CFG3, CYREG_UDB_PA3_CFG3
.set flex3__PA__CFG4, CYREG_UDB_PA3_CFG4
.set flex3__PA__CFG5, CYREG_UDB_PA3_CFG5
.set flex3__PA__CFG6, CYREG_UDB_PA3_CFG6
.set flex3__PA__CFG7, CYREG_UDB_PA3_CFG7
.set flex3__PA__CFG8, CYREG_UDB_PA3_CFG8
.set flex3__PA__CFG9, CYREG_UDB_PA3_CFG9
.set flex3__PC, CYREG_PRT3_PC
.set flex3__PC2, CYREG_PRT3_PC2
.set flex3__PORT, 3
.set flex3__PS, CYREG_PRT3_PS
.set flex3__SHIFT, 0
.set CYDEV_BCLK__HFCLK__HZ, 24000000
.set CYDEV_BCLK__HFCLK__KHZ, 24000
.set CYDEV_BCLK__HFCLK__MHZ, 24
.set CYDEV_BCLK__SYSCLK__HZ, 24000000
.set CYDEV_BCLK__SYSCLK__KHZ, 24000
.set CYDEV_BCLK__SYSCLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 16
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC4
.set CYDEV_CHIP_JTAG_ID, 0x04C81193
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 16
.set CYDEV_CHIP_MEMBER_4D, 12
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 17
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 15
.set CYDEV_CHIP_MEMBER_4I, 21
.set CYDEV_CHIP_MEMBER_4J, 13
.set CYDEV_CHIP_MEMBER_4K, 14
.set CYDEV_CHIP_MEMBER_4L, 20
.set CYDEV_CHIP_MEMBER_4M, 19
.set CYDEV_CHIP_MEMBER_4N, 9
.set CYDEV_CHIP_MEMBER_4O, 7
.set CYDEV_CHIP_MEMBER_4P, 18
.set CYDEV_CHIP_MEMBER_4Q, 11
.set CYDEV_CHIP_MEMBER_4R, 8
.set CYDEV_CHIP_MEMBER_4S, 10
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 22
.set CYDEV_CHIP_MEMBER_FM3, 26
.set CYDEV_CHIP_MEMBER_FM4, 27
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 23
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 24
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 25
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_4A
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 0
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_4A_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_READ_ACCELERATOR, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_Disallowed
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_PROTECT_KILL, 4
.set CYDEV_DEBUG_PROTECT_OPEN, 1
.set CYDEV_DEBUG_PROTECT, CYDEV_DEBUG_PROTECT_OPEN
.set CYDEV_DEBUG_PROTECT_PROTECTED, 2
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DFT_SELECT_CLK0, 1
.set CYDEV_DFT_SELECT_CLK1, 2
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_IMO_TRIMMED_BY_USB, 0
.set CYDEV_IMO_TRIMMED_BY_WCO, 0
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_STACK_SIZE, 0x0400
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 1
.set CYDEV_VDDA_MV, 3300
.set CYDEV_VDDD_MV, 3300
.set CYDEV_WDT_GENERATE_ISR, 1
.set CYIPBLOCK_M0S8_CTBM_VERSION, 0
.set CYIPBLOCK_m0s8cpuss_VERSION, 0
.set CYIPBLOCK_m0s8csd_VERSION, 0
.set CYIPBLOCK_m0s8gpio2_VERSION, 0
.set CYIPBLOCK_m0s8hsiom4a_VERSION, 0
.set CYIPBLOCK_m0s8lcd_VERSION, 0
.set CYIPBLOCK_m0s8lpcomp_VERSION, 0
.set CYIPBLOCK_m0s8pclk_VERSION, 0
.set CYIPBLOCK_m0s8sar_VERSION, 0
.set CYIPBLOCK_m0s8scb_VERSION, 0
.set CYIPBLOCK_m0s8srssv2_VERSION, 1
.set CYIPBLOCK_m0s8tcpwm_VERSION, 0
.set CYIPBLOCK_m0s8udbif_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 2
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
