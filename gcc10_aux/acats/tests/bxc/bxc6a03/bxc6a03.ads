

     --==================================================================--


with FXC6A00;
with BXC6A03_0;

package BXC6A03 is

   type Volatile_Record2 is new FXC6A00.Record_Type;    -- Allows pass-by-copy.
   pragma Volatile (Volatile_Record2);



   package VolTagAct_NonVolAnc is new BXC6A03_0.Tagged_Type_Ancestor
     ( FXC6A00.Volatile_Tagged );                       -- ERROR: {6;1}
                               -- Ancestor is a non-volatile by-reference type.

   package NonVolTagAct_NonVolAnc is new BXC6A03_0.Tagged_Type_Ancestor
     ( FXC6A00.NonVolatile_Tagged );                    -- OK. {6;1}
                               -- Actual is a non-volatile type.

   package VolTagAct_VolAnc is new BXC6A03_0.Volatile_Tagged_Ancestor
     ( FXC6A00.Volatile_Tagged );                       -- OK. {6;1}
                               -- Ancestor is a volatile type.

   package NonVolTagAct_VolAnc is new BXC6A03_0.Volatile_Tagged_Ancestor
     ( FXC6A00.NonVolatile_Tagged );                    -- ERROR: {6;1}
                               -- Actual is a non-volatile type.

   -- AI05-0218-1, a Binding Interpretation, removed the rule that allowed
   -- the following.
   package VolAct_NonVolRecAnc is new BXC6A03_0.Record_Ancestor
     ( Volatile_Record2 );                              -- ERROR: {6;1}
                -- Ancestor is a non-volatile type that allows pass-by-copy.

end BXC6A03;
