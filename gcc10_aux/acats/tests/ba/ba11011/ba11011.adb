                                -- BA11011_20.BA11011_11 is not a library unit.

-------------------------------------------------------
with BA11011_10.BA11011_23;
procedure BA11011 is
   generic package BA11011_29 renames
     BA11011_10.BA11011_23.BA11011_24;                                -- ERROR:
                     -- BA11011_10.BA11011_23.BA11011_11 is not a library unit.

begin
   null;
end BA11011;
