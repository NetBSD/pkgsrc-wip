

package BXE2010.BXE2010_Bad_Child_2 is                             -- ERROR:
             -- this package does not contain a Remote_Call_Interface pragma
             -- but since it is a public child of a Remote_Call_Interface
             -- unit it is required to have one.
  procedure A_Normal_Proc;
end BXE2010.BXE2010_Bad_Child_2;
