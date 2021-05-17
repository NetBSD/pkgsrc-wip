
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
package body CD10001_0 is

  use type System.Address;

  procedure Assert( Truth : Boolean; Message: String ) is
  begin
    if not Truth then
      TCTouch.Implementation_Check( Message );
    end if;
  end Assert;

  procedure TC_Check_Values is
    Record_Object : Record_To_Layout;
  begin

    Assert(Object_Address'Address = Nonstatic_Entity,
           "Object not at specified address");

    Assert(Object_Alignment'Alignment >= One,
           "Object not at specified alignment");

    Assert(Array_With_Components'Component_Size = A_Reasonable_Size_Value,
           "Array Components not specified size");

-- I don't see how to reliably check this one:
--
--  type Enumeration_1 is (First, Second, Third);
--  for Enumeration_1 use (First => One, Second => Two, Third => Three);

    Assert(Some_Tagged_Type'External_Tag = Tag_String,
           "External_Tag not specified value");
    Assert(Record_Object.Bit_0'First_Bit = Zero,
          "Record object First_Bit not zero");

    Assert(Record_Object.Bit_1'Last_Bit = Four,
          "Record object Last_Bit not four");

    Assert(Object_Size'Size = A_Reasonable_Size_Value,
           "Object size not specified value");

    Assert(Tenths'Small = 1.0 / Two ** Five,
           "Tenths small not specified value");

    Assert(Reference'Storage_Size in 4096 .. -- Four * K
               4096 + ImpDef.Maximum_Adjustment_To_Specified_Storage_Size,
           "Reference storage size not near specified value");
               -- Allow rounding up of the Storage_Size value.

  end TC_Check_Values;

end CD10001_0;
