
-----------------------------------------------------------
with B830001_10.B830001_13.B830001_14;
package body B830001_10.B830001_13 is
   B830001_14 : Boolean;                                              -- ERROR:
                                    -- Homograph of B830001_14 is visible here.
   procedure Do_Nothing is
      I : Integer;
   begin
      I := I + 6;
   end Do_Nothing; 

end B830001_10.B830001_13;
