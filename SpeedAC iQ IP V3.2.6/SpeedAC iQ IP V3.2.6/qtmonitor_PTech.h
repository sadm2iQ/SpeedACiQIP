﻿#ifndef __qtmonitor_h_
#define __qtmonitor_h_

/****************************************************************************/
/*                                                                          */
/* definition of constants used for the interaction with the qtmonitor      */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/* widget types                                                             */
/****************************************************************************/
enum
{
  WIDGET_TYPE_BUTTON,
  WIDGET_TYPE_TEXT_OUTPUT,
  WIDGET_TYPE_TEXT_INPUT,
  WIDGET_TYPE_LIST,
  WIDGET_TYPE_TABLE,
  WIDGET_TYPE_CHECKBOX,
  WIDGET_TYPE_COMBOBOX,
  WIDGET_TYPE_SKETCH,
  WIDGET_TYPE_STRETCH,
  WIDGET_TYPE_TEXT_INPUT_USER,
  WIDGET_TYPE_TAB,
  WIDGET_TYPE_ONOFF,
};

/****************************************************************************/
/* window types                                                             */
/****************************************************************************/
enum
{
  WINDOW_TYPE_DIALOG,
  WINDOW_TYPE_POPUP
};

/****************************************************************************/
/* layout types                                                             */
/****************************************************************************/
enum
{
  LAYOUT_TYPE_NONE,
  LAYOUT_TYPE_VBOX,
  LAYOUT_TYPE_HBOX,
  LAYOUT_TYPE_GRID,
};

/****************************************************************************/
/* layout options                                                           */
/****************************************************************************/
enum
{
  LAYOUT_OPTION_SPACING,
  LAYOUT_OPTION_CONTENT_MARGINS,
  LAYOUT_OPTION_COLUMN_MINIMUM_WIDTH,
  LAYOUT_OPTION_COLUMN_STRETCH,
  LAYOUT_OPTION_ROW_MINIMUM_HEIGHT,
  LAYOUT_OPTION_ROW_STRETCH,
};

/****************************************************************************/
/* size policies                                                            */
/****************************************************************************/
enum
{
  SIZE_POLICY_FIXED            = 0x00,
  SIZE_POLICY_MINIMUM          = 0x01,
  SIZE_POLICY_MAXIMUM          = 0x04,
  SIZE_POLICY_PREFERRED        = 0x05,
  SIZE_POLICY_EXPANDING        = 0x07,
  SIZE_POLICY_MINIMUMEXPANDING = 0x03,
  SIZE_POLICY_IGNORED          = 0x0d,
};

/****************************************************************************/
/* event classes                                                            */
/****************************************************************************/
enum
{
  EVENT_CLASS_NONE,
  EVENT_CLASS_MONITOR,
  EVENT_CLASS_APPLICATION,
};

/****************************************************************************/
/* event types                                                              */
/****************************************************************************/
enum
{
  EVENT_TYPE_NONE,
  EVENT_TYPE_BUTTON_PRESS,
  EVENT_TYPE_TEXT_ENTERED,
  EVENT_TYPE_STATUS_BUTTON,
  EVENT_TYPE_LIST_ITEM_SELECTED,
  EVENT_TYPE_TABLE_ITEM_CHANGED,
  EVENT_TYPE_CONNECTION_ESTABLISHED,
  EVENT_TYPE_CHECKBOX_CHANGED,
  EVENT_TYPE_COMBOBOX_ACTIVATED,
  EVENT_TYPE_INDICATED_SCALE_CHANGED,
  EVENT_TYPE_SKETCH_PRESSED,
  EVENT_TYPE_MESSAGEBOX_BUTTON,
  EVENT_TYPE_SKETCH_SIZE_CHANGED,
  EVENT_TYPE_TEXT_ABORTED,
  EVENT_TYPE_TEXT_DROPDOWN_ENTERED,
  EVENT_TYPE_TEXT_DROPDOWN_CHANGED,
  EVENT_TYPE_TEXT_DROPDOWN_ABORTED,
  EVENT_TYPE_USER_TEXT_INPUT_CLICKED,
  EVENT_TYPE_TAB_ACTIVATED,
  EVENT_TYPE_BATTERY_CHARGE_STATE,
  EVENT_TYPE_SCALE_BUTTON,
  EVENT_TYPE_ONOFFBOX_CHANGED,
  EVENT_TYPE_MONITOR_FUNCTION,
  EVENT_TYPE_PAGE_SELECTED,
};

/****************************************************************************/
/* weight display mode                                                      */
/****************************************************************************/
enum
{
  WEIGHT_DISPLAY_OFF,
  WEIGHT_DISPLAY_FULL,
  WEIGHT_DISPLAY_SMALL,
  WEIGHT_DISPLAY_MIDDLE,
  WEIGHT_DISPLAY_INFO,
};

/****************************************************************************/
/* widget attribute types                                                   */
/****************************************************************************/
enum
{
  WIDGET_ATTRIBUTE_NONE,
  WIDGET_ATTRIBUTE_ROWS,
  WIDGET_ATTRIBUTE_COLUMNS,
  WIDGET_ATTRIBUTE_VERTICAL_HEADER,
  WIDGET_ATTRIBUTE_HORIZONTAL_HEADER,
  WIDGET_ATTRIBUTE_DEBOUNCE_TIME,
  WIDGET_ATTRIBUTE_CLICK_EFFECT,
  WIDGET_ATTRIBUTE_AUTO_CHANGE_STATE,
};

/****************************************************************************/
/* click effects                                                            */
/****************************************************************************/
enum
{
  CLICK_EFFECT_NONE,
  CLICK_EFFECT_ENLARGE,
  CLICK_EFFECT_BLACK_WHITE,
};

/****************************************************************************/
/* widget text alignment                                                    */
/****************************************************************************/
enum
{
  WIDGET_TEXT_ALIGN_LEFT      = 0x01,
  WIDGET_TEXT_ALIGN_RIGHT     = 0x02,
  WIDGET_TEXT_ALIGN_HCENTER   = 0x04,
  WIDGET_TEXT_ALIGN_JUSTIFY   = 0x08,
  WIDGET_TEXT_ALIGN_TOP       = 0x20,
  WIDGET_TEXT_ALIGN_BOTTOM    = 0x40,
  WIDGET_TEXT_ALIGN_VCENTER   = 0x80,
  
  WIDGET_TEXT_ALIGN_HCENTER_R = 0x06, // == WIDGET_TEXT_ALIGN_HCENTER + WIDGET_TEXT_ALIGN_RIGHT 
  WIDGET_TEXT_ALIGN_VCENTER_L = 0x81,
  WIDGET_TEXT_ALIGN_VCENTER_R = 0x82,
  WIDGET_TEXT_ALIGN_CENTER    = 0x84,
};

/****************************************************************************/
/* input formats                                                            */
/****************************************************************************/
enum
{
  INPUT_FORMAT_STRING,
  INPUT_FORMAT_PASSWORD,
  INPUT_FORMAT_DATE,
  INPUT_FORMAT_TIME,
  INPUT_FORMAT_INTEGER,
  INPUT_FORMAT_BOOL,
  INPUT_FORMAT_FLOAT,
  INPUT_FORMAT_DECIMAL,
  INPUT_FORMAT_NUMERIC_STRING,
  INPUT_FORMAT_NUMERIC_PASSWORD,
};

/****************************************************************************/
/* drawing polygons                                                         */
/****************************************************************************/
enum
{
  POLYGON_DRAWING_BEGIN,
  POLYGON_DRAWING_FINISH,
  POLYGON_DRAWING_FINISH_ODD_EVEN,
  POLYGON_DRAWING_FINISH_WINDING,
};

/****************************************************************************/
/* display options                                                          */
/****************************************************************************/
enum
{
  DISPLAY_OPTION_NONE,
  DISPLAY_OPTION_SHOW_WIDGET,
  DISPLAY_OPTION_HIDE_WIDGET,
  DISPLAY_OPTION_STATUS_WIDGETS,
  DISPLAY_OPTION_STATUS_USER_TEXT,
  DISPLAY_OPTION_KEYBOARD_MODE,
  DISPLAY_OPTION_SCALE_BUTTONS,
  DISPLAY_OPTION_SCALE_LINE_FUNCTIONS,
  DISPLAY_OPTION_KEYBOARD_BEEP_FREQUENCY,
  DISPLAY_OPTION_APPLICATION_BEEP_FREQUENCY,
  DISPLAY_OPTION_SPLASH_SCREEN_TEXT,
  DISPLAY_OPTION_DISPLAY_MODE,
  DISPLAY_OPTION_SCALE_BUTTONS_SMALL,
  DISPLAY_OPTION_MONITOR_FUNCTION_LOCK,
  //SADM2
  DISPLAY_OPTION_SHOW_BLUETOOTH_STATUS,
  DISPLAY_OPTION_LOG_TIMESTAMP,
  DISPLAY_OPTION_KEYEVENT_MODE, // >= V0.5.20
  DISPLAY_OPTION_CURSOR_TYPE, // >= V.0.5.24
  DISPLAY_OPTION_CURSOR_INPUT, // >= V0.5.29
};

/****************************************************************************/
/* display option values                                                    */
/****************************************************************************/
enum
{
  STATUS_WIDGET_USER_TEXT       = 0x01,
  STATUS_WIDGET_WEIGHING_LABEL  = 0x02,
  STATUS_WIDGET_POWER           = 0x04,
  STATUS_WIDGET_DATE_TIME       = 0x08,
  //SADM2
  STATUS_WIDGET_USER_TEXT_TIME  = 0x09,
  
  STATUS_WIDGET_WIFI            = 0x10,
  STATUS_WIDGET_FORKS           = 0x20,
  STATUS_WIDGET_COM             = 0x40,
  
  //SADM2
  STATUS_WIDGET_TERMINAL_NUMBER = 0x80,
  STATUS_WIDGET_BLUETOOTH       = 0x100,
};

enum
{
  BLUETOOTH_STATUS_CONNECTED,
  BLUETOOTH_STATUS_PAIRED_NOT_CONNECTED,
  BLUETOOTH_STATUS_UNPAIRED,
  __BLUETOOTH_STATUS_MAX
};

enum
{
  DISPLAY_WIDGET_SCALE,
  DISPLAY_WIDGET_HEAD_LINE,
};

enum
{
  KEYBOARD_MODE_ALPHANUMERIC,
  KEYBOARD_MODE_NUMERIC,
  
  //SADM2
  /*  No supported at the moment np+ 10.01.19
  KEYBOARD_MODE_BOOL,
  KEYBOARD_MODE_SELECT,
  KEYBOARD_MODE_NEGNUM,
  KEYBOARD_MODE_ALPHA2,
  KEYBOARD_MODE_FLOAT,
  KEYBOARD_MODE_PASSWORD,
  KEYBOARD_MODE_NONE
*/
};

enum
{
  KEYEVENT_MODE_RAW,
  KEYEVENT_MODE_INTERPRETED,
  __KEYEVENT_MODE_MAX
};

enum
{
  CURSOR_TYPE_REGULAR,
  CURSOR_TYPE_HAND,
  CURSOR_TYPE_ARROW,
  CURSOR_TYPE_CROSS,
  CURSOR_TYPE_DISABLED,
};

enum
{
  CURSOR_INPUT_TOUCHSCREEN,
  CURSOR_INPUT_MOUSE,
};

enum
{
  SCALE_BUTTON_ZERO         = 0x01,
  SCALE_BUTTON_SELECT       = 0x02,
  SCALE_BUTTON_ZERO_SELECT  = 0x03,  
  SCALE_BUTTON_PRESET_TARE  = 0x04,
  SCALE_BUTTON_TARE         = 0x08,
  SCALE_BUTTON_SCALE        = 0x10,
  SCALE_BUTTON_ZERO_TARE    = 0x09,



};

enum
{
  SCALE_LINE_TARE_WEIGHT    = 0x01,
  SCALE_LINE_GROSS_WEIGHT   = 0x02,
  SCALE_LINE_BARGRAPH       = 0x04,
  SCALE_LINE_APPROVALDATA   = 0x08,
};

enum
{
  DISPLAY_MODE_WEIGHT,
  DISPLAY_MODE_PIECES,
};


enum
{
  MONITOR_FUNCTION_ENABLE_ALL_FUNCTIONS	= 0x00,
  MONITOR_FUNCTION_SERVICE_MODE_ACCESS  = 0x01, };


#endif // __qtmonitor_h_



