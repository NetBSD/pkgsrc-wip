
----------------------------------------------------------------- C390011_1

generic
  type Index is (<>);
  type Item is private;
package C390011_1 is

  type List is array(Index range <>) of Item;
  type ListP is access all List;

  type Table is tagged record
    Data: ListP;
  end record;

  function Sort( T: in Table'Class ) return Table'Class;

  function Stable_Table return Table'Class;

  function Table_End( T: Table ) return Index'Base;

end C390011_1;
