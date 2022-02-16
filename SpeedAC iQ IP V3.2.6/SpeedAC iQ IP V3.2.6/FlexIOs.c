﻿/*------------------------------------------------------------------------- 
--  Procedure Name    : CreateFlexIOPage1
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/05
--  
--  Purpose           : Creation of Flexible IOs page #1   
--                    : 
--  Value Parameters  :
--  Variable Params   : none
                      :  
--  Side Effects      : 
--------------------------------------------------------------------------*/
void CreateFlexIOPage1(void) 
{
  begindraw();
  createpage(PAGE_FLEXIO_1);  
  page_background (PAGE_FLEXIO_1, BackgroundColor);
  
  beginlayout(LAYOUT_TYPE_VBOX, 0); // VBOX #1

beginlayout(LAYOUT_TYPE_VBOX, 0); //Test Layout #1 

    beginlayout(LAYOUT_TYPE_HBOX, 0); // HBOX #2    // 
   
      beginlayout(LAYOUT_TYPE_VBOX, 0); // VBOX #3  // 

       beginlayout(LAYOUT_TYPE_HBOX, 0); // HBOX #5 Header
           CreatePTLogoHeader();
           CreateHeader (FLEX_SEARCH_ID, WD_PAGE_HEADER, HT_PAGE_HEADER, "", align_hcenter, concat (space(1), lsub(TX_FLEXIO_PAGE), space(1)), FT_MEDIUM_SIZE, widget_unlocked);

           beginlayout(LAYOUT_TYPE_HBOX, 0);  //HBOX #5   
              //Fault and Mode display
              CreateModeFltDisplay();
           endlayout();  // End layout of HBOX #5
         setlayoutoption (LAYOUT_OPTION_CONTENT_MARGINS, "0,1,0,0"); //"left,top,right,bottom"
        endlayout(); // Header 

        beginlayout(LAYOUT_TYPE_HBOX, 0); // HBOX #6
       
          //  First column on the left
          beginlayout(LAYOUT_TYPE_GRID, 0,3); // Grid Layout #1
            beginrow(); // First row with two columns 
              CreatePromptField (FLEX_ROW5_UNIT, CL_PT_BLUE, true, concat (lsub(TX_OUTPUT), space(1),"1", space(1), lsub(TX_ON)), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked );
            endrow();
            
            beginrow(); // Second row with two columns
              CreatePromptField (FLEX_ROW1_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXIOTYPE), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW1_SELECT, FT_STANDARD_SIZE, FT_RTC_BOLD,         lsub(TX_INPUT), lsub(TX_OUTPUT), lsub(TX_FLEXSETPOINT), "", "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow();
                     
            beginrow(); // Third row with three columns
              CreatePromptField (FLEX_ROW2_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXSETPOINT), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
               beginlayout(LAYOUT_TYPE_HBOX, 0);
                beginrow();
                  CreateComboBoxField (FLEX_ROW2_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD, lsub(TX_LES), lsub(TX_GRT), "", "", "", WD_FLEXIO_SIGNBOX, HT_FLEXIO_BOX, widget_locked );
                  CreateComboBoxField (FLEX_ROW3_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD, lsub(TX_FLEXWPSP1), lsub(TX_FLEXWPSP2), lsub(TX_FLEXMPSP1), lsub(TX_FLEXMPSP1), "", WD_FLEXIO_SIGNBOX2, HT_FLEXIO_BOX, widget_locked );               
                endrow();
               endlayout(); 
            endrow();

            beginrow(); // Fourth row with two columns
              CreatePromptField (FLEX_ROW4_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXIO), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateLanguageListField (FLEX_ROW4_INPUT, FT_RTC_BOLD, WIDGET_TEXT_ALIGN_CENTER,                                                 "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked);  
            endrow();

            beginrow(); // Fifth row with two columns
              CreatePromptField (FLEX_ROW5_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXSWITCH), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked); 
              CreateComboBoxField (FLEX_ROW5_SELECT , FT_STANDARD_SIZE, FT_RTC_BOLD,   lsub(TX_FLEXOFF), lsub(TX_FLEXON), "", "", "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow();

            beginrow(); // Sixth row with two columns
              CreatePromptField (FLEX_ROW6_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXTIMER), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW6_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD, lsub(TX_NONE), lsub(TX_FLEXWPT1), lsub(TX_FLEXWPT2), lsub(TX_FLEXMPT1), lsub(TX_FLEXMPT2), WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );     
            endrow();
                   
          endlayout();  //End of Grid Layout #1
          
        // Second Column  
           
          beginlayout(LAYOUT_TYPE_GRID, 0,3); // Grid Layout #2
            beginrow(); // First row with two columns 
              CreatePromptField (FLEX_ROW11_UNIT,    CL_PT_BLUE, true,      concat (lsub(TX_OUTPUT), space(1),"1", space(1),lsub(TX_OFF)), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked );
            endrow();
            
            beginrow(); // Second row with two columns
              CreatePromptField (FLEX_ROW7_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXIOTYPE), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW7_SELECT, FT_STANDARD_SIZE, FT_RTC_BOLD,         lsub(TX_INPUT), lsub(TX_OUTPUT), lsub(TX_FLEXSETPOINT), "", "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow();  
                     
            beginrow(); // Third row with three columns
              CreatePromptField (FLEX_ROW8_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXSETPOINT), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, 0, widget_locked);
               beginlayout(LAYOUT_TYPE_HBOX, 0);
                beginrow();
                  CreateComboBoxField (FLEX_ROW8_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD,    lsub(TX_LES), lsub(TX_GRT), "", "", "", WD_FLEXIO_SIGNBOX, HT_FLEXIO_BOX, widget_locked );
                  CreateComboBoxField (FLEX_ROW9_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD,    lsub(TX_FLEXWPSP1), lsub(TX_FLEXWPSP2), lsub(TX_FLEXMPSP1), lsub(TX_FLEXMPSP1), "", WD_FLEXIO_SIGNBOX2, HT_FLEXIO_BOX, widget_locked );
                endrow();
               endlayout();  
            endrow();

            beginrow(); // Fourth row with two columns
              CreatePromptField (FLEX_ROW10_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXIO), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateLanguageListField (FLEX_ROW10_INPUT, FT_RTC_BOLD, WIDGET_TEXT_ALIGN_CENTER,                                                 "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked);
            endrow();

            beginrow(); // Fifth row with two columns
              CreatePromptField (FLEX_ROW11_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXSWITCH), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW11_SELECT , FT_STANDARD_SIZE, FT_RTC_BOLD,        lsub(TX_FLEXOFF), lsub(TX_FLEXON), "", "", "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow();

            beginrow(); // Sixth row with two columns
              CreatePromptField (FLEX_ROW12_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXTIMER), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW12_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD, lsub(TX_NONE), lsub(TX_FLEXWPT1), lsub(TX_FLEXWPT2), lsub(TX_FLEXMPT1), lsub(TX_FLEXMPT2), WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked ); 
            endrow();
           setlayoutoption (LAYOUT_OPTION_CONTENT_MARGINS, "0,0,2,0"); //"left,top,right,bottom"        
          endlayout();  //End of Grid Layout #2         
       
        endlayout(); // End of HBOX #6   
        
     endlayout(); // End of VBOX #3 

   
   endlayout();  // End layout of HBOX #2
   
endlayout();  // End layout of Test Layout #1

   createwidget (0, WIDGET_TYPE_STRETCH);
  
   CreateNavigButtons (10, NAV_FCT_BUTTON_1, false);
   DrawNavButtons (SCREEN_FLEXIO_1, true, BTN_AUTO, BTN_RECIPE, BTN_REPORT, BTN_NAVIG, BTN_ALARM, BTN_TIMEDATE, BTN_NIL_BLUE, BTN_NIL_BLUE, BTN_NIL_BLUE, BTN_NEXT);     

  endlayout();  // End of VBOX #1
  enddraw();
}

/*------------------------------------------------------------------------- 
--  Procedure Name    : CreateFlexIOPage2
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/05
--  
--  Purpose           : Creation of Flexible IOs page #2   
--                    : 
--  Value Parameters  :
--  Variable Params   : none
                      :  
--  Side Effects      : 
--------------------------------------------------------------------------*/
void CreateFlexIOPage2(void) 
{
  begindraw();
  createpage(PAGE_FLEXIO_2);  
  page_background (PAGE_FLEXIO_2, BackgroundColor);
  
  beginlayout(LAYOUT_TYPE_VBOX, 0); // VBOX #1

beginlayout(LAYOUT_TYPE_VBOX, 0); //Test Layout #1 

    beginlayout(LAYOUT_TYPE_HBOX, 0); // HBOX #2    
   
      beginlayout(LAYOUT_TYPE_VBOX, 0); // VBOX #3  

       beginlayout(LAYOUT_TYPE_HBOX, 0); // HBOX #5 Header
           CreatePTLogoHeader();
           CreateHeader (FLEX_SEARCH_ID, WD_PAGE_HEADER, HT_PAGE_HEADER, "", align_hcenter, concat (space(1), lsub(TX_FLEXIO_PAGE), space(1)), FT_MEDIUM_SIZE, widget_unlocked);

           beginlayout(LAYOUT_TYPE_HBOX, 0);  //HBOX #5   
              //Fault and Mode display
              CreateModeFltDisplay();
           endlayout();  // End layout of HBOX #5
         setlayoutoption (LAYOUT_OPTION_CONTENT_MARGINS, "0,1,0,0"); //"left,top,right,bottom"
        endlayout(); // Header
      
        beginlayout(LAYOUT_TYPE_HBOX, 0); // HBOX #6
       
          //  First column on the left
          beginlayout(LAYOUT_TYPE_GRID, 0,3); // Grid Layout #1
            beginrow(); // First row with two columns 
              CreatePromptField (FLEX_ROW17_UNIT,    CL_PT_BLUE, true,       concat (lsub(TX_OUTPUT), space(1),"2", space(1),lsub(TX_ON)), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked );
            endrow();
            
            beginrow(); // Second row with two columns
              CreatePromptField (FLEX_ROW13_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXIOTYPE), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW13_SELECT, FT_STANDARD_SIZE, FT_RTC_BOLD,         lsub(TX_INPUT), lsub(TX_OUTPUT), lsub(TX_FLEXSETPOINT), "", "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow(); 
                     
            beginrow(); // Third row with three columns
              CreatePromptField (FLEX_ROW14_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXSETPOINT), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
               beginlayout(LAYOUT_TYPE_HBOX, 0);
                beginrow();
                  CreateComboBoxField (FLEX_ROW14_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD,  lsub(TX_LES), lsub(TX_GRT), "", "", "", WD_FLEXIO_SIGNBOX, HT_FLEXIO_BOX, widget_locked );
                  CreateComboBoxField (FLEX_ROW15_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD,  lsub(TX_FLEXWPSP1), lsub(TX_FLEXWPSP2), lsub(TX_FLEXMPSP1), lsub(TX_FLEXMPSP1), "", WD_FLEXIO_SIGNBOX2, HT_FLEXIO_BOX, widget_locked );
                endrow();
               endlayout(); 
            endrow();

            beginrow(); // Fourth row with two columns
              CreatePromptField (FLEX_ROW16_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXIO), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateLanguageListField (FLEX_ROW16_INPUT, FT_RTC_BOLD, WIDGET_TEXT_ALIGN_CENTER,                                                 "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked);
            endrow();

            beginrow(); // Fifth row with two columns
              CreatePromptField (FLEX_ROW17_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXSWITCH), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW17_SELECT , FT_STANDARD_SIZE, FT_RTC_BOLD,        lsub(TX_FLEXOFF), lsub(TX_FLEXON), "", "", "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow();

            beginrow(); // Sixth row with two columns
              CreatePromptField (FLEX_ROW18_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXTIMER), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW18_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD,   lsub(TX_NONE), lsub(TX_FLEXWPT1), lsub(TX_FLEXWPT2), lsub(TX_FLEXMPT1), lsub(TX_FLEXMPT2), WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow();
                   
          endlayout();  //End of Grid Layout #1
          
        // Second Column  
           
          beginlayout(LAYOUT_TYPE_GRID, 0,3); // Grid Layout #2
            beginrow(); // First row with two columns 
              CreatePromptField (FLEX_ROW23_UNIT,    CL_PT_BLUE, true,      concat (lsub(TX_OUTPUT), space(1),"2", space(1),lsub(TX_OFF)), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked );
            endrow();
            
            beginrow(); // Second row with two columns
              CreatePromptField (FLEX_ROW19_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXIOTYPE), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW19_SELECT, FT_STANDARD_SIZE, FT_RTC_BOLD,         lsub(TX_INPUT), lsub(TX_OUTPUT), lsub(TX_FLEXSETPOINT), "", "",WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow();
            
            beginrow(); // Third row with three columns
              CreatePromptField (FLEX_ROW20_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXSETPOINT), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
               beginlayout(LAYOUT_TYPE_HBOX, 0);
                beginrow();
                  CreateComboBoxField (FLEX_ROW20_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD,  lsub(TX_LES), lsub(TX_GRT), "", "", "", WD_FLEXIO_SIGNBOX, HT_FLEXIO_BOX, widget_locked );
                  CreateComboBoxField (FLEX_ROW21_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD,  lsub(TX_FLEXWPSP1), lsub(TX_FLEXWPSP2), lsub(TX_FLEXMPSP1), lsub(TX_FLEXMPSP1), "", WD_FLEXIO_SIGNBOX2, HT_FLEXIO_BOX, widget_locked );
                endrow();
               endlayout(); 
            endrow();

            beginrow(); // Fourth row with two columns
              CreatePromptField (FLEX_ROW22_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXIO), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              beginlayout(LAYOUT_TYPE_HBOX, 0);
                beginrow();
                  CreateLanguageListField (FLEX_ROW22_INPUT, FT_RTC_BOLD, WIDGET_TEXT_ALIGN_CENTER,                                             "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked);
                endrow();
               endlayout(); 
            endrow();

            beginrow(); // Fifth row with two columns
              CreatePromptField (FLEX_ROW23_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXSWITCH), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);                 
              CreateComboBoxField (FLEX_ROW23_SELECT , FT_STANDARD_SIZE, FT_RTC_BOLD,        lsub(TX_FLEXOFF), lsub(TX_FLEXON), "", "", "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow();

            beginrow(); // Sixth row with two columns
              CreatePromptField (FLEX_ROW24_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXTIMER), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW24_SELECT,  FT_STANDARD_SIZE, FT_RTC_BOLD,  lsub(TX_NONE), lsub(TX_FLEXWPT1), lsub(TX_FLEXWPT2), lsub(TX_FLEXMPT1), lsub(TX_FLEXMPT2), WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow();
                   
          endlayout();  //End of Grid Layout #2       
       
        endlayout(); // End of HBOX #6    
        
     endlayout(); // End of VBOX #3 

   
   endlayout();  // End layout of HBOX #2
   
endlayout();  // End layout of Test Layout #1

   createwidget (0, WIDGET_TYPE_STRETCH);
  
   CreateNavigButtons (10, NAV_FCT_BUTTON_1, false);
   DrawNavButtons (SCREEN_FLEXIO_2, true, BTN_AUTO, BTN_RECIPE, BTN_REPORT, BTN_NAVIG, BTN_ALARM, BTN_NIL_BLUE, BTN_NIL_BLUE, BTN_NIL_BLUE, BTN_PREV, BTN_NIL_BLUE);     

  endlayout();  // End of VBOX #1
  enddraw();
}

/*------------------------------------------------------------------------- 
--  Procedure Name    : CreateFlexIOPage3
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2017/03
--  
--  Purpose           : Creation of Flexible IOs page #3 Counter   
--                    : 
--  Value Parameters  :
--  Variable Params   : none
                      :  
--  Side Effects      : 
--------------------------------------------------------------------------*/
void CreateFlexIOPage3(void) 
{
  begindraw();
  createpage(PAGE_FLEXIO_3);  
  page_background (PAGE_FLEXIO_3, BackgroundColor);
  
  beginlayout(LAYOUT_TYPE_VBOX, 0); // VBOX #1

beginlayout(LAYOUT_TYPE_VBOX, 0); //Test Layout #1 

    beginlayout(LAYOUT_TYPE_HBOX, 0); // HBOX #2    
   
      beginlayout(LAYOUT_TYPE_VBOX, 0); // VBOX #3  


         beginlayout(LAYOUT_TYPE_HBOX, 0); // HBOX #5 Header
           CreatePTLogoHeader();
           CreateHeader (FLEX_SEARCH_ID, WD_PAGE_HEADER, HT_PAGE_HEADER, "", align_hcenter, concat (space(1), lsub(TX_FLEXIO_PAGE), space(1)), FT_MEDIUM_SIZE, widget_locked);

           beginlayout(LAYOUT_TYPE_HBOX, 0);  //HBOX #5   
              //Fault and Mode display
              CreateModeFltDisplay();
           endlayout();  // End layout of HBOX #5
          setlayoutoption (LAYOUT_OPTION_CONTENT_MARGINS, "0,1,0,0"); //"left,top,right,bottom"
         endlayout(); // Header
        

        beginlayout(LAYOUT_TYPE_HBOX, 0); // HBOX #6
            
            //  First column on the left
           beginlayout(LAYOUT_TYPE_GRID, 0,3); // Grid Layout #1
            beginrow(); // First row with two columns 
              CreatePromptField     (FLEX_ROW29_UNIT,    CL_PT_BLUE, true,                   lsub(TX_FLEXCONFIG), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
            endrow();
            
            beginrow(); // Second row with two columns
              CreatePromptField (FLEX_ROW25_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXCNTMODE), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW25_SELECT, FT_STANDARD_SIZE, FT_RTC_BOLD,         lsub(TX_FLEXCNTPRESET), lsub(TX_FLEXCNTPULSE), "", "", "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked);
            endrow(); 
                     
            beginrow(); // third row with two columns
              CreatePromptField (FLEX_ROW26_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXIOTYPE), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW26_SELECT, FT_STANDARD_SIZE, FT_RTC_BOLD,         lsub(TX_INPUT), lsub(TX_OUTPUT), "", "", "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked );
            endrow();

            beginrow(); // Fourth row with two columns
              CreatePromptField (FLEX_ROW27_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXIO), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateLanguageListField (FLEX_ROW27_INPUT, FT_RTC_BOLD, WIDGET_TEXT_ALIGN_CENTER,                                                 "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked);
            endrow();

            beginrow(); // Fifth row with two columns
              CreatePromptField (FLEX_ROW28_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXPRESOURCE), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateComboBoxField (FLEX_ROW28_SELECT , FT_STANDARD_SIZE, FT_RTC_BOLD,        lsub(TX_FLEXWPCOUNTER), lsub(TX_FLEXMPCOUNTER), "", "", "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked);
            endrow();
            
            beginrow(); // Sixth row with two columns 
              CreatePromptField     (FLEX_ROW29_ID,     CL_PT_BLUE, false,                  "", FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, Left_Margin, widget_locked);
              CreateOutputTextField (FLEX_ROW29_SELECT,                                     "", WD_FLEXIO_BOX, HT_FLEXIO_BOX, widget_locked);
            endrow(); 
                   
          endlayout();  //End of Grid Layout #1
          
        // Spacing between columns
//          CreatePromptField (RECIPE_SPACE1,    CL_PT_BLUE, false,                       "", FT_STANDARD_SIZE, WD_FLEX_SPACE, PT_6BOX_SIZE, No_Margin, widget_locked);

        // Second Column  
           
          beginlayout(LAYOUT_TYPE_GRID, 0,3); // Grid Layout #2
            beginrow(); // First row with two columns 
              CreatePromptField (FLEX_ROW35_UNIT,    CL_PT_BLUE, true,                       lsub(TX_FLEXTIMERS), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked );
            endrow();
            
            beginrow(); // Second row with two columns
              CreatePromptField (FLEX_ROW31_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXINITDELAY), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateInputField  (FLEX_ROW31_INPUT, FT_STANDARD_SIZE, FT_RTC_BOLD, INPUT_FORMAT_DECIMAL, 4, 2, false, lsub(TX_FLEXINITDELAY), WD_FLEXIOCNT_BOX, HT_FLEXIO_BOX, widget_locked );
              CreateUnitField   (FLEX_ROW31_UNIT,  FT_RTC_BOLD, FT_STANDARD_SIZE,            lsub(TX_SEC_UNIT), WD_FLEX_SECONDS, PT_6BOX_SIZE, widget_locked );
            endrow();
            
            beginrow(); // Third row with two columns
              CreatePromptField (FLEX_ROW32_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXONTIME), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateInputField  (FLEX_ROW32_INPUT, FT_STANDARD_SIZE, FT_RTC_BOLD, INPUT_FORMAT_DECIMAL, 4, 2, false, lsub(TX_FLEXONTIME), WD_FLEXIOCNT_BOX, HT_FLEXIO_BOX, widget_locked );
              CreateUnitField   (FLEX_ROW32_UNIT,  FT_RTC_BOLD, FT_STANDARD_SIZE,            lsub(TX_SEC_UNIT), WD_FLEX_SECONDS, PT_6BOX_SIZE, widget_locked );
            endrow();

            beginrow(); // Fourth row with two columns
              CreatePromptField (FLEX_ROW33_ID,    CL_PT_BLUE, false,                        lsub(TX_FLEXOFFTIME), FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateInputField  (FLEX_ROW33_INPUT, FT_STANDARD_SIZE, FT_RTC_BOLD, INPUT_FORMAT_DECIMAL, 4, 2, false, lsub(TX_FLEXOFFTIME), WD_FLEXIOCNT_BOX, HT_FLEXIO_BOX, widget_locked );
              CreateUnitField   (FLEX_ROW33_UNIT,  FT_RTC_BOLD, FT_STANDARD_SIZE,            lsub(TX_SEC_UNIT), WD_FLEX_SECONDS, PT_6BOX_SIZE, widget_locked );
            endrow();

            beginrow(); // Fifth row with two columns
              CreatePromptField     (FLEX_ROW35_ID,     CL_PT_BLUE, false,                  "", FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateOutputTextField (FLEX_ROW35_SELECT,                                     "", WD_FLEXIOCNT_BOX, HT_FLEXIO_BOX, widget_locked);
            endrow();

            beginrow(); // Sixth row with two columns
              CreatePromptField     (FLEX_ROW36_ID,     CL_PT_BLUE, false,                  "", FT_STANDARD_SIZE, WD_FLEXIO_DESCRIPTION, HT_FLEXIO_DESCRIPTION, No_Margin, widget_locked);
              CreateOutputTextField (FLEX_ROW36_SELECT,                                     "", WD_FLEXIOCNT_BOX, HT_FLEXIO_BOX, widget_locked);
            endrow();
                   
          endlayout();  //End of Grid Layout #2       
       
        endlayout(); // End of HBOX #6    
        
     endlayout(); // End of VBOX #3 

   
   endlayout();  // End layout of HBOX #2
   
endlayout();  // End layout of Test Layout #1

   createwidget (0, WIDGET_TYPE_STRETCH);
  
   CreateNavigButtons (10, NAV_FCT_BUTTON_1, false);
   DrawNavButtons (SCREEN_FLEXIO_3, true, BTN_AUTO, BTN_RECIPE, BTN_REPORT, BTN_NAVIG, BTN_ALARM, BTN_NIL_BLUE, BTN_NIL_BLUE, BTN_NIL_BLUE, BTN_PREV, BTN_NIL_BLUE);     

  endlayout();  // End of VBOX #1
  enddraw();
}

/*------------------------------------------------------------------------- 
--  Procedure Name    : CreateEnabledIOsListPage
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/05
--  
--  Purpose           : Enabled IOs in IO Config page database creation 
--                    : 
--  Value Parameters  :
--  Variable Params   : none
                      :  
--  Side Effects      : 
--------------------------------------------------------------------------*/
void CreateEnabledIOsListPage(void) // Added by DORJ2 *** Lists the product types
{
  begindraw();
    createpage(PAGE_FLEXIO_DBASE_LIST);  
    beginlayout(LAYOUT_TYPE_VBOX, 0);  // VBox 1 separated in 3 parts: headline, simple weighing and button line
          
      createwidget (FLEX_DBASE_ID, WIDGET_TYPE_TEXT_OUTPUT);
        widget_background     (FLEX_DBASE_ID,   CL_PT_GRAY );
        widget_foreground     (FLEX_DBASE_ID,   CL_PT_WHITE);
        widget_fontsize       (FLEX_DBASE_ID,   FT_RECIPE_SIZE);
        widget_size_policy    (FLEX_DBASE_ID,   SIZE_POLICY_MINIMUMEXPANDING, SIZE_POLICY_MINIMUM);
        widget_text_alignment (FLEX_DBASE_ID,   WIDGET_TEXT_ALIGN_LEFT );
        widget_text           (FLEX_DBASE_ID,   concat(space(1), lsub(TX_FLEXIOSELECT), space(5), lsub(TX_PRESSHERE)) ); 
  
      createwidget (FLEX_ENABLED_IO_DBASE_LIST, WIDGET_TYPE_LIST);
        widget_fontsize    (FLEX_ENABLED_IO_DBASE_LIST, FT_RECIPE_SIZE);  
        
    endlayout(); // End VBox 1 layout
  enddraw();
}


/*------------------------------------------------------------------------- 
--  Procedure Name    : ShowAvailableIOList
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/05
--  
--  Purpose           : Enabled IOs database search display  
--                    : 
--  Value Parameters  :
--  Variable Params   : none
                      :  
--  Side Effects      : 
--------------------------------------------------------------------------*/
int ShowAvailableIOList(int button_no)
{
int     i=0,j, Index_No[36]=0, result ,ID_GENERIC_DBASE_LIST;
int     class, type, value,spacenbr;
string  args[4][255];

  SelectAndWaitPage(PAGE_FLEXIO_DBASE_LIST);
  widget_clear(FLEX_ENABLED_IO_DBASE_LIST);  // clear all list entrys
  if (!LangRefreshed[Current_Screen]) RefreshLanguage(Current_Screen);
  
  for (i=0; i<36; i++)
  {
    Index_No[i]=0;
  }
  i=0; j=0;
  IOdb.No=0;
  ID_GENERIC_DBASE_LIST=FLEX_ENABLED_IO_DBASE_LIST;
  for (i=0; i<=MaxArrayIODbase; i++)
  {
   spacenbr = 3;
   if(IO_No[i] > 9) spacenbr = 1;
   switch (button_no)
   {
    case FLEX_ROW4_INPUT:
                          if (FlexIO_Type[Flex_Out1][FlexOutput_ON] == Flex_Input)
                          {                           
                            if (IO_Input[i] && IO_Enable[i])
                            {
                              widget_text (ID_GENERIC_DBASE_LIST, concat(trim(IO_No[i]), ".", space(spacenbr),IO_Name[i], space(1), IO_Address[i]), j );
                              if(IO_No[i] == FlexIO_IOEnum[Flex_Out1][FlexOutput_ON])
                               {  
                                widget_set_index(ID_GENERIC_DBASE_LIST,j,0);
                                result = j;
                               }   
                              Index_No[j] = IO_No[i];
                              j++; 
                            }
                          }
                          else if (FlexIO_Type[Flex_Out1][FlexOutput_ON] == Flex_Output)
                               {
                                 if (!IO_Input[i] && IO_Enable[i])
                                 {
                                   widget_text (ID_GENERIC_DBASE_LIST, concat(trim(IO_No[i]), ".", space(spacenbr),IO_Name[i], space(1), IO_Address[i]), j );
                                   if(IO_No[i] == FlexIO_IOEnum[Flex_Out1][FlexOutput_ON])
                                    {
                                     widget_set_index(ID_GENERIC_DBASE_LIST,j,0);
                                     result = j;
                                    } 
                                   Index_No[j] = IO_No[i];
                                   j++;
                                 }  
                               }
                         break;
    case FLEX_ROW10_INPUT:
                          if (FlexIO_Type[Flex_Out1][FlexOutput_OFF] == Flex_Input)
                          {
                            if (IO_Input[i] && IO_Enable[i])
                            {
                              widget_text (ID_GENERIC_DBASE_LIST, concat(trim(IO_No[i]), ".", space(spacenbr),IO_Name[i], space(1), IO_Address[i]), j );
                              if(IO_No[i] == FlexIO_IOEnum[Flex_Out1][FlexOutput_OFF])
                               {
                                widget_set_index(ID_GENERIC_DBASE_LIST,j,0);
                                result = j;
                               }  
                              Index_No[j] = IO_No[i];
                              j++; 
                            }
                          }
                          else if (FlexIO_Type[Flex_Out1][FlexOutput_OFF] == Flex_Output)
                               {
                                 if (!IO_Input[i] && IO_Enable[i])
                                 {
                                   widget_text (ID_GENERIC_DBASE_LIST, concat(trim(IO_No[i]), ".", space(spacenbr),IO_Name[i], space(1), IO_Address[i]), j );
                                   if(IO_No[i] == FlexIO_IOEnum[Flex_Out1][FlexOutput_OFF])
                                    {
                                     widget_set_index(ID_GENERIC_DBASE_LIST,j,0);
                                     result = j;
                                    } 
                                   Index_No[j] = IO_No[i];
                                   j++;
                                 }  
                               }
                         break;
    case FLEX_ROW16_INPUT:
                          if (FlexIO_Type[Flex_Out2][FlexOutput_ON] == Flex_Input)
                          {
                            if (IO_Input[i] && IO_Enable[i])
                            {
                              widget_text (ID_GENERIC_DBASE_LIST, concat(trim(IO_No[i]), ".", space(spacenbr),IO_Name[i], space(1), IO_Address[i]), j );
                              if(IO_No[i] == FlexIO_IOEnum[Flex_Out2][FlexOutput_ON])
                               {
                                widget_set_index(ID_GENERIC_DBASE_LIST,j,0);
                                result = j;
                               }  
                              Index_No[j] = IO_No[i];
                              j++; 
                            }
                          }
                          else if (FlexIO_Type[Flex_Out2][FlexOutput_ON] == Flex_Output)
                               {
                                 if (!IO_Input[i] && IO_Enable[i])
                                 {
                                   widget_text (ID_GENERIC_DBASE_LIST, concat(trim(IO_No[i]), ".", space(spacenbr),IO_Name[i], space(1), IO_Address[i]), j );
                                   if(IO_No[i] == FlexIO_IOEnum[Flex_Out2][FlexOutput_ON])
                                    {
                                     widget_set_index(ID_GENERIC_DBASE_LIST,j,0);
                                     result = j;
                                    }  
                                   Index_No[j] = IO_No[i];
                                   j++;
                                 }  
                               }
                         break;
    case FLEX_ROW22_INPUT:
                          if (FlexIO_Type[Flex_Out2][FlexOutput_OFF] == Flex_Input)
                          {
                            if (IO_Input[i] && IO_Enable[i])
                            {
                              widget_text (ID_GENERIC_DBASE_LIST, concat(trim(IO_No[i]), ".", space(spacenbr),IO_Name[i], space(1), IO_Address[i]), j );
                              if(IO_No[i] == FlexIO_IOEnum[Flex_Out2][FlexOutput_OFF])
                               {
                                widget_set_index(ID_GENERIC_DBASE_LIST,j,0);
                                result = j;
                               }  
                              Index_No[j] = IO_No[i];
                              j++; 
                            }
                          }
                          else if (FlexIO_Type[Flex_Out2][FlexOutput_OFF] == Flex_Output)
                               {
                                 if (!IO_Input[i] && IO_Enable[i])
                                 {
                                   widget_text (ID_GENERIC_DBASE_LIST, concat(trim(IO_No[i]), ".", space(spacenbr),IO_Name[i], space(1), IO_Address[i]), j );
                                   if(IO_No[i] == FlexIO_IOEnum[Flex_Out2][FlexOutput_OFF])
                                    {
                                     widget_set_index(ID_GENERIC_DBASE_LIST,j,0);
                                     result = j;
                                    }  
                                   Index_No[j] = IO_No[i];
                                   j++;
                                 }  
                               }
                         break;  
    case FLEX_ROW27_INPUT:
                          if (FlexIO_Type[Flex_Out3][FlexOutput_ON] == Flex_Input)
                          {
                            if (IO_Input[i] && IO_Enable[i])
                            {
                              widget_text (ID_GENERIC_DBASE_LIST, concat(trim(IO_No[i]), ".", space(spacenbr),IO_Name[i], space(1), IO_Address[i]), j );
                              if(IO_No[i] == FlexIO_IOEnum[Flex_Out3][FlexOutput_ON])
                               {
                                widget_set_index(ID_GENERIC_DBASE_LIST,j,0);
                                result = j;
                               }  
                              Index_No[j] = IO_No[i];
                              j++; 
                            }
                          }
                          else if (FlexIO_Type[Flex_Out3][FlexOutput_ON] == Flex_Output)
                               {
                                 if (!IO_Input[i] && IO_Enable[i])
                                 {
                                   widget_text (ID_GENERIC_DBASE_LIST, concat(trim(IO_No[i]), ".", space(spacenbr),IO_Name[i], space(1), IO_Address[i]), j );
                                   if(IO_No[i] == FlexIO_IOEnum[Flex_Out3][FlexOutput_ON])
                                    {
                                     widget_set_index(ID_GENERIC_DBASE_LIST,j,0);
                                     result = j;
                                    }  
                                   Index_No[j] = IO_No[i];
                                   j++;
                                 }  
                               }
                         break;                                               
   }  
  }

  for(;;)
  {
   if(eventreceived())
   {
    readevent (class, type, value, args);
    if (class == EVENT_CLASS_APPLICATION &&
        (type == EVENT_TYPE_LIST_ITEM_SELECTED || type == EVENT_TYPE_BUTTON_PRESS))
     {
      if(type == EVENT_TYPE_LIST_ITEM_SELECTED) result = int(args[0]);
      return (Index_No[result]);
     }
   }
   else DisplayHandling();
  }  

 return (Index_No[result]);  
}

/*------------------------------------------------------------------------- 
--  Procedure Name    : RefreshFlexIOGrayOut
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/05
--  
--  Purpose           : Gray out management while refreshing page
--                      
--  Value Parameters  :
--  Variable Params   : Scrn_No = Active screen, MaxRows = # of rows to update,
--                    : pointer =  starting IO # (0 to 72)
--  Side Effects      : 
--------------------------------------------------------------------------*/
void RefreshFlexIOGrayOut(int Scrn_No, int page_no, int MaxRows, int pointer)
{
int i, j ;
TEST_ID[0]     = string(FLEX_ROW1_ID);
TEST_VALUE[0]  = string(FLEX_ROW1_INPUT);
TEST_SELECT[0] = string(FLEX_ROW1_SELECT);
TEST_UNITS[0]   = string(FLEX_ROW1_UNIT);
j=pointer;

switch (Scrn_No)
{
 case SCREEN_FLEXIO_1:

                   // Output 1 ON 
                     FlexIO_Grayout[1]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);
                     FlexIO_Grayout[2]=(FlexIO_Type[Flex_Out1][FlexOutput_ON] !=Flex_Setpoint  || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);  
                     FlexIO_Grayout[3]=(FlexIO_Type[Flex_Out1][FlexOutput_ON] !=Flex_Setpoint  || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);   
                     FlexIO_Grayout[4]=(FlexIO_Type[Flex_Out1][FlexOutput_ON] == Flex_Setpoint || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);
                     FlexIO_Grayout[5]=(FlexIO_Type[Flex_Out1][FlexOutput_ON] == Flex_Setpoint || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);
                     FlexIO_Grayout[6]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);
                     
                   // Output 1 OFF  
                     FlexIO_Grayout[7]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);
                     FlexIO_Grayout[8]= (FlexIO_Type[Flex_Out1][FlexOutput_OFF] !=Flex_Setpoint  || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);  
                     FlexIO_Grayout[9]= (FlexIO_Type[Flex_Out1][FlexOutput_OFF] !=Flex_Setpoint  || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);  
                     FlexIO_Grayout[10]=(FlexIO_Type[Flex_Out1][FlexOutput_OFF] == Flex_Setpoint || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);
                     FlexIO_Grayout[11]=(FlexIO_Type[Flex_Out1][FlexOutput_OFF] == Flex_Setpoint || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);
                     FlexIO_Grayout[12]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_1]);
                  break;
                  
 case SCREEN_FLEXIO_2:

                   // Output 2 ON 
                     FlexIO_Grayout[13]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);
                     FlexIO_Grayout[14]=(FlexIO_Type[Flex_Out2][FlexOutput_ON] !=Flex_Setpoint  || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);  
                     FlexIO_Grayout[15]=(FlexIO_Type[Flex_Out2][FlexOutput_ON] !=Flex_Setpoint  || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]); 
                     FlexIO_Grayout[16]=(FlexIO_Type[Flex_Out2][FlexOutput_ON] == Flex_Setpoint || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);
                     FlexIO_Grayout[17]=(FlexIO_Type[Flex_Out2][FlexOutput_ON] == Flex_Setpoint || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);
                     FlexIO_Grayout[18]=( mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);
                     
                   // Output 2 OFF  
                     FlexIO_Grayout[19]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);
                     FlexIO_Grayout[20]=(FlexIO_Type[Flex_Out2][FlexOutput_OFF] !=Flex_Setpoint  || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);  
                     FlexIO_Grayout[21]=(FlexIO_Type[Flex_Out2][FlexOutput_OFF] !=Flex_Setpoint  || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);  
                     FlexIO_Grayout[22]=(FlexIO_Type[Flex_Out2][FlexOutput_OFF] == Flex_Setpoint || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);
                     FlexIO_Grayout[23]=(FlexIO_Type[Flex_Out2][FlexOutput_OFF] == Flex_Setpoint || mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);
                     FlexIO_Grayout[24]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_2]);
                  break;  
                  
 case SCREEN_FLEXIO_3:

                   // 1st Column 
                     FlexIO_Grayout[25]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_3]);
                     FlexIO_Grayout[26]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_3]); 
                     FlexIO_Grayout[27]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_3]);
                     FlexIO_Grayout[28]=(mode_step != stp_OFF_MODE || !IO_Enable[O_FlexIO_3]);
                     
                   // 2nd Column
                     FlexIO_Grayout[31]=(!IO_Enable[O_FlexIO_3]);
                     FlexIO_Grayout[32]=(!IO_Enable[O_FlexIO_3]);
                     FlexIO_Grayout[33]=(FlexIO_CntMode[Flex_Out3][FlexOutput_ON] == Flex_Preset || !IO_Enable[O_FlexIO_3]);

                  break;                
}

 for (i=pointer; i<page_no; i++)
     {
 
      TEST_POINTER[i] = pointer+i;
      TEST_ID[i]      = TEST_ID[0]+i;
      TEST_VALUE[i]   = TEST_VALUE[0]+i;
      TEST_SELECT[i]  = TEST_SELECT[0]+i;
      TEST_UNITS[i]   = TEST_UNITS[0]+i;

     }

 for (i=pointer; i<pointer+MaxRows; i++)
     {
      widget_enable     (TEST_ID[j],     !FlexIO_Grayout[i+1]);
      widget_enable     (TEST_VALUE[j],  !FlexIO_Grayout[i+1]);
      widget_enable     (TEST_SELECT[j], !FlexIO_Grayout[i+1]);
                 
      j = j+1;
     }
} 



/*------------------------------------------------------------------------- 
--  Procedure Name    : RefreshFlexIOScreen
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/05
--  
--  Purpose           : Refresh FlexIO screen at first screen access or after 
--                    : keyboard input entry to update Lim function
--  Value Parameters  :
--  Variable Params   : Scrn_No = Active screen number
                      :  
--  Side Effects      : 
--------------------------------------------------------------------------*/
void RefreshFlexIOScreen(int Scrn_No)
{
 begindraw(); 
 


  switch ( Scrn_No )
  {
    case SCREEN_FLEXIO_1 :  
                    widget_text (FLEX_SEARCH_ID, concat(space(1), lsub(TX_FLEXIO_PAGE),space(5), "1" , space(1), TX_FSLASH, space(1), "3") );
                
                  // Output 1 ON                                
                    widget_set_index (FLEX_ROW1_SELECT, FlexIO_Type[Flex_Out1][FlexOutput_ON],0);
                    widget_set_index (FLEX_ROW2_SELECT, FlexIO_SPSign[Flex_Out1][FlexOutput_ON],0);
                    widget_set_index (FLEX_ROW3_SELECT, FlexIO_SP[Flex_Out1][FlexOutput_ON],0);                 

                    if ((FlexIO_Type[Flex_Out1][FlexOutput_ON]==Flex_Input && FlexIO_IOEnum[Flex_Out1][FlexOutput_ON] < 37 ) || (FlexIO_Type[Flex_Out1][FlexOutput_ON]==Flex_Output && FlexIO_IOEnum[Flex_Out1][FlexOutput_ON] >= 37 ))
                    {
                      if ( (length (IO_Name[FlexIO_IOEnum[Flex_Out1][FlexOutput_ON]])) > LISTTEXTLENGTH) widget_fontsize (FLEX_ROW4_INPUT,  FT_FLEX_OVERSIZE);
                      else widget_fontsize (FLEX_ROW4_INPUT,  FT_STANDARD_SIZE);
                      widget_text       (FLEX_ROW4_INPUT,  IO_Name[FlexIO_IOEnum[Flex_Out1][FlexOutput_ON]]);
                    }                 
                    else widget_text      (FLEX_ROW4_INPUT,  ""); 
  
                    widget_set_index (FLEX_ROW5_SELECT, FlexIO_IoSwitch[Flex_Out1][FlexOutput_ON],0);
                    widget_set_index (FLEX_ROW6_SELECT, FlexIO_Timer[Flex_Out1][FlexOutput_ON],0);
                   
                  // Output 1 OFF
                    widget_set_index (FLEX_ROW7_SELECT, FlexIO_Type[Flex_Out1][FlexOutput_OFF],0);
                    widget_set_index (FLEX_ROW8_SELECT, FlexIO_SPSign[Flex_Out1][FlexOutput_OFF],0);
                    widget_set_index (FLEX_ROW9_SELECT, FlexIO_SP[Flex_Out1][FlexOutput_OFF],0);
                    
                    if ((FlexIO_Type[Flex_Out1][FlexOutput_OFF]==Flex_Input && FlexIO_IOEnum[Flex_Out1][FlexOutput_OFF] < 37 ) || (FlexIO_Type[Flex_Out1][FlexOutput_OFF]==Flex_Output && FlexIO_IOEnum[Flex_Out1][FlexOutput_OFF] >= 37 ))
                    {                      
                      if ( (length (IO_Name[FlexIO_IOEnum[Flex_Out1][FlexOutput_OFF]])) > LISTTEXTLENGTH) widget_fontsize (FLEX_ROW10_INPUT,  FT_FLEX_OVERSIZE);
                      else widget_fontsize (FLEX_ROW10_INPUT,  FT_STANDARD_SIZE);
                      widget_text      (FLEX_ROW10_INPUT,  IO_Name[FlexIO_IOEnum[Flex_Out1][FlexOutput_OFF]]);
                    }                 
                    else widget_text      (FLEX_ROW10_INPUT,  "");  
                    
                    widget_set_index (FLEX_ROW11_SELECT,FlexIO_IoSwitch[Flex_Out1][FlexOutput_OFF],0);
                    widget_set_index (FLEX_ROW12_SELECT,FlexIO_Timer[Flex_Out1][FlexOutput_OFF],0);                    
                    
                    RefreshFlexIOGrayOut(SCREEN_FLEXIO_1, MX_PAGE1, 12, 0);                                                                                                                                    
                  break;
                         
                         
    case SCREEN_FLEXIO_2 :    
                    widget_text (FLEX_SEARCH_ID, concat(space(1), lsub(TX_FLEXIO_PAGE),space(5), "2" , space(1), TX_FSLASH, space(1), "3") );
                  // Output 2 ON                                
                    widget_set_index (FLEX_ROW13_SELECT, FlexIO_Type[Flex_Out2][FlexOutput_ON],0);
                    widget_set_index (FLEX_ROW14_SELECT, FlexIO_SPSign[Flex_Out2][FlexOutput_ON],0);
                    widget_set_index (FLEX_ROW15_SELECT, FlexIO_SP[Flex_Out2][FlexOutput_ON],0);
                    
                    if ((FlexIO_Type[Flex_Out2][FlexOutput_ON]==Flex_Input && FlexIO_IOEnum[Flex_Out2][FlexOutput_ON] < 37 ) || (FlexIO_Type[Flex_Out2][FlexOutput_ON]==Flex_Output && FlexIO_IOEnum[Flex_Out2][FlexOutput_ON] >= 37 ))
                    {
                      if ( (length (IO_Name[FlexIO_IOEnum[Flex_Out2][FlexOutput_ON]])) > LISTTEXTLENGTH) widget_fontsize (FLEX_ROW16_INPUT,  FT_FLEX_OVERSIZE);
                      else widget_fontsize (FLEX_ROW16_INPUT,  FT_STANDARD_SIZE);
                      widget_text      (FLEX_ROW16_INPUT,  IO_Name[FlexIO_IOEnum[Flex_Out2][FlexOutput_ON]]);
                    }                 
                    else widget_text      (FLEX_ROW16_INPUT,  ""); 
                    
                    widget_set_index (FLEX_ROW17_SELECT, FlexIO_IoSwitch[Flex_Out2][FlexOutput_ON],0);
                    widget_set_index (FLEX_ROW18_SELECT, FlexIO_Timer[Flex_Out2][FlexOutput_ON],0);  
                    
                 // Output 2 OFF
                    widget_set_index (FLEX_ROW19_SELECT, FlexIO_Type[Flex_Out2][FlexOutput_OFF],0);
                    widget_set_index (FLEX_ROW20_SELECT, FlexIO_SPSign[Flex_Out2][FlexOutput_OFF],0);
                    widget_set_index (FLEX_ROW21_SELECT, FlexIO_SP[Flex_Out2][FlexOutput_OFF],0);
                    
                    if ((FlexIO_Type[Flex_Out2][FlexOutput_OFF]==Flex_Input && FlexIO_IOEnum[Flex_Out2][FlexOutput_OFF] < 37 ) || (FlexIO_Type[Flex_Out2][FlexOutput_OFF]==Flex_Output && FlexIO_IOEnum[Flex_Out2][FlexOutput_OFF] >= 37 ))
                    {
                      if ( (length (IO_Name[FlexIO_IOEnum[Flex_Out2][FlexOutput_OFF]])) > LISTTEXTLENGTH) widget_fontsize (FLEX_ROW22_INPUT,  FT_FLEX_OVERSIZE);
                      else widget_fontsize (FLEX_ROW22_INPUT,  FT_STANDARD_SIZE);
                      widget_text      (FLEX_ROW22_INPUT,  IO_Name[FlexIO_IOEnum[Flex_Out2][FlexOutput_OFF]]);
                    }                 
                    else widget_text      (FLEX_ROW22_INPUT,  "");  
                    
                    widget_set_index (FLEX_ROW23_SELECT, FlexIO_IoSwitch[Flex_Out2][FlexOutput_OFF],0); 
                    widget_set_index (FLEX_ROW24_SELECT, FlexIO_Timer[Flex_Out2][FlexOutput_OFF],0);  
        
                    
                    RefreshFlexIOGrayOut(SCREEN_FLEXIO_2, MX_PAGE2, 12, 12);                    
                     
                   break;

    case SCREEN_FLEXIO_3 :    
                    widget_text (FLEX_SEARCH_ID, concat(space(1), lsub(TX_FLEXIO_PAGE),space(5), "3" , space(1), TX_FSLASH, space(1), "3") );
                  // Output 3 ON                                
                    widget_set_index (FLEX_ROW25_SELECT, FlexIO_CntMode[Flex_Out3][FlexOutput_ON],0);
                    widget_set_index (FLEX_ROW26_SELECT, FlexIO_Type[Flex_Out3][FlexOutput_ON],0);
                    
                    if ((FlexIO_Type[Flex_Out3][FlexOutput_ON]==Flex_Input && FlexIO_IOEnum[Flex_Out3][FlexOutput_ON] < 37 ) || (FlexIO_Type[Flex_Out3][FlexOutput_ON]==Flex_Output && FlexIO_IOEnum[Flex_Out3][FlexOutput_ON] >= 37 ))
                    {
                      if ( (length (IO_Name[FlexIO_IOEnum[Flex_Out3][FlexOutput_ON]])) > LISTTEXTLENGTH) widget_fontsize (FLEX_ROW27_INPUT,  FT_FLEX_OVERSIZE);
                      else widget_fontsize (FLEX_ROW27_INPUT,  FT_STANDARD_SIZE);
                      widget_text      (FLEX_ROW27_INPUT,  IO_Name[FlexIO_IOEnum[Flex_Out3][FlexOutput_ON]]);
                    }                 
                    else widget_text      (FLEX_ROW27_INPUT,  ""); 
                    
                    widget_set_index (FLEX_ROW28_SELECT, FlexIO_CntPreSource[Flex_Out3][FlexOutput_ON],0);
                    
                 // Output 3 OFF
                    widget_text (FLEX_ROW31_INPUT, FlexIO.InitDelay); 
                    widget_text (FLEX_ROW32_INPUT, FlexIO.OnTime);
                    widget_text (FLEX_ROW33_INPUT, FlexIO.OffTime); 
                    
                    RefreshFlexIOGrayOut(SCREEN_FLEXIO_3, MX_PAGE3, 12, 24);                    
                     
                   break;
                                      
  }

 enddraw();           
}


/*------------------------------------------------------------------------- 
--  Procedure Name    : RefreshFlexIOListEntry
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/05
--  
--  Purpose           : Refresh List entry to FlexIO buffer
--                      
--  Value Parameters  :
--  Variable Params   : 
                      :  
--  Side Effects      : 
--------------------------------------------------------------------------*/
void RefreshFlexIOListEntry(int Scrn_No, int value, float Argument) 
{
int err;
find_db (FlexIO_Db);


  err = find(IOdb);
 
  switch (Scrn_No)
  {  
    case SCREEN_FLEXIO_1 :  
                   if (IOdb.No != 9999)
                   {
                     switch (value)
                     {      
                     // Page 1 of 3
                        case FLEX_ROW4_INPUT :   FlexIO.IoEnumOn = IOdb.No;
                                                 FlexIO.IoNameOn = IO_Name[IOdb.No]; 
                                                 FlexIO.No = 1; 
                                              break;
                        case FLEX_ROW10_INPUT :  FlexIO.IoEnumOff = IOdb.No;
                                                 FlexIO.IoNameOff = IO_Name[IOdb.No];
                                                 FlexIO.No = 1;
                                              break;                      
      
                     }
                   }  
                   SelectAndWaitPage(PAGE_FLEXIO_1);                            
                   Current_Screen = SCREEN_FLEXIO_1;              
                 break;  

    case SCREEN_FLEXIO_2 :  
                   if (IOdb.No != 9999)
                   {
                     switch (value)
                     {
                     // Page 2 of 3                         
                        case FLEX_ROW16_INPUT :  FlexIO.IoEnumOn = IOdb.No;
                                                 FlexIO.IoNameOn = IO_Name[IOdb.No];
                                                 FlexIO.No = 2;
                                              break;
                        case FLEX_ROW22_INPUT :  FlexIO.IoEnumOff = IOdb.No;
                                                 FlexIO.IoNameOff = IO_Name[IOdb.No];
                                                 FlexIO.No = 2;
                                              break;        
   
                     }
                   } 
                   SelectAndWaitPage(PAGE_FLEXIO_2);                            
                   Current_Screen = SCREEN_FLEXIO_2;                                                                                                                                    
                 break;
                 
    case SCREEN_FLEXIO_3 :  
                   if (IOdb.No != 9999)
                   {
                     switch (value)
                     {
                     // Page 3 of 3                         
                        case FLEX_ROW27_INPUT :  FlexIO.IoEnumOn = IOdb.No;
                                                 FlexIO.IoNameOn = IO_Name[IOdb.No];
                                                 FlexIO.No = 3;
                                              break;        
   
                     }
                   } 
                   SelectAndWaitPage(PAGE_FLEXIO_3);                            
                   Current_Screen = SCREEN_FLEXIO_3;                                                                                                                                    
                 break;  
  }

}


/*------------------------------------------------------------------------- 
--  Procedure Name    : RefreshFlexIOInputEntry
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/05
--  
--  Purpose           : Refresh Input box entry to FlexIO buffer
--                      
--  Value Parameters  :
--  Variable Params   : 
                      :  
--  Side Effects      : 
--------------------------------------------------------------------------*/
void RefreshFlexIOInputEntry(int Scrn_No, int value, string Argument) 
{
int err;
find_db (FlexIO_Db);

 begindraw();
 
  switch (Scrn_No)
  {  
                
    case SCREEN_FLEXIO_3 :  
                   switch (value)
                   {
                   // Page 3 of 3                         
                      case FLEX_ROW31_INPUT :  FlexIO.InitDelay = decimal (Lim(0,9.99,Argument));          

                                            break;
                      case FLEX_ROW32_INPUT :  FlexIO.OnTime = decimal (Lim(0,9.99,Argument));          

                                            break;   
                      case FLEX_ROW33_INPUT :  FlexIO.OffTime = decimal (Lim(0,9.99,Argument));          

                                            break;     
 
                   }                                                                                                                                     
                 break;                
  }
 enddraw();
}

/*------------------------------------------------------------------------- 
--  Procedure Name    : RefreshFlexIOComboBoxEntry
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/05
--  
--  Purpose           : Refresh ComboBox box entry to FlexIO buffer
--                      
--  Value Parameters  :
--  Variable Params   : value = readevent entered value, Argument = Argument value from readevent 
                      :  
--  Side Effects      : 
--------------------------------------------------------------------------*/
void RefreshFlexIOComboBoxEntry(int Scrn_No, int value, string Argument)
{

find_db (FlexIO_Db);

 begindraw();

  switch (Scrn_No)
  {  
    case SCREEN_FLEXIO_1 :  
                   switch (value)
                   {      
                      //Output 1 ON
                      case FLEX_ROW1_SELECT :  FlexIO.TypeOn = int (Argument);
                                              break; 
                      case FLEX_ROW2_SELECT :  FlexIO.SPSignOn = Argument;
                                              break;  
                      case FLEX_ROW3_SELECT :  FlexIO.SPOn   = int (Argument);
                                              break;
                      case FLEX_ROW5_SELECT :  FlexIO.IoSwOn  = int (Argument);
                                              break;
                      case FLEX_ROW6_SELECT :  FlexIO.TOn    = int (Argument);
                                              break;    
                      //Output 1 OFF
                      case FLEX_ROW7_SELECT :  FlexIO.TypeOff = int (Argument);
                                              break; 
                      case FLEX_ROW8_SELECT :  FlexIO.SPSignOff = Argument;
                                              break;  
                      case FLEX_ROW9_SELECT :  FlexIO.SPOff   = int (Argument);
                                              break;
                      case FLEX_ROW11_SELECT : FlexIO.IoSwOff  = int (Argument);
                                              break;
                      case FLEX_ROW12_SELECT : FlexIO.TOff    = int (Argument);
                                              break;                                                                                                                                        
                   }
                  break; 
                  
    case SCREEN_FLEXIO_2 :  
                   switch (value)
                   {      
                      //Output 2 ON
                      case FLEX_ROW13_SELECT :  FlexIO.TypeOn = int (Argument);
                                              break; 
                      case FLEX_ROW14_SELECT :  FlexIO.SPSignOn = Argument;
                                              break;  
                      case FLEX_ROW15_SELECT :  FlexIO.SPOn   = int (Argument);
                                              break;
                      case FLEX_ROW17_SELECT :  FlexIO.IoSwOn  = int (Argument);
                                              break;
                      case FLEX_ROW18_SELECT :  FlexIO.TOn    = int (Argument);
                                              break;    
                      //Output 2 OFF
                      case FLEX_ROW19_SELECT :  FlexIO.TypeOff = int (Argument);
                                              break; 
                      case FLEX_ROW20_SELECT :  FlexIO.SPSignOff = Argument;
                                              break;  
                      case FLEX_ROW21_SELECT :  FlexIO.SPOff   = int (Argument);
                                              break;
                      case FLEX_ROW23_SELECT : FlexIO.IoSwOff  = int (Argument);
                                              break;
                      case FLEX_ROW24_SELECT : FlexIO.TOff    = int (Argument);
                                              break;   
                       
                   }
                 break;  

    case SCREEN_FLEXIO_3 :  
                   switch (value)
                   {      
                      //Output 2 ON
                      case FLEX_ROW25_SELECT :  FlexIO.CntMode    = int (Argument);
                                              break; 
                      case FLEX_ROW26_SELECT :  FlexIO.TypeOn     = int (Argument);
                                              break;  
                      case FLEX_ROW28_SELECT :  FlexIO.CntPreSource  = int (Argument);
                                              break;
   
                      //Output 2 OFF
                      case FLEX_ROW31_SELECT :  FlexIO.TypeOff = int (Argument);
                                              break; 
                      case FLEX_ROW32_SELECT :  FlexIO.SPSignOff = Argument;
                                              break;  
                      case FLEX_ROW33_SELECT :  FlexIO.SPOff   = int (Argument);
                                              break;  
                       
                   }
                 break; 
  }
 enddraw();
} 


/*------------------------------------------------------------------------- 
--  Procedure Name    : CreateFlexIOPages
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/05
--  
--  Purpose           : Create Flexible IOs Pages Manager 
--                      
--  Value Parameters  :
--  Variable Params   : none 
--  Side Effects      : 
--------------------------------------------------------------------------*/
void CreateFlexIOPages(void) 
{
    CreateEnabledIOsListPage();
    CreateFlexIOPage1();
    CreateFlexIOPage2();
    CreateFlexIOPage3();
}

/*------------------------------------------------------------------------- 
--  Procedure Name    : Reset_FlexIO
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2017/03
--  
--  Purpose           : Reset Flex IO Test Flag to escape logic loop 
--                      
--  Value Parameters  :
--  Variable Params   : none 
--  Side Effects      : 
--------------------------------------------------------------------------*/
void Reset_FlexIO (void)
{
int i,j;

  for (i=0; i<MAX_FLEXIO; i++)
  {
    for (j=0; j<Flex_Out3; j++)
    {
      FlexIO_TestOnFlag[i][j] = OFF;
      FlexIO_SetOnFlag[i][j] = OFF;
    }  
  }
}
/*------------------------------------------------------------------------- 
--  Procedure Name    : TON_Test
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/06
--  
--  Purpose           : Tests if Timer check is valid for the condition
--                      
--  Value Parameters  :
--  Variable Params   : none 
--  Side Effects      : 
--------------------------------------------------------------------------*/
bool TON_Test (int test, int i, int j, int k)
{
  switch (test)
  {
    case Flex_T_EN:  // Test if T_EN !NOT enabled
            if (!T_EN[T_FlexOut1Off+k] || T_PRE[T_FlexOut1Off+k]==0 || FlexIO_Timer[i][j] == 0)
            return (true);
            else return (false);
           break;
    case Flex_T_Dn: // Test if T_Dn Enabled
            if (T_Dn(T_FlexOut1Off+k) || T_PRE[T_FlexOut1Off+k]==0 || FlexIO_Timer[i][j] == 0)
            return (true);
            else return (false);
           break; 
  }
}

/*------------------------------------------------------------------------- 
--  Procedure Name    : Flex_SetpointTest
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/06
--  
--  Purpose           : Tests if setpoint check is valid for the condition
--                      
--  Value Parameters  :
--  Variable Params   : none 
--  Side Effects      : 
--------------------------------------------------------------------------*/

bool Flex_SetpointTest (int i, int j)
{
  
  if (FlexIO_SPSign[i][j])
  {
    if (NetWeight[Scale1] >= FlexIO_SP_Pre[i][j])
    {
    FlexIO_TestOnFlag[i][j] = ON;
    return (true);
    }
    else if (NetWeight[Scale1] < FlexIO_SP_Pre[i][j] && FlexIO_SetOnFlag[i][j]) 
    {FlexIO_TestOnFlag[i][FlexOutput_ON] = OFF; FlexIO_SetOnFlag[i][ON] = OFF;}
    
  }
  else if (!FlexIO_SPSign[i][j])
       {
         if (NetWeight[Scale1] <= FlexIO_SP_Pre[i][j])
         {
         FlexIO_TestOnFlag[i][FlexOutput_ON] = ON;
         return (true);
         }
         else if (NetWeight[Scale1] > FlexIO_SP_Pre[i][j] && FlexIO_SetOnFlag[i][j])
         {FlexIO_TestOnFlag[i][FlexOutput_ON] = OFF; FlexIO_SetOnFlag[i][ON] = OFF;}
       }
  return (false);
}

/*------------------------------------------------------------------------- 
--  Procedure Name    : Flex_IOTest
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/06
--  
--  Purpose           : Tests if IO test is valid for the condition
--                      
--  Value Parameters  :
--  Variable Params   : none 
--  Side Effects      : 
--------------------------------------------------------------------------*/
bool Flex_IOTest (int i, int j, int k)
{
  if (FlexIO_IoSwitch[i][j])
  {
    if (Input_State(FlexIO_IOEnum[i][j]))
    {
      if (TON_Test(Flex_T_Dn, i,j,k)) 
      {
        FlexIO_TestOnFlag[i][j] = ON;
      }  
     return (true);  
    }
    else if (!Input_State(FlexIO_IOEnum[i][j])&& FlexIO_SetOnFlag[i][j]) 
    {FlexIO_TestOnFlag[i][FlexOutput_ON] = OFF; FlexIO_SetOnFlag[i][FlexOutput_ON] = OFF;}
    
  }
  else if (!FlexIO_IoSwitch[i][j])
       {
         if (!Input_State(FlexIO_IOEnum[i][j]))
         {
         if (TON_Test(Flex_T_Dn, i,j,k)) FlexIO_TestOnFlag[i][FlexOutput_ON] = ON;
         return (true);
         }
         else if (Input_State(FlexIO_IOEnum[i][j]) && FlexIO_SetOnFlag[i][j])
         {FlexIO_TestOnFlag[i][FlexOutput_ON] = OFF; FlexIO_SetOnFlag[i][FlexOutput_ON] = OFF;}
       }
  return (false);
}
/*------------------------------------------------------------------------- 
--  Procedure Name    : Flex_Outputs
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/06
--  
--  Purpose           : Flex I/Os Output activation logic
--                      
--  Value Parameters  :
--  Variable Params   : none 
--  Side Effects      : 
--------------------------------------------------------------------------*/
void Flex_Outputs (void)
{
int i,j,k=0,l; 
bool output_status,Test_IO = false, Test_SP = false,
     return_SP, valid = false; 
j = 0;

for (i=0; i<Flex_Out3; i++) /* FlexIO # */
{

  for (j=0; j<2; j++) /* Output OFF or Output ON*/
  {    
    Test_IO = (FlexIO_Type[i][j] == Flex_Input || FlexIO_Type[i][j] == Flex_Output);
    Test_SP = (FlexIO_Type[i][j] == Flex_Setpoint);

    switch (FlexIO_Type[i][j])    
    {
      case Flex_Setpoint:
      case Flex_Output:
      case Flex_Input: // IO Test
               if (IO_Enable[O_FlexIO_1+i])// Output Enabled in IO Config
               {
                output_status = out (IO_Address[(O_FlexIO_1+i)]); // Get state of the current output
                switch (j) // Output "Flex1 or Flex2" ON or OFF selection 
                {
                  case FlexOutput_OFF: // Output Change on IO OFF Condition

                          if (output_status ) // OFF 
                          {
                            if (Test_IO) 
                            {
                              valid = (Flex_IOTest(i,j,k)); //OFF
                            }  
                            else if (Test_SP) 
                                 {  
                                   valid = (Flex_SetpointTest(i,j)); //OFF
                                 }  
                                 else T_EnOff(T_FlexOut1Off+k);
                                 
                                   if (valid)
                                    {                     
                                      if (TON_Test(Flex_T_EN, i,j,k))
                                      {
                                        T_EnOn(T_FlexOut1Off+k);
                                      }  
                                      if (TON_Test(Flex_T_Dn, i,j,k))
                                      {
                                        Output_OFF(O_FlexIO_1+i);
                                        T_EnOff(T_FlexOut1Off+k);
                                      }
                                      valid = false;
                                    }
                                    else T_EnOff(T_FlexOut1Off+k);
                          }
                          else T_EnOff(T_FlexOut1Off+k);
                        break;
                
                  case FlexOutput_ON: // Output Change on IO ON Condition

                          if (!output_status) // ON 
                          { 
                            if (Test_IO) 
                            {
                              valid = (Flex_IOTest(i,j,k)); //OFF
                            }  
                            else if (Test_SP) 
                                 { 
                                   valid = (Flex_SetpointTest(i,j)); //OFF
                                 }  
                                 else T_EnOff(T_FlexOut1Off+k);
                            
                                   if (valid || FlexIO_TestOnFlag[i][j])
                                    { 
                                      if (TON_Test(Flex_T_EN, i,j,k) && !FlexIO_SetOnFlag[i][j]) 
                                      {
                                        T_EnOn(T_FlexOut1Off+k);
                                      }  
                               
                                      if (TON_Test(Flex_T_Dn, i,j,k) && !FlexIO_SetOnFlag[i][j]) 
                                      {
                                        Output_ON(O_FlexIO_1+i);
                                        T_EnOff(T_FlexOut1Off+k);
                                        FlexIO_SetOnFlag[i][FlexOutput_ON ]= ON;
                                      }                        
                                      valid = false;
                                    }
                                    else T_EnOff(T_FlexOut1Off+k); 
                          }
                          else T_EnOff(T_FlexOut1Off+k);                           
                        break;
                }
               }
              
               else if (IO_Enable[O_FlexIO_1+i])
                    {
                      Output_OFF(O_FlexIO_1+i); 
                    }
              
              break;     
                     
      default: // None selected: Turn Outputs OFF
               if (IO_Enable[O_FlexIO_1+i])
                    {
                      Output_OFF(O_FlexIO_1+i);
                    }  
             break;   
    }
    k =k+1;
  }    
}
}      

/*------------------------------------------------------------------------- 
--  Procedure Name    : TON_CntTest
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/06
--  
--  Purpose           : Tests if Timer check is valid for the condition
--                      
--  Value Parameters  :
--  Variable Params   : none 
--  Side Effects      : 
--------------------------------------------------------------------------*/
bool TON_CntTest (int test, int i, int j, int k)
{
  switch (test)
  {
    case Flex_T_EN:  // Test if T_EN !NOT enabled
            if (!T_EN[T_FlexOut3OnTime+k] || T_PRE[T_FlexOut3OnTime+k]==0 )
            return (true);
            else return (false);
           break;
    case Flex_T_Dn: // Test if T_Dn Enabled
            if (T_Dn(T_FlexOut3OnTime+k) || T_PRE[T_FlexOut3OnTime+k]==0 )
            return (true);
            else return (false);
           break; 
  }
}

/*------------------------------------------------------------------------- 
--  Procedure Name    : Flex_IOCntTest
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/06
--  
--  Purpose           : Tests if IO test is valid for the condition
--                      
--  Value Parameters  :
--  Variable Params   : none 
--  Side Effects      : 
--------------------------------------------------------------------------*/
bool Flex_IOCntTest (int i, int j, int k)
{

    if (FlexCounter >= FlexCNT_PRE || (out (IO_Address[(O_FlexIO_3)])))
    {
      if (TON_CntTest(Flex_T_Dn, i,j,k)) 
      {
        FlexIO_TestOnFlag[i][j] = ON;
      } 
     
     return (true);  
    }
    else if (FlexCounter == 0 && FlexIO_SetOnFlag[i][j]) 
         {
           FlexIO_TestOnFlag[i][FlexOutput_ON] = OFF; 
           FlexIO_SetOnFlag[i][FlexOutput_ON] = OFF;
           return (false);
         }   
}
/*------------------------------------------------------------------------- 
--  Procedure Name    : Flex_IOPulseTest
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2016/06
--  
--  Purpose           : Tests if IO test is valid for the condition
--                      
--  Value Parameters  :
--  Variable Params   : none 
--  Side Effects      : 
--------------------------------------------------------------------------*/
bool Flex_IOPulseTest (int i, int j, int k)
{

   if (Input_State(FlexIO_IOEnum[i][j]) || (out (IO_Address[(O_FlexIO_3)])))
    {
      if (TON_CntTest(Flex_T_Dn, i,j,k)) 
      {
        FlexIO_TestOnFlag[i][j] = ON;
      } 
     
     return (true);  
    }
    else if (!Input_State(FlexIO_IOEnum[i][j])&& FlexIO_SetOnFlag[i][j])  
         {
           FlexIO_TestOnFlag[i][FlexOutput_ON] = OFF; 
           FlexIO_SetOnFlag[i][FlexOutput_ON] = OFF;
           return (false);
         }   
}

/*------------------------------------------------------------------------- 
--  Procedure Name    : Flex_Counter
--  Created by        : Jean-Pierre Doré
--  Last modified on  : 2017/03
--  
--  Purpose           : Flex I/Os Output activation on counter logic
--                      
--  Value Parameters  :
--  Variable Params   : none 
--  Side Effects      : 
--------------------------------------------------------------------------*/
void Flex_Counter (void)
{
int i,j,k=0,l; 
bool output_status,Test_SP = false, Test_Pulsing = false, Test_IO,
     return_SP, valid = false; 

 
    Test_IO = (FlexIO_Type[Flex_Out3][FlexOutput_ON] == Flex_Input || FlexIO_Type[Flex_Out3][FlexOutput_ON] == Flex_Output);

               if (IO_Enable[O_FlexIO_3]&& FlexCNT_PRE > 0)// Output Enabled in IO Config
               {
                
                /**************************/
                /* Preset counter section */
                /**************************/                
                 if (!FlexIO_CntMode[Flex_Out3][FlexOutput_ON]) 
                 {
                  output_status = out (IO_Address[(O_FlexIO_3)]); // Get state of the current output
                  
                  switch (output_status) // Output "x" ON or OFF selection 
                  {
                    case ON: // Output Change on IO ON Condition
  
                              if (Test_IO) valid = (Flex_IOCntTest(Flex_Out3,FlexOutput_ON,Flex_On_Time)); //
                               else T_EnOff(T_FlexOut3OnTime); //FlexIO.OnTime
                                   
                                     if (valid)
                                      {                     
                                        if (TON_CntTest(Flex_T_EN, Flex_Out3,FlexOutput_ON,Flex_On_Time))
                                        {
                                          T_EnOn(T_FlexOut3OnTime); //FlexIO.OnTime
                                        }  
                                        if (TON_CntTest(Flex_T_Dn, Flex_Out3,FlexOutput_ON,Flex_On_Time))
                                        {
                                          Output_OFF(O_FlexIO_3);
                                          T_EnOff(T_FlexOut3OnTime); //FlexIO.OnTime
                                          FlexCounter = 0;
                                        }
                                        valid = false;
                                      }
                                      else T_EnOff(T_FlexOut3OnTime); //FlexIO.OnTime

                          break;
                  
                    case OFF: // Output Change on IO OFF Condition
  
                              if (FlexIO_CntMode[Flex_Out3][FlexOutput_ON] == Flex_Preset)
                              {
                                if (Input_State(FlexIO_IOEnum[Flex_Out3][FlexOutput_ON])) 
                                {
                                  if (!Flex_FS_Test)
                                  {
                                    Flex_FS_Test = ON;
                                    FlexCounter++;
                                  }
                                }  
                                else Flex_FS_Test = OFF;  
                              }
                                
                              
                              if (Test_IO) valid = (Flex_IOCntTest(Flex_Out3,FlexOutput_ON,Flex_On_Time)); //
                               else T_EnOff(T_FlexOut3InitOn); //FlexIO.InitDelay
                              
                                     if (valid || FlexIO_TestOnFlag[Flex_Out3][FlexOutput_ON])
                                      { 
                                        
                                        if (TON_CntTest(Flex_T_EN, Flex_Out3,FlexOutput_ON,Flex_Init_Delay) && !FlexIO_SetOnFlag[Flex_Out3][FlexOutput_ON]) 
                                        {
                                          T_EnOn(T_FlexOut3InitOn); //FlexIO.InitDelay
                                        }  
                                 
                                        if (TON_CntTest(Flex_T_Dn, Flex_Out3,FlexOutput_ON,Flex_Init_Delay) && !FlexIO_SetOnFlag[Flex_Out3][FlexOutput_ON]) 
                                        {
                                          Output_ON(O_FlexIO_3);
                                          T_EnOff(T_FlexOut3InitOn); //FlexIO.InitDelay
                                          FlexIO_SetOnFlag[Flex_Out3][FlexOutput_ON ]= ON;
                                          FlexCounter = 0;
                                        }                     
                                        valid = false;
                                      }
                                      else T_EnOff(T_FlexOut3InitOn); //FlexIO.InitDelay
              
                          break;
                  }
                 
                 } 
                /***************************/
                /* Pulsing counter section */
                /***************************/ 
                 else
                 {
                  output_status = out (IO_Address[(O_FlexIO_3)]); // Get state of the current output
                  
                  switch (output_status) // Output "x" ON or OFF selection 
                  {
                    case ON: // Output Change on IO ON Condition
  
                              if (Test_IO) valid = (Flex_IOPulseTest(Flex_Out3,FlexOutput_ON,Flex_On_Time)); //
                               else T_EnOff(T_FlexOut3OnTime); //FlexIO.OnTime
                                   
                                     if (valid)
                                      {                     
//                                        if (TON_CntTest(Flex_T_EN, Flex_Out3,FlexOutput_ON,Flex_On_Time) && !Flex_Pulse_On)
//                                        {
//                                          T_EnOn(T_FlexOut3OnTime); //FlexIO.OnTime
//                                        }  
                                        if (TON_CntTest(Flex_T_Dn, Flex_Out3,FlexOutput_ON,Flex_On_Time))
                                        {
                                          Output_OFF(O_FlexIO_3);
                                          T_EnOff(T_FlexOut3OnTime); //FlexIO.OnTime
                                          if (FlexPulseCnt > 0)
                                          { 
                                            Flex_Pulse_On = ON;
                                            T_EnOn(T_FlexOut3OffTime); //FlexIO.OffTime
                                          }
                                          else Flex_Pulse_On = OFF;
                                        }
                                        valid = false;
                                      }
                                      else T_EnOff(T_FlexOut3OnTime); //FlexIO.OnTime

                          break;
                  
                    case OFF: // Output Change on IO OFF Condition
                                                              
                              if (!Flex_Pulse_On)
                              {
                                  if (Test_IO) valid = (Flex_IOPulseTest(Flex_Out3,FlexOutput_ON,Flex_On_Time)); //
                                   else T_EnOff(T_FlexOut3InitOn); //FlexIO.InitDelay
                              
                                     if (valid || FlexIO_TestOnFlag[Flex_Out3][FlexOutput_ON] || T_EN[T_FlexOut3InitOn] )
                                      { 
                                        
                                        if (TON_CntTest(Flex_T_EN, Flex_Out3,FlexOutput_ON,Flex_Init_Delay) && !FlexIO_SetOnFlag[Flex_Out3][FlexOutput_ON]) 
                                        {
                                          T_EnOn(T_FlexOut3InitOn); //FlexIO.InitDelay
                                          FlexPulseCnt = FlexCNT_PRE - 1;
                                        }  
                                 
                                        if (TON_CntTest(Flex_T_Dn, Flex_Out3,FlexOutput_ON,Flex_Init_Delay) && !FlexIO_SetOnFlag[Flex_Out3][FlexOutput_ON]) 
                                        {
                                          Output_ON(O_FlexIO_3);
                                          T_EnOff(T_FlexOut3InitOn); //FlexIO.InitDelay
                                          T_EnOn(T_FlexOut3OnTime); //FlexIO.OnTime
                                          FlexIO_SetOnFlag[Flex_Out3][FlexOutput_ON ]= ON;
                                        }                     
                                        valid = false;
                                      }
                                      else T_EnOff(T_FlexOut3InitOn); //FlexIO.InitDelay
                              }
                              else if (Flex_Pulse_On) 
                                   {
                                    
                                        if (TON_CntTest(Flex_T_Dn, Flex_Out3,FlexOutput_ON,Flex_Off_Time))
                                        {
                                          Output_ON(O_FlexIO_3);
                                          T_EnOff(T_FlexOut3OffTime); //FlexIO.OffTime
                                          T_EnOn(T_FlexOut3OnTime); //FlexIO.OnTime
                                          FlexPulseCnt--;
                                        }
                                   }
                                   else T_EnOff(T_FlexOut3OffTime); //FlexIO.OffTime
                                                    
                          break;
                  }
                 
                 }

               }              
               else if (IO_Enable[O_FlexIO_3])
                    {
                      Output_OFF(O_FlexIO_3);
                    }
                    else
                    {
                      Flex_FS_Test  = OFF;
                      Flex_Pulse_On = OFF;
                      FlexCounter   = 0;  
                    }  
} 

                                    