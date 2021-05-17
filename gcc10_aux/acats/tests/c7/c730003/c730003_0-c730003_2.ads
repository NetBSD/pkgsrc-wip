
--==================================================================--

with C730003_1; use C730003_1;
package C730003_0.C730003_2 is

   Queen_Of_Spades   : constant C730003_0.ASCII_Representation := 12;
   Ace_Of_Hearts     : constant String := "AH";
   Close_To_The_Vest : constant C730003_0.ASCII_Representation := 14;
   Read_Em_And_Weep  : constant String := "AA";

   type Graphic_Card is new C730003_1.Graphic_Card with null record;

   -- Implicit function Get_Private_View                                -- (C)
   --           (A_Card : Graphic_Card) return C730003_0.ASCII_Representation;

   function  Get_View       (Card : Graphic_Card) return String;
   procedure Update_View    (Card : in out Graphic_Card);
   procedure Hide_From_View (Card : in out Graphic_Card);

end C730003_0.C730003_2;
