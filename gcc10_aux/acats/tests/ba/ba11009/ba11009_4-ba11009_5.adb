
     --=================================================================--

separate (BA11009_4)
procedure BA11009_5 is
   generic package BA11009_10 renames BA11009_4.BA11009_6;           -- OK. 
   generic package BA11009_11 renames BA11009_0.BA11009_1;           -- ERROR:
                                                      -- Outside of BA11009_0.
   generic procedure BA11009_12 renames 
     BA11009_4.BA11009_6.BA11009_7;                                  -- ERROR:
                                                      -- Outside of BA11009_6.
   generic procedure BA11009_13 renames
     BA11009_0.BA11009_1.BA11009_2;                                  -- ERROR:
                                                      -- Outside of BA11009_0.
   generic function BA11009_14 renames BA11009_4.BA11009_8;          -- OK. 
   generic function BA11009_15 renames BA11009_0.BA11009_3;          -- ERROR:
                                                      -- Outside of BA11009_0.
begin
   null;
end BA11009_5;
