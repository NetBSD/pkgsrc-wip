
---------------------------------------------------------------------------

package BXE2012_RT3 is
  -- This package spec should compile without error
  pragma Remote_Types;

  type Tagged_Type_1 is tagged limited private;
  procedure Primitive_Op_1 (Controlling_Parm : access Tagged_Type_1);

  type Remote_Class_Wide_Ptr_1 is access all Tagged_Type_1'Class;

  function Some_Remote_Ptr return Remote_Class_Wide_Ptr_1;
private
  type Tagged_Type_1 is tagged limited
    record
      F : Integer;
    end record;
end BXE2012_RT3;
