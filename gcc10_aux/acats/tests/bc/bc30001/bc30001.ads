

     --===================================================================--


with Ada.Tags;

with BC30001_0;
with BC30001_1;
generic
   type Formal_Private is tagged private;
   type Formal_Derived is new BC30001_0.Tagged_Type with private;
package BC30001 is

-- Check that a tagged actual type may be passed to a non-tagged formal
-- private type, and that a non-extension type may be derived from the
-- actual in the private part or body of an instance.

   package Priv_Derivation is new BC30001_1.Derived_In_Private_Part
      (BC30001_0.Tagged_Type);                                        -- OK.

   package Body_Derivation is new BC30001_1.Derived_In_Body
      (BC30001_0.Tagged_Type);                                        -- OK.



-- Check that a tagged actual type may be passed to a non-tagged formal
-- private type, and that a non-extension type may *not* be derived from the
-- actual in the visible part of an instance.

   package Visi_Deriv_01 is new BC30001_1.Derived_In_Visible_Part
     (BC30001_0.Tagged_Type);                                         -- ERROR:
                      -- Type derived in instance does not have extension part.

   package Visi_Deriv_02 is new BC30001_1.Derived_In_Visible_Part
     (BC30001_0.Rec_Ext);                                             -- ERROR:
                      -- Type derived in instance does not have extension part.

   package Visi_Deriv_03 is new BC30001_1.Derived_In_Visible_Part
     (BC30001_0.Pri_Ext);                                             -- ERROR:
                      -- Type derived in instance does not have extension part.

   package Visi_Deriv_04 is new BC30001_1.Derived_In_Visible_Part
     (Formal_Private);                                                -- ERROR:
                      -- Type derived in instance does not have extension part.

   package Visi_Deriv_05 is new BC30001_1.Derived_In_Visible_Part
     (Formal_Derived);                                                -- ERROR:
                      -- Type derived in instance does not have extension part.


-- Check that a non-tagged type derived from a tagged parent type in the
-- private part of an instance is not treated as tagged outside the instance.

   Object    : Priv_Derivation.Derived_Type;

   Var       : Priv_Derivation.Derived_Type := BC30001_0.Func;        -- ERROR:
                      -- Function not dispatching; function returns wrong type.

   ClassWide : BC30001_0.Tagged_Type'Class := Object;                 -- ERROR:
                                         -- Object is not in Tagged_Type'Class.

   Tag_Val   : Ada.Tags.Tag := Priv_Derivation.Derived_Type'Tag;      -- ERROR:
                                   -- Attribute not defined for untagged types.

   type Rec_Ext is new Priv_Derivation.Derived_Type with null record; -- ERROR:
                                                  -- Parent type is not tagged.

end BC30001;
