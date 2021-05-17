

with BXE2012_SP2;   use BXE2012_SP2;
package BXE2012_RT2 is
  pragma Remote_Types;

  type Tagged_Type_1 is tagged limited private;
  procedure Primitive_Op_1 (Controlling_Parm : access Tagged_Type_1;
                            Non_Controlling  : Good_Private_Type);

  type Remote_Class_Wide_Ptr_1 is access all Tagged_Type_1'Class;    -- OK.

  type Tagged_Type_2 is tagged limited private;
  procedure Primitive_Op_2 (Controlling_Parm : access Tagged_Type_2;
                            Non_Controlling  : Bad_Private_Type);

  type Remote_Class_Wide_Ptr_2 is access all Tagged_Type_2'Class; -- ERROR:
          -- Non-controlling parameters of limited private types designated
          -- by a remote access-to-class-wide type are required to
          -- have Read and Write attributes.

private
  type Tagged_Type_1 is tagged limited
    record
      F : Integer;
    end record;

  type Tagged_Type_2 is tagged limited
    record
      F : Integer;
    end record;
end BXE2012_RT2;
