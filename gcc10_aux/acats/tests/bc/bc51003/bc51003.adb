
-- No body for BC51003_6.


     --==================================================================--


with BC51003_0;  -- Type definitions.
with BC51003_1;  -- Integer formal types.
with BC51003_2;  -- Floating point formal types.
with BC51003_3;  -- Array  formal types.
with BC51003_4;  -- Record formal types.
with BC51003_5;  -- Access formal types.
with BC51003_6;  -- Tagged formal types.
procedure BC51003 is

--
-- Integer Types :
--

   package Integer_Compatible_Constraints1 is new
     BC51003_1 (Natural);                                             -- OK.


   package Integer_Compatible_Constraints2 is new
     BC51003_1 (BC51003_0.Sizes);                                     -- OK.


   package Integer_Incompatible_Constraints is new
     BC51003_1 (BC51003_0.Size);                                      -- ERROR:
                                                                -- Lower bound.


--
-- Floating Point Types :
--

   package Float_Compatible_Constraints is new
     BC51003_2 (BC51003_0.Up_To_100);                                 -- OK.


   package Float_Unconstrained is new
     BC51003_2 (Float);                                               -- ERROR:
                                                       -- Actual unconstrained.

   package Float_Incompatible_Constraints is new
     BC51003_2 (BC51003_0.Top_125);                                   -- ERROR:
                                                                -- Both bounds.


--
-- Array Types :
--

   package Array_Compatible_Constraints is new
     BC51003_3 (BC51003_0.Two_By_Two);                                -- OK.


   package Array_Unconstrained is new
     BC51003_3 (BC51003_0.Matrix);                                    -- ERROR:
                                                       -- Actual unconstrained.

   package Array_Incompatible_Constraints is new
     BC51003_3 (BC51003_0.Shifted_2x2);                               -- ERROR:
                                                               -- Index bounds.


--
-- Record Types :
--

   package Record_Compatible_Constraints is new
     BC51003_4 (BC51003_0.Square2);                                   -- OK.


   package Record_Unconstrained is new
     BC51003_4 (BC51003_0.Square);                                    -- ERROR:
                                                       -- Actual unconstrained.

   package Record_Incompatible_Constraints is new
     BC51003_4 (BC51003_0.Square3);                                   -- ERROR:
                                                    -- Discriminant constraint.


--
-- Access Types :
--

   package Access_Compatible_Constraints is new
     BC51003_5 (BC51003_0.Sq2_Point);                                 -- OK.


   package Access_Unconstrained is new
     BC51003_5 (BC51003_0.Square_Ptr);                                -- ERROR:
                                                       -- Actual unconstrained.

   package Access_Incompatible_Constraints is new
     BC51003_5 (BC51003_0.Sq4_Point);                                 -- ERROR:
                                                    -- Discriminant constraint.


--
-- Tagged Types :
--

   package Tagged_Compatible_Constraints is new
     BC51003_6 (BC51003_0.Dbl_Four);                                  -- OK.


   package Tagged_Unconstrained is new
     BC51003_6 (BC51003_0.Double_Square);                             -- ERROR:
                                                       -- Actual unconstrained.

   package Tagged_Incompatible_Constraints is new
     BC51003_6 (BC51003_0.Dbl_Two);                                   -- ERROR:
                                                    -- Discriminant constraint.


begin
   null;
end BC51003;
