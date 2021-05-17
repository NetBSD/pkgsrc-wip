                               -- Outside the declarative region of BA11011_10.

-------------------------------------------------------
with BA11011_10.BA11011_11.BA11011_12;
generic 
package BA11011_10.BA11011_14 is
   generic package BA11011_15 renames 
     BA11011_10.BA11011_11.BA11011_12;                                -- ERROR:
                               -- Outside the declarative region of BA11011_11.
end BA11011_10.BA11011_14;
