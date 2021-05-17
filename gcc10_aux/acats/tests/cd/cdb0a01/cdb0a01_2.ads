
---------------------------------------------------------------- CDB0A01_2

with FDB0A00.Pool1;
package CDB0A01_2 is

  type Cell;
  type User_Pool_Tree is access Cell;

  for User_Pool_Tree'Storage_Pool use FDB0A00.Pool1.User_Pool;

  type Cell is record
    Data : Character;
    Left,Right : User_Pool_Tree;
  end record;

  procedure Insert( Item: Character; On_Tree : in out User_Pool_Tree );

  procedure Traverse( The_Tree : User_Pool_Tree );

  procedure Defoliate( The_Tree : in out User_Pool_Tree );

end CDB0A01_2;
