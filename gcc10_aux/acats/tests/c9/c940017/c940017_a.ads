-- C940017.A
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
--
-- OBJECTIVE:
--     Check that dispatching calls can be made for subprograms inherited from
--     a progenator for a protected type and implemented by protected
--     operations of the type.
--
-- TEST DESCRIPTION:
--     We imagine a protected interface describing an abstract queue and
--     with concrete implementations supporting various numbers of items
--     and various policies for handling empty/full queues (exceptions,
--     blocking, and so on). [This shouldn't be too hard to imagine, it's
--     essentially how the queue containers work, see RM A.18.28.]
--
--     We then create a class-wide usage of queues, and check using TcTouch
--     to ensure that appropriate routines are called. We only use the
--     environment task here for simplicity.
--
-- CHANGE HISTORY:
--    27 Jun 2019   RLB   Created test.
--
--!

with Report;
package C940017_A is

   type Queue_Interface is protected interface;

   procedure Enqueue (Q : in out Queue_Interface; Item : in Integer)
                                                              is abstract;

   procedure Dequeue (Q : in out Queue_Interface; Item : out Integer)
                                                              is abstract;

   function Item_Count (Q : in Queue_Interface) return Natural is abstract;

end C940017_A;
