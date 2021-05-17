
---------------------------------------------------------------- BXC6001_1

with BXC6001_0;
package BXC6001_1 is

  type Plain_Record_Type is record
    Element_One   : Boolean;
    Element_Two   : Character;
  end record;

  A_Record_Object : Plain_Record_Type;
  pragma Volatile( A_Record_Object );                             -- OK

  type Atomic_Record_Type is record
    Element_One   : Boolean;
    Element_Two   : Character;
  end record;
  pragma Atomic( Atomic_Record_Type );                      -- Optional Error

  type Non_Atomic_Record_Type is record
    Element_One   : Boolean;
    Element_Two   : Character;
  end record;

  Atomic_Object_Of_Non_Atomic_Record_Type : Non_Atomic_Record_Type;
  pragma Atomic( Atomic_Object_Of_Non_Atomic_Record_Type ); -- Optional Error

  type Intermediate_Tagged is new BXC6001_0.Root_Tagged with record
    Additional_Component : Plain_Record_Type;
    pragma Volatile( Additional_Component );                      -- OK
  end record;

  type Non_Volatile_Array is new BXC6001_0.Array_Type;

  type Atomic_Array is new BXC6001_0.Array_Type;
  pragma Atomic( Atomic_Array );                            -- Optional Error

  type Atomic_Component_Array is new BXC6001_0.Array_Type;
  pragma Atomic_Components( Atomic_Component_Array );             -- OK

  type Volatile_Array is new BXC6001_0.Array_Type;
  pragma Volatile( Volatile_Array );                              -- OK

  type Volatile_Component_Array is new BXC6001_0.Array_Type;
  pragma Volatile_Components( Volatile_Component_Array );         -- OK

  ACVC_Team : Volatile_Component_Array;

  ACVC_Reviewers : Atomic_Array;

end BXC6001_1;
