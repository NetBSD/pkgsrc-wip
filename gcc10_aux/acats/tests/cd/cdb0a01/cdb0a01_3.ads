
---------------------------------------------------------------- CDB0A01_3

with FDB0A00.Pool1;
package CDB0A01_3 is

  type Cell;
  type System_Pool_Tree is access Cell;

  for System_Pool_Tree'Storage_Size use 2000;

  -- assumptions: Cell is <= 20 storage_units
  --              Tree building exercise requires O(15) cells
  --              2000 > 20 * 15 by a generous margin

  type Cell is record
    Data: Character;
    Left,Right : System_Pool_Tree;
  end record;

  procedure Insert( Item: Character; On_Tree : in out System_Pool_Tree );

  procedure Traverse( The_Tree : System_Pool_Tree );

  procedure Defoliate( The_Tree : in out System_Pool_Tree );

end CDB0A01_3;
