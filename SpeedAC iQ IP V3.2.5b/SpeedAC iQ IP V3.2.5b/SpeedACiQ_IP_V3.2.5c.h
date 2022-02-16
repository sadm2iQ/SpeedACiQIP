﻿string VersionNumber (void)
{
  string unfiltered[256] = __FILE__;
  string version[64] = "";
  char car;
  int i = 0,len,Vpos;
  int d = 0;
  int delimiter = 0;
  
  len = length(unfiltered);
  
  // search for the last path delimiter
  for (i=0; unfiltered[i]; i++)
    if (unfiltered[i] == '\\' || unfiltered[i] == '/')
      delimiter = i;
   
  version = right(unfiltered,len - delimiter);
  len = length(version);
  
  for(i=len;i>=0;i--)
   {
    car = version[i];
    if(car == 'V')
     {
      Vpos = i;
      i = -1;
     }
   }
      
  len = length(version);
  version = right(version , len-Vpos);
  version = left(version,length(version)-2);
 
    #if defined BETA_RELEASE
    version = concat(version, " BETA");
    #endif
    
  return (concat(version,""));
}

