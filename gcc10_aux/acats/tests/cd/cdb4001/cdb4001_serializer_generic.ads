-- CDB4001.A
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
--      Check allocation and deallocation of objects using subpools.
--
-- TEST DESCRIPTION:
--
--      The test structure is
--         1) Do a bunch of allocators;
--         2) Deallocate a few using Unchecked_Deallocation;
--         3) Deallocate some more using Unchecked_Deallocate_Subpool;
--         4) Exit the scope so that the remaining allocated objects get
--            finalized.
--
-- CHANGE HISTORY:
--       5 Jan 12   SWB     Initial pre-release version.
--       6 Jan 12   SWB     Correction to assert routine.
--      23 Mar 14   SWB     Fixed test errors.
--      24 Mar 14   RLB     Created ACATS 4.0 version, adding missing headers.
--!


generic
    type State is limited private;
    with function Initial_Value return State;
package CDB4001_Serializer_Generic is
    type Null_Record is null record;

    protected type Protected_State is
        function  Read (Op : access procedure (Current_State : State))
          return Null_Record;

        procedure Update (Op : access procedure (Current_State : in out State));
    private
        Current_State : State := Initial_Value;
    end Protected_State;
end CDB4001_Serializer_Generic;
