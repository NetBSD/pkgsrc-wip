
---------------------------------------------------------------------------

with BXE2012_Pure;
package BXE2012_RT1 is
  pragma Remote_Types;

  -- tagged types
  type Tagged_Type_1 is tagged limited private;
  procedure Primitive_1A (TT : access Tagged_Type_1);
  procedure Primitive_1B (TT : in out Tagged_Type_1);

  -- remote access to class wide type
  type Class_Wide_Ptr_1 is access all Tagged_Type_1'Class;           -- OK.

  type Tagged_Type_2 is tagged record
       ZZ : Integer;
    end record;
  procedure Primitive_2A (TT : access Tagged_Type_2);
  type Class_Wide_Ptr_2 is access all Tagged_Type_2'Class;        -- ERROR:
                                  -- the tagged type is not limited private


  type Class_Wide_Ptr_3 is
     access all BXE2012_Pure.Root_Tagged_Type_1'Class;               -- OK.

  type Class_Wide_Ptr_4 is
     access all BXE2012_Pure.Root_Tagged_Type_2'Class;               -- OK.
            -- not all the primitive operations have only access parameters

private
  type Tagged_Type_1 is tagged limited
    record
       B_Field : Boolean;
    end record;

end BXE2012_RT1;
