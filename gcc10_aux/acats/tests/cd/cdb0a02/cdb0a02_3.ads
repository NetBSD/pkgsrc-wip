
---------------------------------------------------------------- CDB0A02_3

-- This package is essentially identical to CDB0A02_2, except that the size
-- of a cell is significantly larger.  This is used to check that different
-- access types may share a single pool

with FDB0A00.Pool2;
package CDB0A02_3 is

  type Large_Cell;
  type Large_Tree is access Large_Cell;

  for Large_Tree'Storage_Pool use FDB0A00.Pool2.Pond;  -- second usage

  type Large_Cell is record
    Data: Character;
    Extra_Data : String(1..2);
    Left,Right : Large_Tree;
  end record;

  procedure Insert( Item: Character; On_Tree : in out Large_Tree );

  procedure Traverse( The_Tree : Large_Tree );

  procedure Defoliate( The_Tree : in out Large_Tree );

end CDB0A02_3;
