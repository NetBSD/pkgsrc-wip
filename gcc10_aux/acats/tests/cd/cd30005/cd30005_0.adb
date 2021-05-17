
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with System.Storage_Elements;
with System.Address_To_Access_Conversions;
package body CD30005_0 is

  use type System.Address;

  procedure TC_Check_Imports is
    S   : External_Func_Ref := CD30005_1'Access;
    I,K : Integer := 99;
  begin

    K := S.all(I);
    if K /= 100 then
      Report.Failed("C program returned" & Integer'Image(K));
    end if;

    I := CD30005_1( I );
    if I /= 100 then
      Report.Failed("C program returned" & Integer'Image(I));
    end if;

    if CD30005_1'Address /= Impdef.CD30005_1_Foreign_Address then
      Report.Failed("Address not that specified");
    end if;

  end TC_Check_Imports;

end CD30005_0;
