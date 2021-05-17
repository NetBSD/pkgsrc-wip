                                           -- BA11010_9 is a subunit.

------------------------------------------------------------------------------
with BA11010_1.BA11010_10;                 -- public child function
function BA11010_31 return BA11010_1.Parent_Type 
  renames BA11010_1.BA11010_10;                                        -- OK
