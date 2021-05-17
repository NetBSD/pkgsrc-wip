-- C950001.A
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
--    The ACAA has created and maintains the Ada Conformity Assessment Test
--    Suite for the purpose of conformity assessments conducted in accordance
--    with the International Standard ISO/IEC 18009 - Ada: Conformity
--    assessment of a language processor. This test suite should not be used
--    to make claims of conformance unless used in accordance with
--    ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
--
-- OBJECTIVE:
--      Check that primitive procedures of synchronized interfaces with
--      a Synchronization aspect can be completed by a procedure, protected
--      procedure or entry as specified, and check correct mutual exclusion.
--
-- TEST DESCRIPTION:
--      We first define a synchronized interface using various synchronization
--      specifications. We then implement that interface with an appropriate
--      protected object. We finally then test the interface by making
--      dispatching calls through the interface and verify that each has the
--      correct behavior.
--
-- CHANGE HISTORY:
--      16 Nov 13   GRB     Initial version.
--      26 Nov 13   RLB     Added headers, cleaned up capitalization of
--                          messages.
--      21 Apr 14   RLB     Added to ACATS, added dispatching calls for
--                          realism. Replaced Volatile counter with PO.
--!

package C950001_0 is
   type Spinlock is synchronized interface;

   procedure Unlock (L : in out Spinlock) is abstract
      with Synchronization => By_Protected_Procedure;
   procedure Lock (L : in out Spinlock) is abstract
      with Synchronization => By_Entry;
   procedure Try_Lock  (L : in out Spinlock; Success : out Boolean) is abstract
      with Synchronization => Optional;
   procedure Unlock_2 (L : in out Spinlock) is abstract
      with Synchronization => Optional;
   procedure Lock_2 (L : in out Spinlock) is abstract
      with Synchronization => Optional;

   protected type Lock_Type is new Spinlock with
      procedure Unlock;   --  Synchronization => By_Protected_Procedure
      procedure Unlock_2; --  Synchronization => Optional
      entry Lock;         --  Synchronization => By_Entry
      entry Lock_2;       --  Synchronization => Optional
   private
      Unlocked : Boolean := True;
   end Lock_Type;

   procedure Try_Lock
     (L       : in out Lock_Type;
      Success : out Boolean) with Synchronization => Optional;

   function Get_Lock return Spinlock'Class;

end C950001_0;
