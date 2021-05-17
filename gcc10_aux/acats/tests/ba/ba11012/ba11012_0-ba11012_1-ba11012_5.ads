                                -- Outside the declarative region of BA11012_0.

-------------------------------------------------------
with BA11012_0.BA11012_1.BA11012_2;     -- private generic grandchild package.
private 
generic 
package BA11012_0.BA11012_1.BA11012_5 renames 
  BA11012_0.BA11012_1.BA11012_2;                                      -- OK.
