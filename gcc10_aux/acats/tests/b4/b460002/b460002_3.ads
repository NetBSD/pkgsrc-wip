

     --==================================================================--


with B460002_0;
generic
   type Formal_Disc_Record_Type is new B460002_0.Disc_Record_Type;
   Formal_AccDisc : in out Formal_Disc_Record_Type;
package B460002_3 is

   -- The following conversion is illegal in an instance if the level of the
   -- actual object corresponding to Formal_AccDisc is deeper than that of
   -- B460002_0.External_Target_Type_L0 (because the operand type is the
   -- anonymous type of an access discriminant, the level of which is
   -- that of the containing object): 

   Target : B460002_0.External_Target_Type_L0 :=
            B460002_0.External_Target_Type_L0(Formal_AccDisc.D);

end B460002_3;
