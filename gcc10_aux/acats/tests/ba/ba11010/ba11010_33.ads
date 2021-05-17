                                           -- BA11010_11 is a nested package.

with BA11010_1.BA11010_10;                 -- public child function
procedure BA11010_33 renames BA11010_1.BA11010_10.BA11010_12;        -- ERROR:
