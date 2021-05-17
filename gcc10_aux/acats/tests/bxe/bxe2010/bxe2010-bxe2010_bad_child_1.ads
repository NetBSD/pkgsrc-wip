

package BXE2010.BXE2010_Bad_Child_1 is   
  pragma Remote_Call_Interface (BXE2010);                          -- ERROR:
                      -- The name specified in the pragma does not match the 
                      -- library unit name    
  pragma All_Calls_Remote (BXE2010);                               -- ERROR:
                      -- The name specified in the pragma does not match the 
                      -- library unit name    
  pragma Remote_Call_Interface;
  procedure A_Remote_Proc;
end BXE2010.BXE2010_Bad_Child_1;
