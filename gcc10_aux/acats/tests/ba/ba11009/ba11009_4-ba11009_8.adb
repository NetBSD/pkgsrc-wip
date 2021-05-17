
     --=================================================================--


with BA11009_0.BA11009_1.BA11009_2;   -- Generic grandchild procedure,
                                      -- implicitly with BA11009_0.BA11009_1.

function BA11009_4.BA11009_8 return SGrand_Parent_Type is

   generic package BA11009_25 renames BA11009_4.BA11009_6;           -- OK. 
   generic package BA11009_26 renames BA11009_0.BA11009_1;           -- ERROR:
                                                      -- Outside of BA11009_0.
   generic procedure BA11009_27 renames 
     BA11009_4.BA11009_6.BA11009_7;                                  -- ERROR:
                                                      -- Outside of BA11009_6.
   generic procedure BA11009_28 renames 
     BA11009_0.BA11009_1.BA11009_2;                                  -- ERROR:
                                                      -- Outside of BA11009_0.
   generic function BA11009_29 renames BA11009_0.BA11009_3;          -- ERROR:
                                                      -- Outside of BA11009_0.

begin
   return 598;
end BA11009_4.BA11009_8;
