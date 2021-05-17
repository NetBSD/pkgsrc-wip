
---------------------------------------------------------------- BXC6001_2

with BXC6001_0;
with BXC6001_1;
package BXC6001_2 is

  Array_1 : BXC6001_1.Non_Volatile_Array;
  pragma Volatile_Components( Array_1 );                          -- ERROR:
           -- for objects, may only apply to object of anonymous array type

  Array_2 : BXC6001_1.Non_Volatile_Array;
  pragma Atomic_Components( Array_2 );                            -- ERROR:
           -- for objects, may only apply to object of anonymous array type

  type Whole_Array_Volatile is array(1..10) of Integer;
  pragma Volatile( Whole_Array_Volatile );                        -- OK

  type End_Product_Tagged is new BXC6001_1.Intermediate_Tagged with record
    Simple_Component : Natural;
    pragma Volatile( Inheritable_Component );                     -- ERROR:
                                 -- may not apply to an inherited component
  end record;

   type Consumer_Tagged is new BXC6001_1.Intermediate_Tagged with record
    Simple_Component : Natural;
    pragma Volatile( Simple_Component );                         -- OK
  end record;

 type Private_Record is private;

  type Subatomic_Tagged is new BXC6001_0.Root_Tagged with record
    Additional_Component : BXC6001_1.Plain_Record_Type;
    pragma Atomic( Additional_Component );                  -- Optional Error
  end record;

  type Nuclear_Tagged is new BXC6001_0.Root_Tagged with record
    Simple_Component : Natural;
    pragma Atomic( Inheritable_Component );                       -- ERROR:
                                 -- may not apply to an inherited component
  end record;

  type Private_Atomic_Type is private;
  pragma Atomic( Private_Atomic_Type );                           -- ERROR:
                                     -- must apply to full_type_declaration

  type Private_Volatile_Type is private;
  pragma Volatile( Private_Volatile_Type );                       -- ERROR:
                                     -- must apply to full_type_declaration

  type Incomplete_Atomic;
  pragma Atomic( Incomplete_Atomic );                             -- ERROR:
                                     -- must apply to full_type_declaration

  type IndirectA is access Incomplete_Atomic;

  type Incomplete_Atomic is record I,J: IndirectA; end record;
  pragma Atomic( Incomplete_Atomic );                       -- Optional Error

  type Incomplete_Volatile;
  pragma Volatile( Incomplete_Volatile );                         -- ERROR:
                                     -- must apply to full_type_declaration

  type IndirectV is access Incomplete_Volatile;

  type Incomplete_Volatile is record I,J: IndirectV; end record;
  pragma Volatile( Incomplete_Volatile );                         -- OK

  type Atomic_Record_Components is record
    F1, F2, F3 : Natural;
  end record;
  pragma Atomic_Components( Atomic_Record_Components );           -- ERROR:
                                            -- may not apply to record type

  type Volatile_Record_Components is record
    F1, F2, F3 : Natural;
  end record;
  pragma Volatile_Components( Volatile_Record_Components );       -- ERROR:
                                            -- may not apply to record type

  I_Take : exception;

  pragma Atomic( I_Take );                                        -- ERROR:
                                           -- may not apply to an exception

  pragma Volatile( I_Take );                                      -- ERROR:
                                           -- may not apply to an exception

  package Store is
    Whine : constant := -1;
  end Store;

  pragma Atomic( Store );                                         -- ERROR:
                                              -- may not apply to a package

  pragma Volatile( Store );                                       -- ERROR:
                                              -- may not apply to a package

private
  type Private_Record is record
     X,Y,Z: Natural;
  end record;

  type Private_Atomic_Type is range -2**8 .. 0;
  pragma Atomic( Private_Atomic_Type );                           -- OK

  type Private_Volatile_Type is range -8**2 .. 0;
  pragma Volatile( Private_Volatile_Type );                       -- OK

end BXC6001_2;
