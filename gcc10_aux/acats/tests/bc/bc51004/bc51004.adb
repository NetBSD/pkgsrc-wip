
-- No body for BC51004_6.


     --==================================================================--


with BC51004_0;  -- Type definitions.
with BC51004_1;  -- Integer formal types.
with BC51004_2;  -- Floating point formal types.
with BC51004_3;  -- Array  formal types.
with BC51004_4;  -- Record formal types.
with BC51004_5;  -- Access formal types.
with BC51004_6;  -- Tagged formal types.
procedure BC51004 is

--
-- Integer Types :
--

   package Integer_Compatible_Constraints is new
     BC51004_1 (BC51004_0.Sizes);                                     -- OK.


   package Integer_Incompatible_Constraints is new
     BC51004_1 (BC51004_0.Size);                                      -- ERROR:
                                                                -- Lower bound.


--
-- Floating Point Types :
--

   package Float_Compatible_Constraints is new
     BC51004_2 (BC51004_0.Up_To_100);                                 -- OK.


   package Float_Incompatible_Constraints is new
     BC51004_2 (BC51004_0.Top_125);                                   -- ERROR:
                                                                -- Both bounds.


--
-- Array Types :
--

   package Array_Compatible_Constraints is new
     BC51004_3 (BC51004_0.Two_By_Two);                                -- OK.


   package Array_Incompatible_Constraints is new
     BC51004_3 (BC51004_0.Shifted_2x2);                               -- ERROR:
                                                               -- Index bounds.


--
-- Record Types :
--

   package Record_Compatible_Constraints is new
     BC51004_4 (BC51004_0.Another_Sq2);                               -- OK.


   package Record_Incompatible_Constraints is new
     BC51004_4 (BC51004_0.Square3);                                   -- ERROR:
                                                    -- Discriminant constraint.


--
-- Access Types :
--

   package Access_Compatible_Constraints is new
     BC51004_5 (BC51004_0.Sq2_Point);                                 -- OK.


   package Access_Incompatible_Constraints is new
     BC51004_5 (BC51004_0.Sq4_Point);                                 -- ERROR:
                                                    -- Discriminant constraint.


--
-- Tagged Types :
--

   package Tagged_Compatible_Constraints is new
     BC51004_6 (BC51004_0.Annot_Dbl_Sq4);                             -- OK.


   package Tagged_Incompatible_Constraints is new
     BC51004_6 (BC51004_0.Dbl_Two);                                   -- ERROR:
                                                    -- Discriminant constraint.


begin
   null;
end BC51004;
