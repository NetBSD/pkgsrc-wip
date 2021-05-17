-- C760013.A
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
--    Check that Initialize is not called for default-initialized subcomponents
--    of the ancestor type of an extension aggregate.  (Defect Report
--    8652/0021, Technical Corrigendum 7.6(11/1)).
--
-- CHANGE HISTORY:
--    25 JAN 2001   PHL   Initial version.
--    29 JUN 2001   RLB   Reformatted for ACATS.
--
--!
with Ada.Finalization;
use Ada.Finalization;
package C760013_0 is

    type Ctrl1 is new Controlled with
	record
	    C : Integer := 0;
	end record;
    type Ctrl2 is new Controlled with
	record
	    C : Integer := 0;
	end record;

    procedure Initialize (Obj1 : in out Ctrl1);
    procedure Initialize (Obj2 : in out Ctrl2);

end C760013_0;
