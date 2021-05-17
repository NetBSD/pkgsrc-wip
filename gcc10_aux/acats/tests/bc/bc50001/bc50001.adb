
-- No body for BC50001_3.


     --==================================================================--


with BC50001_0;  -- Type definitions.
with BC50001_1;  -- Scalar formal derived type.
with BC50001_2;  -- Array  formal derived type.
with BC50001_3;  -- Access formal derived type.
procedure BC50001 is

  -- NOTE: A specific type is a descendant of itself.

--
-- Scalar types :
--

   package Scalar_Ancestor is new
     BC50001_1 (BC50001_0.Weight);                                    -- OK.


   package Scalar_Ancestor_Subtype is new
     BC50001_1 (BC50001_0.LightWt);                                   -- OK.


   package Scalar_Child is new
     BC50001_1 (BC50001_0.Pounds);                                    -- OK.


   package Scalar_Child_Subtype is new
     BC50001_1 (BC50001_0.Lbs100);                                    -- OK.


   package Scalar_Grandchild is new
     BC50001_1 (BC50001_0.UpTo10Lbs);                                 -- OK.


   package Scalar_Grandchild_Subtype is new
     BC50001_1 (BC50001_0.FeatherWt);                                 -- OK.


   package Scalar_Root is new
     BC50001_1 (Float);                                               -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Scalar_Root_Subtype is new
     BC50001_1 (BC50001_0.Float250);                                  -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Scalar_Sibling is new
     BC50001_1 (BC50001_0.Distance);                                  -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Scalar_Sibling_Subtype is new
     BC50001_1 (BC50001_0.Nearby);                                    -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Scalar_Nephew is new
     BC50001_1 (BC50001_0.Miles);                                     -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Scalar_Nephew_Subtype is new
     BC50001_1 (BC50001_0.StonesThrow);                               -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

--
-- Array types :
--

   package Array_Ancestor is new
     BC50001_2 (BC50001_0.Names);                                     -- OK.


   package Array_Ancestor_Subtype is new
     BC50001_2 (BC50001_0.NameSub);                                   -- OK.


   package Array_Child is new
     BC50001_2 (BC50001_0.LastNames);                                 -- OK.


   package Array_Grandchild is new BC50001_2
     (BC50001_0.LastNamesA_L);                                        -- OK.


   package Array_Root is new
     BC50001_2 (String);                                              -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Array_Root_Subtype is new
     BC50001_2 (BC50001_0.StringSub);                                 -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Array_Sibling is new BC50001_2
     (BC50001_0.ReservedWords);                                       -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Array_Nephew is new BC50001_2
     (BC50001_0.NewReservedWords);                                    -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

--
-- Access types :
--

   package Access_Ancestor is new
     BC50001_3 (BC50001_0.NamePtr);                                   -- OK.


   package Access_Ancestor_Subtype is new
     BC50001_3 (BC50001_0.NameSubPtr);                                -- OK.


   package Access_Child is new
     BC50001_3 (BC50001_0.LastNamePtr);                               -- OK.


   package Access_Grandchild is new BC50001_3
     (BC50001_0.LastA_LPtr);                                          -- OK.


   package Access_Root is new
     BC50001_3 (BC50001_0.StringPtr);                                 -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Access_Root_Subtype is new
     BC50001_3 (BC50001_0.StrSubPtr);                                 -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Access_Sibling is new BC50001_3
     (BC50001_0.ReservedWordPtr);                                     -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Access_Nephew is new BC50001_3
     (BC50001_0.NewReservedWdPtr);                                    -- ERROR:
                                 -- Actual is not a descendant of the ancestor.
begin
   null;
end BC50001;
