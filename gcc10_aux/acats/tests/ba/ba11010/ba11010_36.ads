                                           -- BA11010_14 is a nested package.

with BA11010_13;                           
function BA11010_36 return integer renames BA11010_13.BA11010_15;    -- ERROR:
                                           -- BA11010_15 is a subunit.
