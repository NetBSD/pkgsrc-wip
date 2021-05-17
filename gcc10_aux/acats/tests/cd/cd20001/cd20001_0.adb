
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with TCTouch;
package body CD20001_0 is

  procedure TC_Check_Values is
    My_Word      : Wordlong_Bool_Array := (others => False);

    Cited_Unit   : Spec_Rep_Components := 0;

    Packed_Array : Packed_Array_Def_Components := (others => 0);

    Cited_Packed : Packed_Array_Spec_Components := (others => 0);

  begin
    TCTouch.Assert( My_Word'Size = System.Word_Size,
       "pragma Pack on array of Booleans does not pack one Boolean per bit" );

    TCTouch.Assert( My_Word'Component_Size = 1,
                    "size of Boolean array component not 1 bit");

    TCTouch.Assert( Cited_Unit'Size = System.Storage_Unit,
                    "Object specified to be Storage_Unit bits not " &
                    "Storage_Unit bits in size");

    TCTouch.Assert( Packed_Array'Component_Size <= System.Storage_Unit,
                    "Packed array component expected to be less than or " &
                    "equal to Storage_Unit bits in size is greater than " &
                    "Storage_Unit bits in size");

    TCTouch.Assert( Cited_Packed'Component_Size = System.Storage_Unit,
                    "Array component specified to be Storage_Unit " &
                    "bits not Storage_Unit bits in size");

  end TC_Check_Values;

end CD20001_0;
