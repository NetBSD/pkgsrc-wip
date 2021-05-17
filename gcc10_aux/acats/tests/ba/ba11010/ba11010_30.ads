                                    -- BA11010_8 is a nested package instance.

with BA11010_1.BA11010_6;                  -- public child package
function BA11010_30 return BA11010_1.Parent_Type
  renames BA11010_1.BA11010_6.BA11010_9;                             -- ERROR:
