

     --==================================================================--


with B460002_0;
generic
   type Designated_Type is new B460002_0.Tagged_Type with private;

   type Formal_Target_Type is access all Designated_Type;

   type Formal_Disc_Record_Type is new B460002_0.Disc_Record_Type;
   Formal_AccDisc: in out Formal_Disc_Record_Type;
package B460002_6 is

   -- The following conversion is illegal in an instance if the level of the
   -- actual object corresponding to Formal_AccDisc is deeper than that of
   -- the actual corresponding to Formal_Target_Type (because the operand type
   -- is the anonymous type of an access discriminant, the level of which is
   -- that of the containing object): 

private

   Target : Formal_Target_Type := Formal_Target_Type(Formal_AccDisc.D);

end B460002_6;
