
     --==================================================================--

with CA11022_0.CA11022_1;                -- Generic sibling.

-- Child package to provide customized graphic functions for the
-- IBM3270.
package CA11022_0.CA11022_3 is           -- IBM3270 Graphic.

   X : Column := 39;
   Y : Row    := 11;
   R : Radius := 3;
   L : Length := 7;

   procedure IBM3270_Graphic;

end CA11022_0.CA11022_3;
