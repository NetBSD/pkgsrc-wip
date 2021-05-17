
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body C390011_1 is

    -- In a user program this package would DO something

  function Sort( T: in Table'Class ) return Table'Class is
  begin
   return T;
  end Sort;

  Empty : Table'Class := Table'( Data => null );

  function Stable_Table return Table'Class is
  begin
    return Empty;
  end Stable_Table;

  function Table_End( T: Table ) return Index'Base is
  begin
    return Index'Base( T.Data.all'Last );
  end Table_End;

end C390011_1;
