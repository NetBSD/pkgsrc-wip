-- BDB4001.A
--
--                             Grant of Unlimited Rights
--
--     The Ada Conformity Assessment Authority (ACAA) holds unlimited
--     rights in the software and documentation contained herein. Unlimited
--     rights are the same as those granted by the U.S. Government for older
--     parts of the Ada Conformity Assessment Test Suite, and are defined
--     in DFAR 252.227-7013(a)(19). By making this public release, the ACAA
--     intends to confer upon all recipients unlimited rights equal to those
--     held by the ACAA. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever, and
--     to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS. THE ACAA MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--*
-- OBJECTIVE:
--      Check that a specification of a storage pool is illegal if the
--      storage pool supports subpools and:
--          (A) The access type is statically deeper than the storage pool
--              object;
--          (B) The storage pool object is a part of a formal parameter;
--          (C) The storage pool object is a part of the dereference of a
--              non-library level general access type;
--          (D) The access type is a general access type.
--      Part 1: Non-generic uses.
--
-- TEST DESCRIPTION:
--
--      The test declares a storage pool that supports subpools (based on the
--      pool from test CDB4001), and then tries a number of illegal uses.
--      The rules are 13.11.4(22-23/3), which originated in AI12-0111-3 but
--      mostly appear in a fix-up AI05-0252-1.
--
--      The intent of this rule is that the storage pool object and the access
--      type are defined in the same static scope level. This ensures that
--      the designated type is at worse declared in the same scope as the
--      pool object. The language only defines an inequality relationship for
--      static levels, thus the RM talks about "not statically deeper" rather
--      than an equality of level. Note that it is impossible to use a
--      more-nested object, as such objects aren't visible in the declarative
--      list of the access type, so since a less nested item is not allowed,
--      the same scope is the only remaining choice.
--
--      The part of a formal parameter rule exists as part of this same
--      requirement, as the actual value necessarily belongs to a dynamically
--      less nested level. For non-library-level general access types, we don't
--      know the exact level of the object, so we assume it is not local and
--      reject the usage. These types are fairly rare, so this case is unlikely
--      (but note that anonymous access types are general access types and thus
--      are subject to these rules -- those are mostly of interest for the
--      dynamic verion of these rules, tested elsewhere).
--
--
-- CHANGE HISTORY:
--      26 Dec 19   RLB     Created test.
--!


with System.Storage_Pools.Subpools;
with System.Storage_Elements;

package BDB4001_Tracked_Subpools is
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

    use System;

    type Allocator_Info is
       record
           Storage_Address : System.Address;
           Size_In_Storage_Elements : Storage_Count;
           Subpool : Tracked_Subpool_Handle;
       end record;

    type AI_List is array (1..10) of Allocator_Info;

    type Tracked_Pool
      is new Subpools.Root_Storage_Pool_With_Subpools with record
        Allocation_Map : AI_List;
      end record;

    type Allocated_Storage;
    type Allocated_Storage_Ref is access Allocated_Storage;

    type Allocated_Storage (Size : Storage_Offset) is
      limited record
        Next_In_Subpool : Allocated_Storage_Ref;
        Storage : aliased Storage_Array (1 .. Size);
      end record;

    type Tracked_Subpool is new Subpools.Root_Subpool with record
        First_In_Subpool : Allocated_Storage_Ref := null;
        Reclaim_Upon_Deallocation : Boolean := False;
      end record;

end BDB4001_Tracked_Subpools;
