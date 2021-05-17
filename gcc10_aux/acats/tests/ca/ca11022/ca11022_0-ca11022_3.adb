
     --==================================================================--

package body CA11022_0.CA11022_3 is    

   procedure IBM3270_Graphic is
      procedure IBM3270_Putdot (X : in Column;
                             Y : in Row) is
      begin   
         -- Light a pixel at location (X + 2, Y);
         TC_Screen (Y, X + Column(2)) := true;
      end IBM3270_Putdot;

                  ------------------------------------

      -- Declare instance of the generic sibling package to draw a circle, 
      -- a square, or an ellipse customized for the IBM3270.
      package IBM3270_Graphic is new CA11022_0.CA11022_1 (IBM3270_Putdot);
   
   begin  
      IBM3270_Graphic.Draw_Circle (X, Y, R);
      IBM3270_Graphic.Draw_Square (X, Y, L);
   end IBM3270_Graphic;

end CA11022_0.CA11022_3;
