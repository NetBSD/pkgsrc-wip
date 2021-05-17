
     --=================================================================--

with BA11009_4.BA11009_6.BA11009_7;   -- Generic grandchild procedure.
with BA11009_4.BA11009_8;             -- Generic grandchild function.

with BA11009_0.BA11009_1.BA11009_2;   -- Generic grandchild procedure,
                                      -- implicitly with BA11009_0.BA11009_1.
with BA11009_0.BA11009_3;             -- Generic grandchild function.

package body BA11009_4.BA11009_6 is

   generic package BA11009_16 renames BA11009_0.BA11009_1;           -- ERROR:
                                                      -- Outside of BA11009_0.
   generic procedure BA11009_17 renames 
     BA11009_4.BA11009_6.BA11009_7;                                  -- OK. 
   generic procedure BA11009_18 renames 
     BA11009_0.BA11009_1.BA11009_2;                                  -- ERROR:
                                                      -- Outside of BA11009_0.
   generic function BA11009_19 renames BA11009_4.BA11009_8;          -- OK. 
   generic function BA11009_20 renames BA11009_0.BA11009_3;          -- ERROR:
                                                      -- Outside of BA11009_0.

  procedure Do_Something is               -- here to require the package body 
   begin
      SParent_Var := SParent_Var / 7;
      -- Real body of procedure goes here.
   end Do_Something;

end BA11009_4.BA11009_6;
