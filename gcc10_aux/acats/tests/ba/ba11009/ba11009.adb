
     --=================================================================--

with BA11009_0.BA11009_1.BA11009_2;   -- Generic grandchild procedure,
                                      -- implicitly with BA11009_0.BA11009_1.
with BA11009_0.BA11009_3;             -- Generic grandchild function.

procedure BA11009 is

   generic package BA11009_30 renames BA11009_0.BA11009_1;           -- ERROR:
                                                      -- Outside of BA11009_0.
   generic procedure BA11009_31 renames 
     BA11009_0.BA11009_1.BA11009_2;                                  -- ERROR:
                                                      -- Outside of BA11009_0.
   generic function BA11009_32 renames BA11009_0.BA11009_3;          -- ERROR:
                                                      -- Outside of BA11009_0.
begin
   null;
end BA11009;
