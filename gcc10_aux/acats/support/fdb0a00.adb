
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
package body FDB0A00 is

  Largest_Request_On_Record : System.Storage_Elements.Storage_Count := 0;

  procedure Allocate(
    Pool : in out Stack_Heap;
    Storage_Address : out System.Address;
    Size_In_Storage_Elements : in System.Storage_Elements.Storage_Count;
    Alignment : in System.Storage_Elements.Storage_Count) is
      use type System.Storage_Elements.Storage_Offset;
  begin
    TCTouch.Touch('A');  --------------------------------------------------- A

    -- set the pointer to the next correctly aligned available address
    Pool.Avail := Pool.Avail
                + (Alignment - (Pool.Data(Pool.Avail)'Address mod Alignment));

    -- check for overflow
    if Pool.Avail + Size_In_Storage_Elements > Pool.Water_Line then
      raise Pool_Overflow;
    end if;

    -- set the resulting address to that address
    Storage_Address := Pool.Data(Pool.Avail)'Address;

    -- update the housekeeping
    Pool.Avail := Pool.Avail + Size_In_Storage_Elements;
    Largest_Request_On_Record
      := System.Storage_Elements.Storage_Count'Max(Largest_Request_On_Record,
                                                   Size_In_Storage_Elements);
  exception
    when Constraint_Error => raise Pool_Overflow;  -- in case I missed an edge
  end Allocate;

  procedure Deallocate(
    Pool : in out Stack_Heap;
    Storage_Address : in System.Address;
    Size_In_Storage_Elements : in System.Storage_Elements.Storage_Count;
    Alignment : in System.Storage_Elements.Storage_Count) is
  begin
    TCTouch.Touch('D');  --------------------------------------------------- D

    -- for the purposes of validation, the simplest possible implementation
    -- of Deallocate is shown below:

    null;

  end Deallocate;

  function Storage_Size( Pool: in Stack_Heap )
           return System.Storage_Elements.Storage_Count is
  begin
    TCTouch.Touch('S');  --------------------------------------------------- S
    return Pool.Water_Line;
  end Storage_Size;

  function TC_Largest_Request return System.Storage_Elements.Storage_Count is
  begin
    return Largest_Request_On_Record;
  end TC_Largest_Request;

end FDB0A00;
