
package C452001_4 is

   type Tagged_Partial_Tagged_Full is tagged private;
   procedure Change (Object : in out Tagged_Partial_Tagged_Full;
                     Value  : in Boolean);

   type Untagged_Partial_Tagged_Full is private;
   procedure Change (Object : in out Untagged_Partial_Tagged_Full;
                     Value  : in Integer);

   type Untagged_Partial_Untagged_Record_Full is private;
   procedure Change (Object : in out Untagged_Partial_Untagged_Record_Full;
                     Value  : in Duration);

   function "=" (L, R : in Untagged_Partial_Untagged_Record_Full) return Boolean;
      -- Primitive equality checks that records equate in component S only.
      -- This has to be visible to avoid violating 4.5.2(9.7/3).

   type Untagged_Partial_Untagged_Array_Full is private;
   procedure Change (Object : in out Untagged_Partial_Untagged_Array_Full;
                     Value  : in Character);

   function "=" (L, R : in Untagged_Partial_Untagged_Array_Full) return Boolean;
      -- Primitive equality checks that components 1..4 are equal only.
      -- We make this visible to be similar to the record case.

private

   type Tagged_Partial_Tagged_Full is
      tagged record
         B : Boolean := True;
         C : Character := ' ';
      end record;
   -- predefined equality checks that all components are equal

   function "=" (L, R : in Tagged_Partial_Tagged_Full) return Boolean;
   -- primitive equality checks that records equate in component C only

   type Untagged_Partial_Tagged_Full is
      tagged record
         I : Integer := 0;
         P : Positive := 1;
      end record;
   -- predefined equality checks that all components are equal

   function "=" (L, R : in Untagged_Partial_Tagged_Full) return Boolean;
   -- primitive equality checks that records equate in component P only

   type Untagged_Partial_Untagged_Record_Full is
      record
         D : Duration := 0.0;
         S : String (1..12) := "Ada 12 rules";
      end record;
   -- predefined equality checks that all components are equal

   --function "=" (L, R : in Untagged_Partial_Untagged_Record_Full) return Boolean;
   -- Moved above, would violate 4.5.2(9.7/3) here.

   type Untagged_Partial_Untagged_Array_Full is
      array (1..8) of Character with Default_Component_Value => 'L';
   -- predefined equality checks that all components are equal

   --function "=" (L, R : in Untagged_Partial_Untagged_Array_Full) return Boolean;
   -- Moved above, to match record case.

end C452001_4;
