
     --==================================================================--

package body CA11022_0.CA11022_2 is    

   procedure VT100_Graphic is
      procedure VT100_Putdot (X : in Column;
                              Y : in Row) is
      begin   
         -- Light a pixel at location (X, Y);
         TC_Screen (Y, X) := true;
      end VT100_Putdot;

                  ------------------------------------

      -- Declare instance of the generic sibling package to draw a circle, 
      -- a square, or an ellipse customized for the VT100.
      package VT100_Graphic is new CA11022_0.CA11022_1 (VT100_Putdot);
   
   begin  
      VT100_Graphic.Draw_Circle (X, Y, R);
      VT100_Graphic.Draw_Square (X, Y, L);
   end VT100_Graphic;

end CA11022_0.CA11022_2;
