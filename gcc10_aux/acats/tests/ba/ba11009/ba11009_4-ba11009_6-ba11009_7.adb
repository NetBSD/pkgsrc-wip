
     --=================================================================--

with BA11009_4.BA11009_8;             -- Generic grandchild function.

with BA11009_0.BA11009_1.BA11009_2;   -- Generic grandchild procedure,
                                      -- implicitly with BA11009_0.BA11009_1.
with BA11009_0.BA11009_3;             -- Generic grandchild function.

procedure BA11009_4.BA11009_6.BA11009_7 is

   generic package BA11009_21 renames BA11009_0.BA11009_1;           -- ERROR:
                                                      -- Outside of BA11009_0.
   generic procedure BA11009_22 renames 
     BA11009_0.BA11009_1.BA11009_2;                                  -- ERROR:
                                                      -- Outside of BA11009_0.
   generic function BA11009_23 renames BA11009_4.BA11009_8;          -- OK. 
   generic function BA11009_24 renames BA11009_0.BA11009_3;          -- ERROR:
                                                      -- Outside of BA11009_0.
begin
   null;
end BA11009_4.BA11009_6.BA11009_7;
