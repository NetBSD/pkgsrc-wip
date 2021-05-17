
     --==================================================================--


with BC51011_0;
with BC51011_1;
with BC51011_2;
with BC51011_3;
with BC51011_4;
with BC51011_5;

package BC51011 is

   type Rec_Null_Constraints (Disc : BC51011_0.My_Natural) is null record;
   type Rec_Equal_Bounds     (Disc : BC51011_0.All_Natural) is null record;
   type Rec_Unequal_Bounds   (Disc : BC51011_0.My_Positive) is null record;

   type Tag_Null_Constraints (Disc : BC51011_0.My_Natural) is tagged
     null record;
   type Tag_Equal_Bounds     (Disc : BC51011_0.All_Natural) is tagged
     null record;
   type Tag_Unequal_Bounds   (Disc : BC51011_0.My_Positive) is tagged
     null record;

   type Rec_with_Null_Disc_Range_1 (Disc : BC51011_0.Null_Range_1) is 
     null record;
   type Rec_with_Null_Disc_Range_2 (Disc : BC51011_0.Null_Range_2) is 
     null record;

   
   package Signature_Package is new BC51011_3 (BC51011_0.My_Natural);


--
-- Discriminant subtype of formal is static:
--

   package Static_Null_Constraints is new
     BC51011_1 (Rec_Null_Constraints);                                -- OK.

   package Static_Equal_Corresponding_Bounds is new
     BC51011_1 (Rec_Equal_Bounds);                                    -- OK.

   package Static_Unequal_Corresponding_Bounds is new
     BC51011_1 (Rec_Unequal_Bounds);                                  -- ERROR:
                                                  -- Lower bounds do not match.

--
-- Discriminant subtype of formal is a formal of the same generic package:
--

   package Same_Generic_Null_Constraints is new BC51011_2
     (BC51011_0.My_Natural, Rec_Null_Constraints);                    -- OK.

-- Tagged actual passed to nontagged private formal:
   package Same_Generic_Equal_Corresponding_Bounds is new BC51011_2
     (BC51011_0.My_Natural, Tag_Equal_Bounds);                        -- OK.

   package Same_Generic_Unequal_Corresponding_Bounds is new BC51011_2
     (BC51011_0.My_Natural, Rec_Unequal_Bounds);                      -- ERROR:
                                                  -- Lower bounds do not match.

--
-- Discriminant subtype of formal is a formal of a formal package:
--

   package Formal_Package_Null_Constraints is new BC51011_4
     (Signature_Package, Tag_Null_Constraints);                       -- OK.

   package Formal_Package_Equal_Corresponding_Bounds is new BC51011_4
     (Signature_Package, Tag_Equal_Bounds);                           -- OK.

   package Formal_Package_Unequal_Corresponding_Bounds is new BC51011_4
     (Signature_Package, Tag_Unequal_Bounds);                         -- ERROR:
                                                  -- Lower bounds do not match.





   package Package_with_Null_Range_1 is 
     new BC51011_5 (Rec_with_Null_Disc_Range_1);                      -- OK.

   package Package_with_Null_Range_2 is 
     new BC51011_5 (Rec_with_Null_Disc_Range_2);                      -- ERROR:
                                                        -- Bounds do not match.

end BC51011;
