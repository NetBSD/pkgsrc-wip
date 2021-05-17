

private package BXE2010.BXE2010_Ok_Child_3 is
  pragma Remote_Call_Interface (BXE2010.BXE2010_Ok_Child_3);       -- OK.
        -- private child can be a RCI unit but can only be called from
        -- units within its own partition since those are the only
        -- units that can see it.
  procedure A_Remote_Proc;
end BXE2010.BXE2010_Ok_Child_3;
