
--==================================================================--

with C730003_0;
with C730003_0.C730003_2;
with Report;

procedure C730003 is
begin

   Report.Test ("C730003", "Check that the characteristics of a type "   &
                           "derived from a private extension (outside "  &
                           "the scope of the full view) are those "      &
                           "defined by the partial view of the private " &
                           "extension");

   Check_Your_Cards:
   declare
      use C730003_0;
      use C730003_0.C730003_2;

      Top_Card_On_The_Deck : Graphic_Card;

   begin

      -- Update value in the components of the card.  There are two
      -- component fields named View, although one is not visible for
      -- any view of a Graphic_Card.

      Update_View(Top_Card_On_The_Deck);

      -- Verify that both "View" components of the card have been updated.

      if Get_View(Top_Card_On_The_Deck) /= Ace_Of_Hearts then
         Report.Failed ("Incorrect value in visible component - 1");
      end if;

      if Get_Private_View(Top_Card_On_The_Deck) /= Queen_Of_Spades
      then
         Report.Failed ("Incorrect value in non-visible component - 1");
      end if;

      -- Again, update the components of the card (to blank values).

      Hide_From_View(Top_Card_On_The_Deck);

      -- Verify that both components have been updated.

      if Get_View(Top_Card_On_The_Deck) /= Read_Em_And_Weep then
         Report.Failed ("Incorrect value in visible component - 2");
      end if;

      if Get_Private_View(Top_Card_On_The_Deck) /= Close_To_The_Vest
      then
         Report.Failed ("Incorrect value in non-visible component - 2");
      end if;

   exception
      when others => Report.Failed("Exception raised in test block");
   end Check_Your_Cards;

   Report.Result;

end C730003;
