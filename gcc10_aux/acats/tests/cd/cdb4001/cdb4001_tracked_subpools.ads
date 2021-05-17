

with Ada.Containers.Ordered_Maps;
with CDB4001_Serializer_Generic;
with System.Storage_Pools.Subpools;
with System.Storage_Elements;

package CDB4001_Tracked_Subpools is
    -- Subpools which support mapping an address returned from a call
    -- to Allocate back to its enclosing subpool.

    use System.Storage_Pools;
    use System.Storage_Elements;

    type Tracked_Pool
      is new Subpools.Root_Storage_Pool_With_Subpools with private;
    --
    -- Default_Subpool_For_Pool is not overridden, so allocators which
    -- do not provide a subpool will raise Program_Error.

    type Tracked_Subpool is new Subpools.Root_Subpool with private;

    type Tracked_Subpool_Handle is access all Tracked_Subpool'Class;
    for Tracked_Subpool_Handle'Storage_Size use 0;

    function Enclosing_Subpool
      (Pool : Tracked_Pool; Storage_Address : System.Address) return
      Tracked_Subpool_Handle;
    -- If the given address points into a block of storage that was
    -- returned by a previous call to this Pool type's Allocate (and
    -- was not subsequently freed), then return a reference to the
    -- enclosing subpool. Otherwise, the result is undefined.

    function Enclosing_Subpool
      (Pool : Tracked_Pool; Storage_Address : System.Address)
      return Subpools.Subpool_Handle is
      (Subpools.Subpool_Handle
         (Tracked_Subpool_Handle'
            (Enclosing_Subpool (Pool, Storage_Address))));

    function Create_Tracked_Subpool (Pool : in out Tracked_Pool) return
      not null Tracked_Subpool_Handle;

    overriding
    function Create_Subpool (Pool : in out Tracked_Pool)
      return not null Subpools.Subpool_Handle
      is (Subpools.Subpool_Handle (Create_Tracked_Subpool (Pool)));

private
    overriding
    function Storage_Size (Pool : Tracked_Pool) return Storage_Count;

    overriding
    procedure Allocate_From_Subpool (
      Pool : in out Tracked_Pool;
      Storage_Address : out System.Address;
      Size_In_Storage_Elements : Storage_Count;
      Alignment : Storage_Count;
      Subpool : not null Subpools.Subpool_Handle);

    overriding
    procedure Deallocate_Subpool (
      Pool : in out Tracked_Pool;
      Subpool : in out Subpools.Subpool_Handle);

    use Ada.Containers;
    use System;

    type Allocator_Info is
       record
           Storage_Address : System.Address;
           Size_In_Storage_Elements : Storage_Count;
           Subpool : Tracked_Subpool_Handle;
       end record;

    package Allocator_Info_Maps is new Ordered_Maps
      (Key_Type => Address,
       Element_Type => Allocator_Info,
       "<" => "<",
       "=" => "=");

    function Empty_Map return Allocator_Info_Maps.Map is
      (Allocator_Info_Maps.Empty_Map);

    package Serialized_Allocator_Info_Maps is new CDB4001_Serializer_Generic
      (Allocator_Info_Maps.Map, Initial_Value => Empty_Map);

    type Tracked_Pool
      is new Subpools.Root_Storage_Pool_With_Subpools with record
        Allocation_Map : Serialized_Allocator_Info_Maps.Protected_State;
      end record;

    type Allocated_Storage;
    type Allocated_Storage_Ref is access Allocated_Storage;

    type Allocated_Storage (Size : Storage_Offset) is
      limited record
        Next_In_Subpool : Allocated_Storage_Ref;
        Storage : aliased Storage_Array (1 .. Size);
      end record;

    function Nil return Allocated_Storage_Ref is (null);

    package Serialized_Allocated_Storage_Refs is
      new CDB4001_Serializer_Generic (Allocated_Storage_Ref,
                                      Initial_Value => Nil);

    type Tracked_Subpool is new Subpools.Root_Subpool with record
        First_In_Subpool : Serialized_Allocated_Storage_Refs.Protected_State;
        Reclaim_Upon_Deallocation : Boolean := False;
      end record;

end CDB4001_Tracked_Subpools;
