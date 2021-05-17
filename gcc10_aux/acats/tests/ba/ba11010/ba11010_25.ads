                                           -- BA11010_2 is a nested package.

with BA11010_1;                            -- public parent package
package BA11010_25 renames BA11010_1.BA11010_3;                      -- ERROR:
