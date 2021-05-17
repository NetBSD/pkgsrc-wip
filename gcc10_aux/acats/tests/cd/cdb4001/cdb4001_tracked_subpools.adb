

with Ada.Unchecked_Deallocation;

package body CDB4001_Tracked_Subpools is

    function Enclosing_Subpool
      (Pool : Tracked_Pool; Storage_Address : System.Address) return
      Tracked_Subpool_Handle is
        use Allocator_Info_Maps;
        use Serialized_Allocator_Info_Maps;

        Result : Tracked_Subpool_Handle;

        procedure Set_Result (Mapping : Map) is
            Position : constant Cursor
              := Floor (Mapping, Storage_Address);
            Info : Allocator_Info;
        begin
            Result := null;
            if Position /= No_Element then
                Info := Element (Position);
                if Storage_Address < Info.Storage_Address
                                     + Info.Size_In_Storage_Elements then
                    Result := Info.Subpool;
                end if;
            end if;
        end Set_Result;

        Ignored : Null_Record renames
          Pool.Allocation_Map.Read (Set_Result'Access);
    begin
        return Result;
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

        use Allocator_Info_Maps;
        use Serialized_Allocator_Info_Maps;

        procedure Update_Pool (Mapping : in out Map) is
        begin
            Insert (Mapping,
                    Unaligned_Address,
                    Allocator_Info'(Unaligned_Address,
                                    Allocated.Size,
                                    Tracked_Subpool));
        end Update_Pool;

        procedure Update_Allocation_Ref (Ref : in out Allocated_Storage_Ref) is
        begin
            Allocated.Next_In_Subpool := Ref;
            Ref := Allocated;
        end Update_Allocation_Ref;

    begin
        Storage_Address :=
          Unaligned_Address +
          (if Misalignment /= 0 then Alignment - Misalignment else 0);

        pragma Assert (Alignment = 0 or else
                       Storage_Address mod Alignment = 0);

        Pool.Allocation_Map.Update (Update_Pool'Access);
        Tracked_Subpool.First_In_Subpool.Update (Update_Allocation_Ref'Access);
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

        procedure Set_Rover (Ref : in out Allocated_Storage_Ref) is
        begin
            Rover := Ref;
            Ref := null;
        end Set_Rover;

    begin
        Tracked_Subpool.First_In_Subpool.Update (Set_Rover'Access);

        while Rover /= null loop
            declare
                use Allocator_Info_Maps;

                procedure Update_Pool (Mapping : in out Map) is
                begin
                    -- Empty map indicates enclosing pool has been finalized.
                    if not Is_Empty (Mapping) then
                        Delete (Mapping, Rover.Storage'Address);
                    end if;
                end Update_Pool;
            begin
                Pool.Allocation_Map.Update (Update_Pool'Access);
            end;

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
end CDB4001_Tracked_Subpools;
