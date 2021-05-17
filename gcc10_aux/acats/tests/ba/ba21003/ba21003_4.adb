 

     --===================================================================--


with BA21003_3;                                                       -- ERROR:
                                              -- WITHed unit not declared pure.
package body BA21003_4 is
   procedure Init (P: in out T2) is
   begin
      P.C := 0;
   end Init;
end BA21003_4;
