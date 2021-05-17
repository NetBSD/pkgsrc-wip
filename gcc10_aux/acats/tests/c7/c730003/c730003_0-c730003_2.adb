
--==================================================================--

package body C730003_0.C730003_2 is

   function Get_View (Card : Graphic_Card) return String is
   begin
      return Card.View;
   end Get_View;

   procedure Update_View (Card : in out Graphic_Card) is
      ASCII_View      : Disp_Card renames Disp_Card(Card); -- View conversion.
   begin
      ASCII_View.View := Queen_Of_Spades;                               -- (F)
                                              -- Assignment to "hidden" field.
      Card.View       := Ace_Of_Hearts;                                 -- (D)
                                 -- Assignment to Graphic_Card declared field.
   end Update_View;

   procedure Hide_From_View (Card : in out Graphic_Card) is
   begin
      -- Update both of Card's View components.
      Disp_Card(Card).View := Close_To_The_Vest;                        -- (E)
                                              -- Assignment to "hidden" field.
      Card.View            := Read_Em_And_Weep;                         -- (D)
                                 -- Assignment to Graphic_Card declared field.
   end Hide_From_View;

end C730003_0.C730003_2;
