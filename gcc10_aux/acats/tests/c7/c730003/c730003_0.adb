
--==================================================================--

package body C730003_0 is

   procedure Turn_Over_Card (Card: in out Playing_Card) is
   begin
      Card.Face := Up;
   end Turn_Over_Card;

   function Get_Private_View (A_Card : Disp_Card)
     return ASCII_Representation is
   begin
      return A_Card.View;
   end Get_Private_View;

end C730003_0;
