

with Ada.Unchecked_Deallocation;

package body BDB4001_Tracked_Subpools is

    function Enclosing_Subpool
      (Pool : Tracked_Pool; Storage_Address : System.Address) return
      Tracked_Subpool_Handle is
    begin
        for I in Pool.Allocation_Map'Range loop
	   declare
              Info : Allocator_Info renames Pool.Allocation_Map(I);
           begin
                if Storage_Address >= Info.Storage_Address and then
                   Storage_Address < Info.Storage_Address
                                     + Info.Size_In_Storage_Elements then
                    return Info.Subpool;
                end if;
           end;
        end loop;
        -- Not found:
        return null;
    end Enclosing_Subpool;

    type Tracked_Subpool_Ref is access all Tracked_Subpool;

    function Create_Tracked_Subpool (Pool : in out Tracked_Pool) return
      not null Tracked_Subpool_Handle is
        use Subpools;
    begin
        return Result : constant not null Tracked_Subpool_Handle :=
          Tracked_Subpool_Handle (Tracked_Subpool_Ref'(new Tracked_Subpool)) do
           Set_Pool_Of_Subpool (Subpool_Handle (Result), Pool);
           Result.Reclaim_Upon_Deallocation := True;
        end return;
    end Create_Tracked_Subpool;

    function Storage_Size (Pool : Tracked_Pool) return Storage_Count is
    begin
        return Storage_Size (Allocated_Storage_Ref'Storage_Pool); -- ???
    end Storage_Size;

    procedure Allocate_From_Subpool (
      Pool : in out Tracked_Pool;
      Storage_Address : out System.Address;
      Size_In_Storage_Elements : Storage_Count;
      Alignment : Storage_Count;
      Subpool : not null Subpools.Subpool_Handle) is

        Allocated : constant Allocated_Storage_Ref :=
          new Allocated_Storage
                (Size => Size_In_Storage_Elements +
                         Storage_Count'Max (Alignment - 1, 0));

        Unaligned_Address : constant System.Address
          := Allocated.Storage'Address;

        Misalignment : constant Storage_Offset
          := (if Alignment = 0 then 0 else Unaligned_Address mod Alignment);

        Tracked_Subpool : constant Tracked_Subpool_Handle :=
           Tracked_Subpool_Handle (Subpool);

    begin
        Storage_Address :=
          Unaligned_Address +
          (if Misalignment /= 0 then Alignment - Misalignment else 0);

        pragma Assert (Alignment = 0 or else
                       Storage_Address mod Alignment = 0);

        -- Incomplete implementation here (not relevant for a B-Test).
        -- Need to insert the mapping into Pool.Allocation_Map.

        Allocated.Next_In_Subpool := Tracked_Subpool.First_In_Subpool;
        Tracked_Subpool.First_In_Subpool := Allocated;

    end Allocate_From_Subpool;

    procedure Deallocate_Subpool (
      Pool : in out Tracked_Pool;
      Subpool : in out Subpools.Subpool_Handle) is
        procedure Free is new Ada.Unchecked_Deallocation
          (Allocated_Storage, Allocated_Storage_Ref);
        procedure Free is new Ada.Unchecked_Deallocation
          (Tracked_Subpool, Tracked_Subpool_Ref);

        Tracked_Subpool : Tracked_Subpool_Ref :=
           Tracked_Subpool_Ref (Subpool);

        Rover : Allocated_Storage_Ref;

    begin
        Rover := Tracked_Subpool.First_In_Subpool;
        Tracked_Subpool.First_In_Subpool := null;

        while Rover /= null loop
            -- Incomplete implementation here (not relevant for a B-Test).
            -- Need to remove Rover from the Allocated_Map.

            declare
                Prev : Allocated_Storage_Ref := Rover;
            begin
                Rover := Rover.Next_In_Subpool;
                Free (Prev);
            end;
        end loop;
        Subpool := null;
        if Tracked_Subpool.Reclaim_Upon_Deallocation then
            Free (Tracked_Subpool);
        end if;
    end Deallocate_Subpool;
end BDB4001_Tracked_Subpools;
