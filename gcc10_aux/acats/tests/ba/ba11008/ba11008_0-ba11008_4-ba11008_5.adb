 
     --=================================================================--
 
with BA11008_0.BA11008_1.BA11008_2;   -- Generic grandchild package,
                                      -- implicitly with BA11008_0.BA11008_1.
 
package body BA11008_0.BA11008_4.BA11008_5 is
 
   package BA11008_13 is new BA11008_0.BA11008_1;                    -- OK. 
                                     -- within BA11008_0's declarative region.
 
   package BA11008_14 is new BA11008_0.BA11008_1.BA11008_2;          -- ERROR:
                      -- not in the declarative region of BA11008_0.BA11008_1.
 
   procedure Gr_Child_Proc is
   begin
      Gr_Child_Var := Gr_Child_Var / 5;
   end Gr_Child_Proc;

end BA11008_0.BA11008_4.BA11008_5;
