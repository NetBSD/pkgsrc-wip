
     --==================================================================--

with CA11022_0.CA11022_1;                -- Generic sibling.

-- Child package to provide customized graphic functions for the
-- VT100.
package CA11022_0.CA11022_2 is           -- VT100 Graphic.

   X : Column := 8;
   Y : Row    := 3;
   R : Radius := 2;
   L : Length := 6;

   procedure VT100_Graphic;

end CA11022_0.CA11022_2;
