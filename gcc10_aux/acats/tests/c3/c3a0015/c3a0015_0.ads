-- C3A0015.A
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
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--    Check that a derived access type has the same storage pool as its
--    parent.  (Defect Report 8652/0012, Technical Corrigendum 3.10(7/1)).
--
-- CHANGE HISTORY:
--    24 JAN 2001   PHL   Initial version.
--    29 JUN 2001   RLB   Reformatted for ACATS.
--
--!
with System.Storage_Elements;
use System.Storage_Elements;
with System.Storage_Pools;
use System.Storage_Pools;
package C3A0015_0 is

    type Pool (Storage_Size : Storage_Count) is new Root_Storage_Pool with
	record
	    First_Free : Storage_Count := 1;
	    Contents : Storage_Array (1 .. Storage_Size);
	end record;

    procedure Allocate (Pool : in out C3A0015_0.Pool;
			Storage_Address : out System.Address;
			Size_In_Storage_Elements : in Storage_Count;
			Alignment : in Storage_Count);

    procedure Deallocate (Pool : in out C3A0015_0.Pool;
			  Storage_Address : in System.Address;
			  Size_In_Storage_Elements : in Storage_Count;
			  Alignment : in Storage_Count);

    function Storage_Size (Pool : in C3A0015_0.Pool) return Storage_Count;

end C3A0015_0;
