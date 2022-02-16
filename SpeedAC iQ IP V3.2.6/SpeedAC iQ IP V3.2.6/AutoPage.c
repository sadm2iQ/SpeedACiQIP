﻿#define  MAX_BARGRAPH        1 
#define  MAX_SILO_CAPACITY   200000            
#define  GRAPH_REMAIN_SPACE  1000   
#define  PERCENT             0.0002  // 0.5%
//#define  GRAPH3D             

/*------------------------------------------------------------------------------- 
--  Procedure Name    : UpdateBargraph
--  Created by        : Kittipong Namvichai
--  Last modified on  : 2018/05
--  
--  Purpose           : Update Bargraph
--                      
--  Value Parameters  :  
--  Variable Params   : id, width, height, percent
--  Side Effects      : 
--------------------------------------------------------------------------------*/
void UpdateBargraph (int id, int width, int height,int color, float percent)
{
 int pixel = percent * (width-2);
 begindraw ();
   selectsketch (id);

   // draw bar
   background (color); 
   posto (1, 1);
   boxto (pixel, height-2, 1);

   // clean remainder
   background (BARGRAPH_BACKGROUND_COLOR);
   posto (pixel+1, 1);
   boxto (width-2, height-2, 1);
 enddraw ();
}


/*------------------------------------------------------------------------------- 
--  Procedure Name    : CreateBargraph
--  Created by        : Kittipong Namvichai
--  Last modified on  : 2018/05
--  
--  Purpose           : Create Bargraph
--                      
--  Value Parameters  :
--  Variable Params   : id, width, height
--  Side Effects      : 
--------------------------------------------------------------------------------*/
void CreateBargraph (int id, int width, int height)
{
  createwidget (id, WIDGET_TYPE_SKETCH);
  widget_dimensions (id, width, height);
}

/*------------------------------------------------------------------------------- 
--  Procedure Name    : InitBargraph
--  Created by        : Kittipong Namvichai
--  Last modified on  : 2018/05
--  
--  Purpose           : Initial Bargraph
--                      
--  Value Parameters  :
--  Variable Params   : id, width, height
--  Side Effects      : 
--------------------------------------------------------------------------------*/
void InitBargraph (int id, int width, int height)
{
  begindraw ();
  #ifdef GRAPH3D
    //selectsketch (id);
    //posto (0, 0);               // .
    //lineto (width-1, 0);        // ---------------------
    //lineto (width-1, height-1); //                     |
    //lineto (0, height-1);       // ---------------------
    //lineto (0, 0);              // |
  #else
    selectsketch (id);
    posto (0, 0);               // .
    lineto (width-1, 0);        // ---------------------
    lineto (width-1, height-1); //                     |
    lineto (0, height-1);       // ---------------------
    lineto (0, 0);              // |
  #endif 
  enddraw ();
}



void CreateAutoRecipeButton (int id, int font_size, int font_face, string fg_color, string bg_color, string text)
{
  createwidget (id, WIDGET_TYPE_BUTTON);
//    widget_dimensions      (id,  435,45);   
    widget_size_policy     (id,  SIZE_POLICY_FIXED, SIZE_POLICY_FIXED);     
    widget_fontsize        (id,  font_size); 
    widget_fontface        (id,  font_face);
    widget_foreground      (id,  fg_color);
    widget_background      (id,  bg_color);
    widget_text_alignment  (id,  WIDGET_TEXT_ALIGN_CENTER );
    widget_text            (id,  text );
    widget_style           (id,  AUTOWPBOX_STYLE);
    widget_content_margins (id,  0,0,0,10); 
    widget_maximum_size    (id,  450, 45);  
    widget_attribute       (id,  WIDGET_ATTRIBUTE_CLICK_EFFECT, CLICK_EFFECT_BLACK_WHITE); 
}

/* *********************************************************************** */
/*                                                                         */
/*   Create AUTO page                                                      */
/*                                                                         */
/* *********************************************************************** */

void CreateAutoScreen(void) 
{
begindraw();
  createpage(PAGE_AUTO);  
  page_background (PAGE_AUTO, BackgroundColor);                                       
                                                                                   
// Border control   
  beginlayout(LAYOUT_TYPE_VBOX, 0); //VBOX #1
          
        beginlayout(LAYOUT_TYPE_HBOX, 0); //search recipe button
          CreatePTLogoHeader();
          CreateAutoRecipeButton (ACTIVE_RECIPE_ID, FT_MEDIUM_SIZE, FT_RTC_BOLD, CL_PT_BLUE, CL_PT_WHITE, concat (space(1), lsub(WP.Name), space(1)));
         
          beginlayout(LAYOUT_TYPE_HBOX, 0);  //HBOX #1   
           //Fault and Mode display
           CreateModeFltDisplay();
          endlayout();  // End layout of HBOX #1
         setlayoutoption (LAYOUT_OPTION_CONTENT_MARGINS, "0,2,0,0"); //"left,top,right,bottom"
        endlayout(); // End of search recipe button
 
       beginlayout(LAYOUT_TYPE_HBOX, 0);  //HBOX #2

//beginlayout(LAYOUT_TYPE_GRID, 0);        
//setlayoutoption (LAYOUT_OPTION_CONTENT_MARGINS, "0,0,0,0"); //"left,top,right,bottom"

       // First Column
       
          //  First column on the left
          beginlayout(LAYOUT_TYPE_GRID, 0,3); // Grid #1
//setlayoutoption (LAYOUT_OPTION_CONTENT_MARGINS, "0,0,0,0"); //"left,top,right,bottom" 
            beginrow(); // First row with one column
              CreatePromptField (AUTO_ROW1_ID,     CL_PT_BLUE, false, lsub(TX_NOMINAL_WEIGHT_ID), FT_AUTOPAGE2_SIZE, WD_AUTO_DESCRIPTION, HT_AUTO_DESCRIPTION, Left_Margin, widget_locked); //true
              CreateOutputDataField (AUTO_ROW1_OUTPUT, FT_RTC_BOLD, FT_AUTOPAGE2_SIZE, WIDGET_TEXT_ALIGN_RIGHT, WD_AUTOPAGE_BOX, HT_AUTOPAGE_BOX, widget_locked);
              CreateUnitField   (AUTO_ROW1_UNIT,  FT_RTC_BOLD, FT_AUTOPAGE2_SIZE,          WP.Unit , WD_AUTO_UNIT+30, HT_AUTOPAGE_BOX, widget_locked);                               
              
              CreatePromptField (AUTO_ROW22_ID,     CL_PT_BLUE, false, lsub(TX_BULK_TIME_ID), FT_AUTOPAGE2_SIZE, WD_AUTO_DESCRIPTION, HT_AUTO_DESCRIPTION, No_Margin, widget_locked); 
              CreateOutputDataField (AUTO_ROW22_OUTPUT, FT_RTC_BOLD, FT_AUTOPAGE2_SIZE, WIDGET_TEXT_ALIGN_RIGHT, WD_AUTOPAGE_BOX, HT_AUTOPAGE_BOX, widget_locked);
              CreateUnitField   (AUTO_ROW22_UNIT,  FT_RTC_BOLD, FT_AUTOPAGE2_SIZE,          lsub(TX_SEC_UNIT) , WD_AUTO_UNIT+30, HT_AUTOPAGE_BOX, widget_locked);   
              
              CreatePromptField (AUTO_ROW23_ID,     CL_PT_BLUE, false, lsub(TX_DRIBBLE_TIME_ID), FT_AUTOPAGE2_SIZE, WD_AUTO_DESCRIPTION, HT_AUTO_DESCRIPTION, No_Margin, widget_locked); 
              CreateOutputDataField (AUTO_ROW23_OUTPUT, FT_RTC_BOLD, FT_AUTOPAGE2_SIZE, WIDGET_TEXT_ALIGN_RIGHT, WD_AUTOPAGE_BOX, HT_AUTOPAGE_BOX, widget_locked);
              CreateUnitField   (AUTO_ROW23_UNIT,  FT_RTC_BOLD, FT_AUTOPAGE2_SIZE,          lsub(TX_SEC_UNIT) , WD_AUTO_UNIT+30, HT_AUTOPAGE_BOX, widget_locked); 
              
                                                
                     
            endrow();

            beginrow(); // Second row with one column 
              CreatePromptField (AUTO_ROW2_ID,     CL_PT_BLUE, false, lsub(TX_AVERAGE_ID), FT_AUTOPAGE2_SIZE, WD_AUTO_DESCRIPTION, HT_AUTO_DESCRIPTION, Left_Margin, widget_locked); //true
              CreateOutputDataField (AUTO_ROW2_OUTPUT, FT_RTC_BOLD, FT_AUTOPAGE2_SIZE, WIDGET_TEXT_ALIGN_RIGHT, WD_AUTOPAGE_BOX, HT_AUTOPAGE_BOX, widget_locked);
              CreateUnitField   (AUTO_ROW2_UNIT,  FT_RTC_BOLD, FT_AUTOPAGE2_SIZE,          WP.Unit , WD_AUTO_UNIT+30, HT_AUTOPAGE_BOX, widget_locked); 
              
              CreatePromptField (AUTO_ROW24_ID,     CL_PT_BLUE, false, lsub(TX_CYCLE_TIME_ID), FT_AUTOPAGE2_SIZE, WD_AUTO_DESCRIPTION, HT_AUTO_DESCRIPTION, No_Margin, widget_locked); 
              CreateOutputDataField (AUTO_ROW24_OUTPUT, FT_RTC_BOLD, FT_AUTOPAGE2_SIZE, WIDGET_TEXT_ALIGN_RIGHT, WD_AUTOPAGE_BOX, HT_AUTOPAGE_BOX, widget_locked);
              CreateUnitField   (AUTO_ROW24_UNIT,  FT_RTC_BOLD, FT_AUTOPAGE2_SIZE,          lsub(TX_SEC_UNIT) , WD_AUTO_UNIT+30, HT_AUTOPAGE_BOX, widget_locked);
              
              CreatePromptField (AUTO_ROW13_ID,     CL_PT_BLUE, false, lsub(TX_UNITS_DONE_ID), FT_AUTOPAGE2_SIZE, (WD_AUTO_DESCRIPTION), HT_AUTO_DESCRIPTION, No_Margin, widget_locked); 
              CreateOutputDataField (AUTO_ROW13_OUTPUT, FT_RTC_BOLD, FT_AUTOPAGE2_SIZE, WIDGET_TEXT_ALIGN_RIGHT, (WD_AUTOPAGE_BOX), HT_AUTOPAGE_BOX, widget_locked);
              CreateUnitField   (AUTO_ROW13_UNIT,  FT_RTC_BOLD, FT_AUTOPAGE2_SIZE,          "" , WD_AUTO_UNIT+30, HT_AUTOPAGE_BOX, widget_locked);        
                
            endrow();
            
           
            
          endlayout();  // End Grid layout #1 
          
          //CreatePromptField (AUTO_SPACE_3,    CL_PT_BLUE, false,                       "", FT_STANDARD_SIZE, 90, HT_AUTO_DESCRIPTION, No_Margin, widget_locked);//260 
               
        endlayout(); // End of HBOX #2
        
        beginlayout(LAYOUT_TYPE_HBOX, 0); // HBOX #3
        
           beginlayout(LAYOUT_TYPE_GRID, 0); // GRID #test
            beginrow(); 
              CreatePromptField (AUTO_ROW15_ID,     CL_PT_BLUE, false, lsub(TX_PRESETFEEDRATE_ID), FT_AUTOPAGE2_SIZE, (WD_AUTO_DESCRIPTION), HT_AUTO_DESCRIPTION, Left_Margin, widget_locked);            
            endrow();
            beginrow();
              CreatePromptField (AUTO_ROW5_ID,     CL_PT_BLUE, false, lsub(TX_ACTUALFEEDRATE_ID), FT_AUTOPAGE2_SIZE, (WD_AUTO_DESCRIPTION), HT_AUTO_DESCRIPTION, Left_Margin, widget_locked);
            endrow();
          endlayout();
          
          beginlayout(LAYOUT_TYPE_GRID, 0); // GRID #test
            beginrow(); 
              CreateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT);   //create first bargraph
            endrow();
            
            beginrow();
              CreateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT);   //create second bargraph
            endrow();
          endlayout();
          
          beginlayout(LAYOUT_TYPE_GRID, 0); // GRID#test
            beginrow(); 
               CreateOutputDataField (AUTO_ROW15_OUTPUT, FT_RTC_BOLD, FT_AUTOPAGE2_SIZE, WIDGET_TEXT_ALIGN_RIGHT, (WD_AUTOPAGE_BOX+15), HT_AUTOPAGE_BOX, widget_locked);
               CreateUnitField   (AUTO_ROW15_UNIT,  FT_RTC_BOLD, FT_AUTOPAGE2_SIZE,         WP.Unit + "/h", (WD_AUTO_UNIT+30), HT_AUTOPAGE_BOX, widget_locked);                                         
            endrow();
                        
            beginrow(); 
               CreateOutputDataField (AUTO_ROW5_OUTPUT, FT_RTC_BOLD, FT_AUTOPAGE2_SIZE, WIDGET_TEXT_ALIGN_RIGHT, (WD_AUTOPAGE_BOX+15), HT_AUTOPAGE_BOX, widget_locked);
               CreateUnitField   (AUTO_ROW5_UNIT,  FT_RTC_BOLD, FT_AUTOPAGE2_SIZE,          WP.Unit + "/h" , (WD_AUTO_UNIT+30), HT_AUTOPAGE_BOX, widget_locked);               
            endrow();
          endlayout();     
          
          beginlayout(LAYOUT_TYPE_GRID, 0); // GRID #test 
            beginrow(); // First row with one column 
              CreatePromptField (AUTO_ROW3_ID,      CL_PT_BLUE, false, lsub(TX_TOTAL_WEIGHT_ID), (FT_AUTOPAGE2_SIZE+10), (WD_AUTO_DESCRIPTION-10), (HT_AUTO_DESCRIPTION+15), No_Margin, widget_locked);
              //CreateOutputDataField (AUTO_ROW3_OUTPUT, FT_RTC_BOLD, FT_AUTOPAGE2_SIZE+10, WIDGET_TEXT_ALIGN_LEFT, WD_AUTOPAGE_BOX+130, HT_AUTOPAGE_BOX+35, widget_locked);   
              CreateOutputDataField (AUTO_ROW3_OUTPUT, FT_RTC_BOLD, FT_AUTOPAGE2_SIZE+10, WIDGET_TEXT_ALIGN_LEFT, (WD_AUTOPAGE_BOX+140), HT_AUTOPAGE_BOX+15, widget_locked);                   
            endrow();                          
          endlayout();   
          
        endlayout();   // End of HBOX #2  
        
        
    beginlayout(LAYOUT_TYPE_VBOX, 0); // HBOX #4 
      
    createwidget (0, WIDGET_TYPE_STRETCH);
 
    beginlayout(LAYOUT_TYPE_GRID, 0,2);
     beginrow();
    /*Display message line*/
      createwidget (MESSAGE_DISPLAY, WIDGET_TYPE_TEXT_OUTPUT);
        widget_foreground      (MESSAGE_DISPLAY,   CL_PT_BLUE);
        widget_text_alignment  (MESSAGE_DISPLAY,   WIDGET_TEXT_ALIGN_HCENTER);
        widget_fontsize        (MESSAGE_DISPLAY,   PT_INFO_LINE);
        widget_size_policy     (MESSAGE_DISPLAY,   SIZE_POLICY_FIXED, SIZE_POLICY_MINIMUM);
        widget_maximum_size    (MESSAGE_DISPLAY,  850, 0);
        widget_text            (MESSAGE_DISPLAY,   "");
        widget_text_alignment  (MESSAGE_DISPLAY,   WIDGET_TEXT_ALIGN_LEFT);
        widget_content_margins (MESSAGE_DISPLAY, Left_Margin,0,0,0);
        
    /*Display High resolution Weight*/   
      createwidget (HIRESWEIGHT, WIDGET_TYPE_TEXT_OUTPUT);
        widget_foreground      (HIRESWEIGHT,   CL_PT_BLUE);
        widget_text_alignment  (HIRESWEIGHT,   WIDGET_TEXT_ALIGN_HCENTER);
        widget_fontsize        (HIRESWEIGHT,   PT_INFO_LINE);
        widget_size_policy     (HIRESWEIGHT,   SIZE_POLICY_FIXED, SIZE_POLICY_MINIMUM);
        widget_maximum_size    (HIRESWEIGHT,  150, 0);
        widget_text            (HIRESWEIGHT,   concat(NetWeightHiRes[Scale1],space(1),WP.Unit,space(1)));
        widget_text_alignment  (HIRESWEIGHT,   WIDGET_TEXT_ALIGN_RIGHT);
        widget_content_margins (HIRESWEIGHT, 0,2,0,0);    
     endrow();   
    endlayout();
     
      CreateNavigButtons (10, NAV_FCT_BUTTON_1, false);
      DrawNavButtons (SCREEN_AUTOMATIC, true, BTN_AUTO, BTN_RECIPE, BTN_REPORT, BTN_NAVIG, BTN_ALARM, BTN_DISCH_PAN_OFF, BTN_OFF, HOPPER_FILL, BTN_START, BTN_STOP);   
    
  endlayout(); // End layout of VBOX #1 
  
enddraw();

}

/*------------------------------------------------------------------------------- 
--  Procedure Name    : RefreshAutoScreenTextByMode
--  Created by        : Kittipong Namvichai
--  Last modified on  : 2018/09/19
--  
--  Purpose           : Change text refers mode related to bar graphs on auto screen 
--                      
--  Value Parameters  : None
--  Variable Params   : None
--  Side Effects      : 
--------------------------------------------------------------------------------*/
void RefreshAutoScreenTextByMode(void)
{
 int SiloNoTemp, SiloDestTemp;
 bool TransferSiloTemp;
 string UnitSelected[3];

        if((SeqModeManager == stp_OFF_MODE || SeqModeManager == stp_STOP_MODE) ||  
        SiloNoTemp != WP.SiloNo || SiloDestTemp != WP.SiloDest || TransferSiloTemp != WP.TransferSilo)
        {
          if(UnitTemp == "t")
          {
            UnitSelected = UnitTemp;
          }
          else
          {
            UnitSelected = WP.Unit;
          }
        
          SiloNoTemp = WP.SiloNo;
          SiloDestTemp = WP.SiloDest;
          TransferSiloTemp = WP.TransferSilo;
          
          if (MC.WeighingMode == Monitoring) 
          {   
              // Third row info                                                                                 
              widget_text      (AUTO_ROW15_ID,    lsub(TX_MPMAXFEEDRATE));
              // Third row unit info
              widget_text      (AUTO_ROW15_UNIT, lsub(UnitSelected + TX_PER_HOUR));
              // Fourth row info                                                
              widget_text      (AUTO_ROW5_ID,    lsub(TX_ACTUALFEEDRATE_ID));
              // Fourth row unit info             
              widget_text      (AUTO_ROW5_UNIT, lsub(UnitSelected + TX_PER_HOUR));
          }
                    
          else if (MC.WeighingMode == FeedRateControl || MC.WeighingMode == TimeControl) 
          {
             // Third row info 
             widget_text      (AUTO_ROW15_ID,    lsub(TX_PRESETFEEDRATE_ID));
             // Third row unit info
             widget_text      (AUTO_ROW15_UNIT, lsub(UnitSelected + TX_PER_HOUR));                                               
             // Fourth row info
             widget_text      (AUTO_ROW5_ID,    lsub(TX_ACTUALFEEDRATE_ID));             
             // Fourth row unit info 
             widget_text      (AUTO_ROW5_UNIT, lsub(UnitSelected + TX_PER_HOUR));
          }
          
           else if (MC.WeighingMode == Batching) 
          {
             if(WP.PresetBatch != 0)
             { 
               /*
               // Third row info
               widget_text      (AUTO_ROW15_ID,    lsub(TX_BATCH_TARGET_ID));
               // Third row unit info
               widget_text      (AUTO_ROW15_UNIT, "");                                               
               // Fourth row info
               widget_text      (AUTO_ROW5_ID,    lsub(TX_BATCH_REMAIN_ID));             
               // Fourth row unit info
               widget_text      (AUTO_ROW5_UNIT, "");
               */
               // Third row info                                                                                 
              widget_text      (AUTO_ROW15_ID,    lsub(TX_MPMAXFEEDRATE));
              // Third row unit info
              widget_text      (AUTO_ROW15_UNIT, lsub(UnitSelected + TX_PER_HOUR));
              // Fourth row info                                                
              widget_text      (AUTO_ROW5_ID,    lsub(TX_ACTUALFEEDRATE_ID));
              // Fourth row unit info             
              widget_text      (AUTO_ROW5_UNIT, lsub(UnitSelected + TX_PER_HOUR));
             }
             else
             {
               // Third row info
               widget_text      (AUTO_ROW15_ID,    lsub(TX_BATCH_TARGET_ID));
               // Third row unit info
               widget_text      (AUTO_ROW15_UNIT, WP.Unit);                                               
               // Fourth row info
               widget_text      (AUTO_ROW5_ID,    lsub(TX_BATCH_REMAIN_ID));             
               // Fourth row unit info
               widget_text      (AUTO_ROW5_UNIT, WP.Unit);
             }
          }
                 
          else if (MC.WeighingMode == Bulk)
          {
            
            if (WP.TransferSilo == YES && (WP.BulkModeIP == Receive || WP.BulkModeIP == Ship))
            {
              // Third row info
              widget_text      (AUTO_ROW15_ID,   (lsub(TX_SILO_SOURCE_ID)) + adj(WP.SiloNo, 2, 0));
              // Third row unit info
              widget_text      (AUTO_ROW15_UNIT, WP.Unit);                                              
              // Fourth row info
              widget_text      (AUTO_ROW5_ID,   (lsub(TX_SILODEST_ID)) + adj(WP.SiloDest, 2, 0));
              // Fourth row unit info
              widget_text      (AUTO_ROW5_UNIT, WP.Unit); 
            }
            
            else if (WP.TransferSilo == NO && WP.BulkModeIP == Receive)
            {
              // Third row info
              widget_text      (AUTO_ROW15_ID,    lsub(TX_NETWEIGHT_ID));
              // Third row unit info
              widget_text      (AUTO_ROW15_UNIT, WP.Unit);                                              
              // Fourth row info
              widget_text      (AUTO_ROW5_ID,   (lsub(TX_SILONO_ID)) + adj(WP.SiloNo, 2, 0));
              // Fourth row unit info
              widget_text      (AUTO_ROW5_UNIT, WP.Unit); 
            }
            
            else if (WP.TransferSilo == NO && WP.BulkModeIP == Ship)
            {
              // Third row info
              widget_text      (AUTO_ROW15_ID,    lsub(TX_BATCH_TARGET_ID));
              // Third row unit info
              widget_text      (AUTO_ROW15_UNIT, WP.Unit);                                               
              // Fourth row info
              widget_text      (AUTO_ROW5_ID,    lsub(TX_BATCH_REMAIN_ID));             
              // Fourth row unit info
              widget_text      (AUTO_ROW5_UNIT, WP.Unit);
            }
            
          }
          else if (MC.WeighingMode == FlowThrough) 
          {
             // Third row info 
             widget_text      (AUTO_ROW15_ID,    "");
             // Third row unit info
             widget_text      (AUTO_ROW15_UNIT, "");                                               
             // Fourth row info
             widget_text      (AUTO_ROW5_ID,    "");             
             // Fourth row unit info 
             widget_text      (AUTO_ROW5_UNIT, "");
          }
        }                             
}


/*------------------------------------------------------------------------------- 
--  Procedure Name    : RefreshAutoScreenDataByMode
--  Created by        : Kittipong Namvichai
--  Last modified on  : 2018/07/24
--  
--  Purpose           : Refresh operation mode and update data in Auto page
--                      
--  Value Parameters  :
--  Variable Params   : None
--  Side Effects      : 
--------------------------------------------------------------------------------*/
void RefreshAutoScreenDataByMode(void)
{
  int ProdSiloNo,ProdSiloDest;
  ProdSiloNo = int(WP.SiloNo);
  ProdSiloDest = int(WP.SiloDest);
  //decimal ProdFeedRateTemp%10.4;
  double MaxFeedRateTemp, ProdFeedRateTemp;
  double PresetFeedRateTemp, ProdEvalFeedRateTemp;
  //decimal ProdEvalFeedRateTemp%10.4;
  
  if(UnitTemp == "t")
  {
    MaxFeedRateTemp = MP.MaxFeedRate/1000;
    ProdFeedRateTemp = ProdFeedRate[Scale1]/1000;
    ProdEvalFeedRateTemp = ProdEvalFeedRate[Scale1]/1000;
    PresetFeedRateTemp = ProdPresetFeedRate/1000;
  }
    else
  {
    MaxFeedRateTemp = MP.MaxFeedRate;
    ProdFeedRateTemp = ProdFeedRate[Scale1];
    ProdEvalFeedRateTemp = ProdEvalFeedRate[Scale1];
    PresetFeedRateTemp = ProdPresetFeedRate;
  }
    
  switch(MC.WeighingMode)
  {
    case Monitoring:
         UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(MP.MaxFeedRate / (MP.MaxFeedRate + (MP.MaxFeedRate*PERCENT))));   
         widget_text    (AUTO_ROW15_OUTPUT, trim(adj(MaxFeedRateTemp,10,1)));         
           
         widget_text    (AUTO_ROW5_OUTPUT, trim(adj(ProdFeedRateTemp,10,1)));           
         UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdFeedRate[Scale1] / (MP.MaxFeedRate + (MP.MaxFeedRate*PERCENT)))); 
         break;
         
    case TimeControl:        
         UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdEvalFeedRate[Scale1] / (ProdEvalFeedRate[Scale1] + (ProdEvalFeedRate[Scale1]*PERCENT))));   
         widget_text       (AUTO_ROW15_OUTPUT, trim(adj(ProdEvalFeedRateTemp,10,1)));     
              
         widget_text    (AUTO_ROW5_OUTPUT, trim(adj(ProdFeedRateTemp,10,1)));           
         UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdFeedRate[Scale1] / (ProdEvalFeedRate[Scale1] + (ProdEvalFeedRate[Scale1]*PERCENT)))); 
         break;
         
    case FeedRateControl:
         UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdPresetFeedRate / (MP.MaxFeedRate + (MP.MaxFeedRate*PERCENT))));   
         widget_text       (AUTO_ROW15_OUTPUT, trim(adj(PresetFeedRateTemp,10,1))); 
         
         widget_text    (AUTO_ROW5_OUTPUT, trim(adj(ProdFeedRateTemp,10,1)));           
         UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdFeedRate[Scale1] / (MP.MaxFeedRate + (MP.MaxFeedRate*PERCENT)))); 
         break;
         
    case Batching:
         if(WP.PresetBatch > 0)
         {
         /*
           UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(WP.PresetBatch  / (WP.PresetBatch + (WP.PresetBatch*PERCENT))));   
           widget_text       (AUTO_ROW15_OUTPUT, adj(WP.PresetBatch,6,0)); 
           
           widget_text    (AUTO_ROW5_OUTPUT, adj(ProdRemainBatch,6,0));           
           UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdRemainBatch / (WP.PresetBatch + (WP.PresetBatch*PERCENT)) ));
         */
           UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(MP.MaxFeedRate / (MP.MaxFeedRate + (MP.MaxFeedRate*PERCENT))));   
           widget_text    (AUTO_ROW15_OUTPUT, trim(adj(MaxFeedRateTemp,10,1)));         
           
           widget_text    (AUTO_ROW5_OUTPUT, trim(adj(ProdFeedRateTemp,10,1)));           
           UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdFeedRate[Scale1] / (MP.MaxFeedRate + (MP.MaxFeedRate*PERCENT)))); 
           break;
         }
         else
         {
           UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(WP.TargetWeightIP / (WP.TargetWeightIP + (WP.TargetWeightIP*PERCENT))));   
           widget_text       (AUTO_ROW15_OUTPUT, adj(WP.TargetWeightIP,10,dp)); 
         
           widget_text    (AUTO_ROW5_OUTPUT, adj(ProdRemainWeight,10,dp));           
           UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdRemainWeight / (WP.TargetWeightIP + (WP.TargetWeightIP*PERCENT))));
           break;
         }
         
    case Bulk:
         if(WP.TransferSilo == YES && WP.BulkModeIP == Receive)
         {
           UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdSiloNoWeight[ProdSiloNo] / (MAX_SILO_CAPACITY + (MAX_SILO_CAPACITY*PERCENT))));   
           widget_text       (AUTO_ROW15_OUTPUT, adj(ProdSiloNoWeight[ProdSiloNo],10,1)); 
         
           widget_text    (AUTO_ROW5_OUTPUT, adj(ProdSiloNoWeight[ProdSiloDest],10,1));           
           UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdSiloNoWeight[ProdSiloDest] / (MAX_SILO_CAPACITY + (MAX_SILO_CAPACITY*PERCENT))));
         }
         else if(WP.TransferSilo == NO && WP.BulkModeIP == Receive)
         {
           UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(NetWeight[Scale1] / (WP.NominalWeight + (WP.NominalWeight*PERCENT))));   
           widget_text       (AUTO_ROW15_OUTPUT, adj(NetWeight[Scale1],6,2)); 
         
           widget_text    (AUTO_ROW5_OUTPUT, adj(ProdSiloNoWeight[ProdSiloNo],10,dp));           
           UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdSiloNoWeight[ProdSiloNo] / (MAX_SILO_CAPACITY + (MAX_SILO_CAPACITY*PERCENT))));
         } 
         
         else if(WP.TransferSilo == YES && WP.BulkModeIP == Ship) 
         {
           UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdSiloNoWeight[ProdSiloNo] / (MAX_SILO_CAPACITY + (MAX_SILO_CAPACITY*PERCENT))));   
           widget_text       (AUTO_ROW15_OUTPUT, adj(ProdSiloNoWeight[ProdSiloNo],10,1)); 
         
           widget_text    (AUTO_ROW5_OUTPUT, adj(ProdSiloNoWeight[ProdSiloDest],10,1));           
           UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdSiloNoWeight[ProdSiloDest] / (MAX_SILO_CAPACITY + (MAX_SILO_CAPACITY*PERCENT))));
         }   
         
         else if(WP.TransferSilo == NO && WP.BulkModeIP == Ship)
         {
           UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs((WP.TargetWeightIP+DTFWeight) / ((WP.TargetWeightIP+DTFWeight) + ((WP.TargetWeightIP+DTFWeight)*PERCENT))));   
           widget_text       (AUTO_ROW15_OUTPUT, adj((WP.TargetWeightIP+DTFWeight),10,dp)); 
         
           widget_text    (AUTO_ROW5_OUTPUT, adj(ProdRemainWeight,10,dp));           
           UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(ProdRemainWeight / (WP.TargetWeightIP+DTFWeight + (WP.TargetWeightIP*PERCENT))));
         }                   
         break;
         
    case FlowThrough:
           UpdateBargraph (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(FlowThroughGraphCnt / (10+(10*0.01))));
           widget_text       (AUTO_ROW15_OUTPUT, ""); 
         
           widget_text    (AUTO_ROW5_OUTPUT, "");   
           UpdateBargraph (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT,BARGRAPH_FOREGROUND_COLOR, abs(FlowThroughGraphCnt / (10+(10*0.01))));
         break;
  }  
}

/* *********************************************************************** */
/*                                                                         */
/*       Refresh Auto screen display                                       */
/*                                                                         */
/* *********************************************************************** */

void RefreshAutoScreen(bool RefreshAll)
{
 bool    FirstPassDone;
 decimal TargetWeightTemp%6.2[2],ProdAvgWeightTemp%6.2[2],ProdStdDevTemp%6.4[2],ProdLastCheckedTemp%7.3[2], TargetWeightBatchTempTemp%6.2;
 decimal ProdTotalWeightTemp%10.2[2],ProdFeedRateTemp%10.2[2],ProdPresetFeedRateTemp%10.2[2],BatchTotalWeightTemp%10.2;
 decimal ProdAcceptUnitCntTemp%6.0[2],WeighPerUnitAccTemp%5.0,ProdTotalUnitsCntTemp%6.0[2];
 decimal ProdCycleUnitsPerMinTemp%6.2,ProdBulkDurationTemp%6.2[2],ProdDribbleDurationTemp%6.2[2],ProdCycleDurationTemp%6.2[2],PrdFeedRateTemp%10.2;
 decimal NetWeightTemp%6.2;
 int     Batch_CountTemp, BatchUnitsDoneTemp,FlowThroughGraphCntTemp;
 int     WPTransferSiloTemp,WPBulkModeIPTemp,MCWeighingModeTemp,WPPresetBatchTempMem,WPBatchTargetTempMem; 
 
  if(RefreshAll)
  {
   FirstPassDone = OFF;
  }

  begindraw();
        //if(SeqModeManager == stp_OFF_MODE)RefreshRecipeInAutoScreen();
        //RefreshCurrentUser();
        InitBargraph   (BARGRAPH_ID1, BARGRAPH_WIDTH, BARGRAPH_HEIGHT);
        InitBargraph   (BARGRAPH_ID2, BARGRAPH_WIDTH, BARGRAPH_HEIGHT); 
  // First Column                                
                                            
        // First Row Info 
        if(TargetWeightTemp[Scale1] != TargetWeight[Scale1] || !FirstPassDone || TargetWeightBatchTempTemp != TargetWeightBatchTemp)
        {
         
         if(BulkByWeightON)
         {
         widget_text (AUTO_ROW1_OUTPUT, adj(TargetWeightBatchTemp,6,dp));
         if(BulkByWeightON)BulkByWeightON = OFF; //SADM2 2020 November
         }
         else
         {
         widget_text (AUTO_ROW1_OUTPUT, adj(TargetWeight[Scale1],6,dp));
         }
         TargetWeightTemp[Scale1] = TargetWeight[Scale1];
         TargetWeightBatchTempTemp = TargetWeightBatchTemp;
        } 
        if(SeqModeManager == stp_OFF_MODE)widget_text (AUTO_ROW1_UNIT, WP.Unit);
  
        // 2nd Row Info 
        if(ProdAvgWeightTemp[Scale1] != ProdAvgWeight[Scale1] || !FirstPassDone)
        {
         widget_text (AUTO_ROW2_OUTPUT, adj(ProdAvgWeight[Scale1],6,dp));
         ProdAvgWeightTemp[Scale1] = ProdAvgWeight[Scale1];
        } 
        if(SeqModeManager == stp_OFF_MODE)widget_text (AUTO_ROW2_UNIT, WP.Unit); 
                                       
        // Third Row Info 
        if(ProdTotalWeightTemp[Scale1] != ProdTotalWeight[Scale1] || !FirstPassDone || BatchTotalWeightTemp != Batch.TotalWeight)
        {
         if(BulkByWeightON || BatchByDischON || BulkByDischON || BatchByWeightON)
         {
           if(UnitTemp == "t") 
           {
             ThroughputAutoPage = Batch.TotalWeight/1000;
             widget_text (AUTO_ROW3_OUTPUT, concat(adj(ThroughputAutoPage,6,dp+1),UnitTemp));
           }
           else 
           {
             ThroughputAutoPage = Batch.TotalWeight;
             widget_text (AUTO_ROW3_OUTPUT, concat(adj(ThroughputAutoPage,6,dp),WP.Unit)); //test 
           }
         }
         else
         {
           if(UnitTemp == "t") 
           {
             ThroughputAutoPage = ProdTotalWeight[Scale1]/1000;
             widget_text (AUTO_ROW3_OUTPUT, concat(adj(ThroughputAutoPage,6,dp+1),UnitTemp));
           }
           else 
           {
             ThroughputAutoPage = ProdTotalWeight[Scale1]; 
             widget_text (AUTO_ROW3_OUTPUT, concat(adj(ThroughputAutoPage,6,dp),WP.Unit)); 
           }
         }
         ProdTotalWeightTemp[Scale1] = ProdTotalWeight[Scale1]; 
         BatchTotalWeightTemp = Batch.TotalWeight;
        } 
        if(SeqModeManager == stp_OFF_MODE)widget_text (AUTO_ROW3_UNIT, ""); 
                                       
        // Fourth Row Info 
        if(ProdLastCheckedTemp[Scale1] != ProdLastChecked[Scale1] || !FirstPassDone)
        {
         widget_text (AUTO_ROW4_OUTPUT, adj(ProdLastChecked[Scale1],6,dp));
         ProdLastCheckedTemp[Scale1] = ProdLastChecked[Scale1];
        } 
        if(SeqModeManager == stp_OFF_MODE)widget_text (AUTO_ROW4_UNIT, WP.Unit);
        
        
  // Second Column                               
                                        
        // First Row Info 
        if(ProdAcceptUnitCntTemp[Scale1] != ProdAcceptUnitCnt[Scale1] || !FirstPassDone)
        {
         widget_text (AUTO_ROW11_OUTPUT, ProdAcceptUnitCnt[Scale1]);
         ProdAcceptUnitCntTemp[Scale1] = ProdAcceptUnitCnt[Scale1];
        }
         
        // 2nd Row Info 
        if(WeighPerUnitAccTemp != WeighPerUnitAcc || !FirstPassDone || SeqModeManager == stp_OFF_MODE)
        { 
         widget_text (AUTO_ROW12_OUTPUT, concat(WeighPerUnitAcc,"/",WP.WeighmentsPerUnit)); 
         WeighPerUnitAccTemp = WeighPerUnitAcc;
        }                                

        // Third Row Info 
        if(ProdTotalUnitsCntTemp[Scale1] != ProdTotalUnitsCnt[Scale1] || !FirstPassDone || BatchUnitsDoneTemp != Batch.UnitsDone)
        { 
         if(BulkByWeightON || BatchByDischON || BulkByDischON || BatchByWeightON)
         {
         widget_text (AUTO_ROW13_OUTPUT,  Batch.UnitsDone);
         }
         else
         {
         widget_text (AUTO_ROW13_OUTPUT,  ProdTotalUnitsCnt[Scale1]);
         }
         ProdTotalUnitsCntTemp[Scale1] = ProdTotalUnitsCnt[Scale1];
         BatchUnitsDoneTemp = Batch.UnitsDone;
         RefreshAutoScreenDataByMode();
        }                                
        // Fourth Row Info 
        if(Batch_CountTemp != Batch.Count || !FirstPassDone || SeqModeManager == stp_OFF_MODE || SeqModeManager == stp_STOP_MODE)
        { 
         widget_text (AUTO_ROW14_OUTPUT, concat(Batch.Count,"/",Batch.Preset));
         Batch_CountTemp = Batch.Count;
        } 
        
        if(MC.WeighingMode == FlowThrough && FlowThroughGraphCntTemp != FlowThroughGraphCnt)
        { 
          FlowThroughGraphCntTemp = FlowThroughGraphCnt;
          RefreshAutoScreenDataByMode();
        }
        if(NetWeightTemp != NetWeight[Scale1] && MC.WeighingMode == Bulk && WP.BulkModeIP == Receive && SeqModeManager != stp_STOP_MODE)
        {
          NetWeightTemp = NetWeight[Scale1];
          RefreshAutoScreenDataByMode();
        }
        

  // Third Column                               
                                        
        // First Row Info 
        /*if(ProdCycleUnitsPerMinTemp != ProdCycleUnitsPerMin[Scale1] || !FirstPassDone)
        {
         widget_text (AUTO_ROW21_OUTPUT, ProdCycleUnitsPerMin[Scale1]);
         ProdCycleUnitsPerMinTemp = ProdCycleUnitsPerMin[Scale1];         
        }*/
        
        if(ProdCycleUnitsPerMinTemp != ProdFeedRate[Scale1] || !FirstPassDone)
        {
         widget_text (AUTO_ROW21_OUTPUT, ProdFeedRate[Scale1]);
         ProdCycleUnitsPerMinTemp = ProdFeedRate[Scale1];       
        }
        
        // 2nd Row Info 
        if(ProdBulkDurationTemp[Scale1] != ProdBulkDuration[Scale1] || !FirstPassDone)
        {
         widget_text (AUTO_ROW22_OUTPUT, ProdBulkDuration[Scale1]);
         ProdBulkDurationTemp[Scale1] = ProdBulkDuration[Scale1];
        } 
                                         
        // Third Row Info 
        if(ProdDribbleDurationTemp[Scale1] != ProdDribbleDuration[Scale1] || !FirstPassDone)
        {
         widget_text (AUTO_ROW23_OUTPUT, ProdDribbleDuration[Scale1]);
         ProdDribbleDurationTemp[Scale1] = ProdDribbleDuration[Scale1];
        }
        
                                      
        // Fourth Row Info 
        if(ProdCycleDurationTemp[Scale1] != ProdCycleDuration[Scale1] || !FirstPassDone)
        {
         widget_text (AUTO_ROW24_OUTPUT, adj(ProdCycleDuration[Scale1],6,dp));
         ProdCycleDurationTemp[Scale1] = ProdCycleDuration[Scale1];
        } 
        
        if(SeqModeManager == stp_OFF_MODE || WPTransferSiloTemp != WP.TransferSilo || WPBulkModeIPTemp != WP.BulkModeIP 
        || MCWeighingModeTemp != MC.WeighingMode || WPPresetBatchTempMem != WP.PresetBatch || WPBatchTargetTempMem != WP.TargetWeightIP)
        {
          if(WPPresetBatchTempMem != WP.PresetBatch || WPBatchTargetTempMem != WP.TargetWeightIP)
          {
            ProdRemainWeight = (WP.TargetWeightIP+DTFWeight)- Batch.TotalWeight;
          }
          RefreshAutoScreenTextByMode();
          RefreshAutoScreenDataByMode();
          WPTransferSiloTemp = WP.TransferSilo;
          WPBulkModeIPTemp = WP.BulkModeIP;
          MCWeighingModeTemp = MC.WeighingMode;
          WPPresetBatchTempMem  = WP.PresetBatch;
          WPBatchTargetTempMem  = WP.TargetWeightIP;
          
        }
        
        if(PrdFeedRateTemp != ProdFeedRate[Scale1] && SeqModeManager != stp_OFF_MODE)
        {
          PrdFeedRateTemp = ProdFeedRate[Scale1];
          RefreshAutoScreenDataByMode();
        }
        
        if(MessageTextTemp != MessageText || !FirstPassDone)
        {
         widget_background     (MESSAGE_DISPLAY, MessageColor);
         widget_text           (MESSAGE_DISPLAY, MessageText);
         widget_background     (HIRESWEIGHT, HiResColor);
         MessageTextTemp = MessageText;
        } 

  enddraw(); 
  
   FirstPassDone = ON;                                         
}


/* *********************************************** */
/*          CreateProdDataWidget                   */                                                                 
/* *********************************************** */
void CreateProdDataWidget (int id, int width, int height, int alignment, string text, int font_size )
{
  createwidget (id, WIDGET_TYPE_TEXT_OUTPUT);
    widget_dimensions     (id,  width, height); //FCT_BUTTON_WIDTH, FCT_BUTTON_HEIGHT);      
    widget_fontsize       (id,  font_size); 
    widget_size_policy    (id,  SIZE_POLICY_FIXED,SIZE_POLICY_FIXED);     //SIZE_POLICY_MINIMUMEXPANDING, SIZE_POLICY_MINIMUM      
    widget_foreground     (id,  CL_PT_WHITE);
    if (alignment == align_hcenter)
    { 
    widget_text_alignment (id,  WIDGET_TEXT_ALIGN_HCENTER );
    }
    else if(alignment == align_left)
    {
    widget_text_alignment (id,  WIDGET_TEXT_ALIGN_LEFT);
    }
    else
    {
    widget_text_alignment (id,  WIDGET_TEXT_ALIGN_VCENTER );
    }
    widget_text           (id,  text );
   
    #if defined LAYOUT_TEST
       widget_background(id, "red" );
    #else
        widget_background(id, CL_PT_BLUE );
    #endif  
    widget_fontface       (id,  FT_RTC_BOLD); 
}


/*------------------------------------------------------------------------- 
--  Procedure Name    : CreateProdDataPopupBox
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/03/17
--  
--  Purpose           : Prod Data Popup window creation    
--                      
--  Value Parameters  :
--  Variable Params   : 
--  Side Effects      : 
--------------------------------------------------------------------------*/
void CreateProdDataPopupBox (void)         
{
  begindraw();
    createwindow (PRODDATA_POPUP_WINDOW, WINDOW_TYPE_POPUP, "Popup Window");
    windowstyle (PRODDATA_POPUP_WINDOW, POPUP_OUTBOX_STYLE2);      
      
      beginlayout (LAYOUT_TYPE_VBOX,0);
      
        beginlayout (LAYOUT_TYPE_VBOX,0);
         //Info Text
          createwidget (PRODDATA_POPUP, WIDGET_TYPE_TEXT_OUTPUT);
            widget_size_policy    (PRODDATA_POPUP,  SIZE_POLICY_MINIMUM, SIZE_POLICY_MINIMUM);
            widget_style          (PRODDATA_POPUP,  ST_BOXTEXT_STYLE); // ST_BOXTEXT_STYLE
            widget_fontsize       (PRODDATA_POPUP,  30); 
            widget_foreground     (PRODDATA_POPUP, CL_PT_BLUE );                               
            widget_text_alignment (PRODDATA_POPUP,  WIDGET_TEXT_ALIGN_HCENTER);
            widget_text           (PRODDATA_POPUP, concat(space(25),"Algorithm Statistical Data",space(25)));

        endlayout();


        beginlayout(LAYOUT_TYPE_VBOX, STD_EDGE_DISTANCE_NAVIG, FCT_BUTTON_DISTANCE_NAVIG);
 
         beginlayout(LAYOUT_TYPE_GRID, 0); // Grid Layout #1
            beginrow(); 
              CreateProdDataWidget (PRODDATA_STRING1, -1, -1, align_hcenter, "", 20);
              CreateProdDataWidget (PRODDATA_STRING2, -1, -1, align_hcenter, "", 20);
              CreateProdDataWidget (PRODDATA_STRING3, -1, -1, align_hcenter, "", 20);
            endrow(); 
            
            beginrow(); 
              CreateProdDataWidget (PRODDATA_STRING4, -1, -1, align_hcenter, "", 20);
              CreateProdDataWidget (PRODDATA_STRING5, -1, -1, align_hcenter, "               Cycle Machine for New Data                ", 20);
              CreateProdDataWidget (PRODDATA_STRING6, -1, -1, align_hcenter, "", 20);
            endrow(); 
            
            beginrow(); 
              CreateProdDataWidget (PRODDATA_STRING7, -1, -1, align_hcenter, "", 20);
              CreateProdDataWidget (PRODDATA_STRING8, -1, -1, align_hcenter, "", 20);
              CreateProdDataWidget (PRODDATA_STRING9, -1, -1, align_hcenter, "", 20);
            endrow();

        endlayout();       

            
          createwidget (ID_STRETCH, WIDGET_TYPE_STRETCH); 
        endlayout();
      
      endlayout();
  enddraw();
}
 
/*------------------------------------------------------------------------- 
--  Procedure Name    : CreateWeighingDataPopupBox
--  Created by        : Jean-Pierre DorÃ©
--  Last modified on  : 2016/03/17
--  
--  Purpose           : Prod Data Popup window creation    
--                      
--  Value Parameters  :
--  Variable Params   : 
--  Side Effects      : 
--------------------------------------------------------------------------*/
void CreateWeighingDataPopupBox (void)         
{
 int width = 300,heigth = 27,font_wd = 16,i,j,between;
  begindraw();
    createwindow (WEIGHINGDATA_POPUP_WINDOW, WINDOW_TYPE_POPUP, "Popup Window");
    windowstyle (WEIGHINGDATA_POPUP_WINDOW, POPUP_OUTBOX_STYLE3);      
    
      beginlayout (LAYOUT_TYPE_VBOX,0);
      
        beginlayout (LAYOUT_TYPE_VBOX,0);
         //Info Text
         beginlayout(LAYOUT_TYPE_GRID, 0); // Grid Layout #1
            beginrow(); 
             createwidget (WEIGHINGDATA_POPUP, WIDGET_TYPE_TEXT_OUTPUT);
              widget_size_policy    (WEIGHINGDATA_POPUP,  SIZE_POLICY_MINIMUM, SIZE_POLICY_MINIMUM);
              widget_style          (WEIGHINGDATA_POPUP,  WEIGHINGDATA_STYLE); 
              widget_fontsize       (WEIGHINGDATA_POPUP,  20); 
              widget_foreground     (WEIGHINGDATA_POPUP, CL_PT_BLUE ); 
              widget_text_alignment (WEIGHINGDATA_POPUP,  WIDGET_TEXT_ALIGN_HCENTER);
              widget_text           (WEIGHINGDATA_POPUP, "Weighing Data");
            endrow();  
                             
        endlayout();


        beginlayout(LAYOUT_TYPE_HBOX, STD_EDGE_DISTANCE_NAVIG, FCT_BUTTON_DISTANCE_NAVIG);
 
         beginlayout(LAYOUT_TYPE_GRID, 0,0); // Grid Layout #1
            beginrow();
              CreateProdDataWidget (WEIGHINGDATA_TITLE_1+j, width, heigth, align_left, concat("Bulk",space(tab-1),"Dribble",space(tab-2),"Weight",space(tab+2),"Time"),font_wd);
            endrow();  
            
            for(i=0;i<10;i++)
            {
             beginrow();
               CreateProdDataWidget(WEIGHINGDATA_STRING1_1+i, width, heigth, align_left, concat("0.00s",space(tab),"0.00s",space(tab),"0.00kg",space(tab),"00:00:00"), font_wd);
             endrow();
            }  
            
        endlayout();       

            
          createwidget (ID_STRETCH, WIDGET_TYPE_STRETCH); 
        endlayout();
      
      endlayout();
  enddraw();
}
  