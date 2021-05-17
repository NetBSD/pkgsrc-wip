
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with System.Storage_Elements;
with System.Address_To_Access_Conversions;
package body CD30001_0 is

  package Simple_Enum_Type_Ref_Conv is
    new System.Address_To_Access_Conversions(Simple_Enum_Type);

  package Data_Ref_Conv is new System.Address_To_Access_Conversions(Data);

  package Array_W_Aliased_Comps_Ref_Conv is
    new System.Address_To_Access_Conversions(Array_W_Aliased_Comps);

  use type System.Address;
  use type System.Storage_Elements.Integer_Address;
  use type System.Storage_Elements.Storage_Offset;

  procedure TC_Check_Aliased_Addresses is
    use type Simple_Enum_Type_Ref_Conv.Object_Pointer;
    use type Data_Ref_Conv.Object_Pointer;
    use type Array_W_Aliased_Comps_Ref_Conv.Object_Pointer;

  begin

    -- Check the object Aliased_Object

    if Aliased_Object'Address not in System.Address then
      Report.Failed("Aliased_Object'Address not an address");
    end if;

    if Array_W_Aliased_Comps_Ref_Conv.To_Pointer(Aliased_Object'Address)
       /= Aliased_Object'Unchecked_Access then                   
      Report.Failed
                  ("'Unchecked_Access does not match expected address value");
    end if;

    -- Check the element Aliased_Object(1)

    if Data_Ref_Conv.To_Address( Aliased_Object(1)'Access )
       /= Aliased_Object(1)'Address then
      Report.Failed
             ("Array element 'Access does not match expected address value");
    end if;

    -- Check that Array'Address points at the first component...   

    if Array_W_Aliased_Comps_Ref_Conv.To_Address( Aliased_Object'Access )
       /= Aliased_Object(1)'Address then
      Report.Failed
        ("Address of array object does not equal address of first component");
    end if;

    -- Check the components of Aliased_Object(2)

    if Simple_Enum_Type_Ref_Conv.To_Address(
                          Aliased_Object(2).Aliased_Comp_1'Unchecked_Access)
       not in System.Address then
      Report.Failed("Component 2 'Unchecked_Access not a valid address");
    end if;

    if Aliased_Object(2).Aliased_Comp_2'Address not in System.Address then
      Report.Failed("Component 2 not located at a valid address ");
    end if;

  end TC_Check_Aliased_Addresses;

  procedure TC_Check_Specific_Addresses is
    use type System.Address;
    use type System.Storage_Elements.Integer_Address;
    use type Simple_Enum_Type_Ref_Conv.Object_Pointer;
    use type Data_Ref_Conv.Object_Pointer;
    use type Array_W_Aliased_Comps_Ref_Conv.Object_Pointer;
  begin

    -- Check the object Specific_Object

    if System.Storage_Elements.To_Integer(Specific_Object'Address)
       /= System.Storage_Elements.To_Integer(SPPRT13.Variable_Address2) then
      Report.Failed
        ("Specific_Object not at address specified in representation clause");
    end if;

    if Array_W_Aliased_Comps_Ref_Conv.To_Pointer(SPPRT13.Variable_Address2)
       /= Specific_Object'Unchecked_Access then
      Report.Failed("Specific_Object'Unchecked_Access not expected value");
    end if;

    -- Check the element Specific_Object(1)

    if Data_Ref_Conv.To_Address( Specific_Object(1)'Access )
       /= Specific_Object(1)'Address then
      Report.Failed
        ("Specific Array element 'Access does not correspond to the "
         & "elements 'Address");
    end if;

    -- Check that Array'Address points at the first component...

    if Array_W_Aliased_Comps_Ref_Conv.To_Address( Specific_Object'Access )
       /= Specific_Object(1)'Address then
      Report.Failed
        ("Address of array object does not equal address of first component");
    end if;

    -- Check the components of Specific_Object(2)

    if Simple_Enum_Type_Ref_Conv.To_Address(
                                    Specific_Object(1).Aliased_Comp_1'Access)
                                                    not in System.Address then
      Report.Failed("Access value of first record component for object at " &
                    "specific address not a valid address");
    end if;

    if Specific_Object(2).Aliased_Comp_2'Address not in System.Address then
      Report.Failed("Second record component for object at specific " &
                    "address not located at a valid address");
    end if;

  end TC_Check_Specific_Addresses;

--      Check that X'Address produces a useful result when X is an object of
--      a by-reference type.

    type Tagged_But_Not_Exciting is tagged record
      A_Bit_Of_Data : Boolean;
    end record;

    Tagged_Object : Tagged_But_Not_Exciting;

  procedure Muck_With_Addresses( It : in out Tagged_But_Not_Exciting;
                                 Its_Address : in System.Address ) is
  begin
    if It'Address /= Its_Address then
      Report.Failed("Address of object passed by reference does not " &
                    "match address of object passed" );
    end if;
  end Muck_With_Addresses;

  procedure TC_Check_By_Reference_Types is 
  begin
    Muck_With_Addresses( Tagged_Object, Tagged_Object'Address );
  end TC_Check_By_Reference_Types;

end CD30001_0;
