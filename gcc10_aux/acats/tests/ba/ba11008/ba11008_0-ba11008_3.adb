 
     --=================================================================--
 
with BA11008_0.BA11008_1.BA11008_2;   -- Generic grandchild package,
                                      -- implicitly with BA11008_0.BA11008_1.
package body BA11008_0.BA11008_3 is
 
   package BA11008_10 is new BA11008_0.BA11008_1;                    -- OK. 
                                      -- within BA11008_0's declarative region.
 
   package BA11008_11 is new BA11008_0.BA11008_1.BA11008_2;          -- ERROR:
                      -- not in the declarative region of BA11008_0.BA11008_1.

   package BA11008_12 is new BA11008_10.BA11008_2;                   -- OK.

   procedure Parent_Proc is
   begin
      Parent_Var := Parent_Var + 1;
   end Parent_Proc;

end BA11008_0.BA11008_3;
