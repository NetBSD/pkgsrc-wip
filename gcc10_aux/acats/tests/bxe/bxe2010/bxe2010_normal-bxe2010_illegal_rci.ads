

package BXE2010_Normal.BXE2010_Illegal_RCI is
  pragma Remote_Call_Interface;                                    -- ERROR:
               -- This package depends upon a normal package so it cannot be
               -- an RCI unit.
  procedure Bletch (X : Integer);
end BXE2010_Normal.BXE2010_Illegal_RCI;
