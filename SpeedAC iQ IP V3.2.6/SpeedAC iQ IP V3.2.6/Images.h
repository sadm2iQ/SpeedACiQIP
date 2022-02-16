﻿#ifndef __images_h_
#define __images_h_

/****************************************************************************/
/*                                                                          */
/*    Directory of images used in indicator display                         */
/*                                                                          */
/****************************************************************************/

//#define SQUARE(x) ((x) * (x))
//int z = SQUARE (17); // int z = ((17) * (17));

#define DIRECTORY "appdata/"

#define BTN_INFO                concat(DIRECTORY, "BTN_INFO.png")
#define BTN_IO_STATUS           concat(DIRECTORY, "BTN_IO_TEST.png")
#define BTN_IO_STATUS_GRAYOUT   concat(DIRECTORY, "BTN_IO_TEST_GRAYOUT.png")
#define BTN_LOGO_PTC            concat(DIRECTORY, "MONOGRAMME_PT.png")

#define BTN_START               concat(DIRECTORY, "BTN_START.png")
#define BTN_CHECK               concat(DIRECTORY, "BTN_CHECK.png")
#define BTN_X                   concat(DIRECTORY, "BTN_X.png")
#define BTN_BLANK               concat(DIRECTORY, "BTN_BLANK.png")
#define BTN_PREV                concat(DIRECTORY, "BTN_PREV.png")
#define BTN_NEXT                concat(DIRECTORY, "BTN_NEXT.png")

#define BTN_AUTOTUNEON          concat(DIRECTORY, "BTN_AUTOTUNE_ON.png")
//#define BTN_AUTOTUNEDONE        concat(DIRECTORY, "BTN_AUTOTUNE_OFF.png")
#define BTN_AUTO                concat(DIRECTORY, "BTN_HOME.png")
#define BTN_ALARM               concat(DIRECTORY, "BTN_FAULT_RESET.png")
#define BTN_RECIPE              concat(DIRECTORY, "BTN_RECIPE.png")
#define BTN_RECIPE_GRAYOUT      concat(DIRECTORY, "BTN_RECIPE_GRAYOUT.png")
#define BTN_REPORT              concat(DIRECTORY, "BTN_REPORT.png")
#define BTN_BATCH               concat(DIRECTORY, "BTN_BATCH.png")
#define BTN_ACCESS              concat(DIRECTORY, "BTN_ACCESS.png")
#define BTN_OFF                 concat(DIRECTORY, "BTN_OFF.png")
#define BTN_STOP                concat(DIRECTORY, "BTN_STOP.png")
#define NO_FAULT                concat(DIRECTORY, "BTN_NO_FAULT.png")
#define STOPPING_FAULT          concat(DIRECTORY, "BTN_FAULT.png")
#define BLOCKING_FAULT          concat(DIRECTORY, "BTN_FAULT.png")
#define GENERAL_FAULT           concat(DIRECTORY, "BTN_FAULT.png")
#define WARNING_FAULT           concat(DIRECTORY, "BTN_WARNING.png")
#define OFF_MODE                concat(DIRECTORY, "OFF.png")
#define MAN_MODE                concat(DIRECTORY, "MANUAL.png")
#define STOPPING_MODE           concat(DIRECTORY, "STOPPING.png")
#define STOP_MODE               concat(DIRECTORY, "STOP.png")
#define PREP_MODE               concat(DIRECTORY, "PREP.png")
#define AUTO_MODE               concat(DIRECTORY, "AUTO.png")
#define BTN_LANGUAGE            concat(DIRECTORY, "BTN_LANGUAGE.png")
#define BTN_NIL_BLUE            concat(DIRECTORY, "BTN_NIL_BLUE.png") 
#define BTN_NIL_WHITE           concat(DIRECTORY, "BTN_NIL_WHITE.png")
#define BTN_NIL_GRAYOUT         concat(DIRECTORY, "BTN_NIL_GRAYOUT.png")

#define BTN_NAVIG               concat(DIRECTORY, "BTN_ECRANS.png")
#define HOPPER_FILL             concat(DIRECTORY, "HOPPER_FILL.png")  
#define HOPPER_EMPTY            concat(DIRECTORY, "HOPPER_EMPTY.png") 
#define BTN_SAVE                concat(DIRECTORY, "BTN_SAVE.png")
#define BTN_COPY                concat(DIRECTORY, "BTN_COPY.png")
#define BTN_COPY_GRAYOUT        concat(DIRECTORY, "BTN_COPY_GRAYOUT.png")
#define BTN_DEL                 concat(DIRECTORY, "BTN_TRASH.png")
#define BTN_FAULTS              concat(DIRECTORY, "BTN_FAULTS.png")
#define BTN_PRINT               concat(DIRECTORY, "BTN_PRINTER.png")
#define BTN_RENAME              concat(DIRECTORY, "BTN_RENAME.png")
#define BTN_INPUT               concat(DIRECTORY, "BTN_INPUT.png")
#define BTN_OUTPUT              concat(DIRECTORY, "BTN_OUTPUT.png")
#define BTN_IO_CONFIG           concat(DIRECTORY, "BTN_IO_CONFIG.png")
#define BTN_IO_CONFIG_GRAYOUT   concat(DIRECTORY, "BTN_IO_CONFIG_GRAYOUT.png")
#define BTN_MP                  concat(DIRECTORY, "BTN_TOOLS.png")
#define BTN_MP_GRAYOUT          concat(DIRECTORY, "BTN_TOOLS_GRAYOUT.png")
#define BTN_MC                  concat(DIRECTORY, "BTN_SETTINGS.png")
#define BTN_MC_GRAYOUT          concat(DIRECTORY, "BTN_SETTINGS_GRAYOUT.png")
#define BTN_SAVE2DFLT           concat(DIRECTORY, "BTN_SAVE2DFLT.png") 
#define BTN_RESTOREDFLT         concat(DIRECTORY, "BTN_RESTOREDFLT.png")
#define BTN_REPORTRESET         concat(DIRECTORY, "BTN_RESET_REPORT.png")
#define BTN_RESETLIFETIME       concat(DIRECTORY, "BTN_RESET_REPORT3.png")
#define BTN_TIMEDATE            concat(DIRECTORY, "BTN_CLOCK_DATE.png")
#define BTN_REFRESH             concat(DIRECTORY, "BTN_REFRESH.png")
#define BTN_FLEXIO              concat(DIRECTORY, "BTN_FLEX_IQ.png")
#define BTN_FLEXIO_GRAYOUT      concat(DIRECTORY, "BTN_FLEX_IQ_GRAYOUT.png")

#define BTN_FIRST_PAGE          concat(DIRECTORY, "BTN_FIRST_PAGE.png")
#define BTN_LAST_PAGE           concat(DIRECTORY, "BTN_LAST_PAGE.png")
#define BTN_PAGE_UP             concat(DIRECTORY, "BTN_PAGE_UP.png")
 #define BTN_PAGE_DOWN          concat(DIRECTORY, "BTN_PAGE_DOWN.png")

#define BTN_ACCESS_OK           concat(DIRECTORY, "BTN_ACCESS_OK.png")
#define BTN_NOACCESS            concat(DIRECTORY, "BTN_ACCESS_NO.png")

#define BTN_DISCH_MAN           concat(DIRECTORY, "BTN_DISCH_MAN.png")
#define BTN_DISCH_OVER          concat(DIRECTORY, "BTN_DISCH_OVER_RED.png")
#define BTN_DISCH_UNDER         concat(DIRECTORY, "BTN_DISCH_UNDER_YELLOW.png")
#define BTN_DISCH_PAN_OFF       concat(DIRECTORY, "BTN_DISCH_PAN_GRAYOUT.png")
#define BTN_DISCH_PAN_ON        concat(DIRECTORY, "BTN_DISCH_PAN_CANCEL.png")

#define BTN_RELWGT              concat(DIRECTORY, "BTN_RELWGT.png")
#define BTN_CHKWGT              concat(DIRECTORY, "BTN_CHKWGT.png")

// Widget Type ON/OFF Images
#define BTN_CHECKON             concat(DIRECTORY, "BTN_SLIDER_BLUE_45px_Large.png") 
#define BTN_CHECKOFF            concat(DIRECTORY, "BTN_SLIDER_GRAY_45px_Large.png") 
#define BTN_TESTON              concat(DIRECTORY, "BTN_SLIDER_GREEN_45px_Medium.png")
#define BTN_TESTOFF             concat(DIRECTORY, "BTN_SLIDER_RED_45px_Medium.png")
#define BTN_CHECKON_SMALL       concat(DIRECTORY, "BTN_SLIDER_BLUE_45px_Small.png")
#define BTN_CHECKOFF_SMALL      concat(DIRECTORY, "BTN_SLIDER_GRAY_45px_Small.png")

#define BTN_LOGO_iQ             concat(DIRECTORY, "LOGO_SpeedACiQ.png")

#define BTN_LOWLEVEL_MANRESET   concat(DIRECTORY, "BTN_LOWLEVEL_MANRESET.png")
#define BTN_LOWLEVEL_AUTORESET  concat(DIRECTORY, "BTN_LOWLEVEL_AUTORESET.png")
#define BTN_WEIGHING_DATA       concat(DIRECTORY, "BTN_WEIGHING_DATA.png") 

#define BTN_PAUSE               concat(DIRECTORY, "BTN_PAUSE.png") 
#define PAUSE_MODE              concat(DIRECTORY, "PAUSE.png") 
#define BTN_LOAD_DBS            concat(DIRECTORY, "BTN_LOAD_DBS.png") 
  

#endif // __images_h_
