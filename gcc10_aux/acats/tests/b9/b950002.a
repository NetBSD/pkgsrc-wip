-- B950002.A
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
--      a Synchronization aspect cannot be completed with the wrong kind
--      of callable entity, nor can they have completions with a conflicting
--      Synchronization aspect.
--
-- CHANGE HISTORY:
--      16 Nov 13   GRB     Initial version
--      26 Nov 13   RLB     Added missing headers, fixed objective.
--      32 Apr 14   RLB     Added additional case, renamed for ACATS 4.0.
--!

package B950002 is
   type Spinlock is synchronized interface;

   procedure Unlock (L : in out Spinlock) is abstract
      with Synchronization => By_Protected_Procedure;
   procedure Lock (L : in out Spinlock) is abstract
      with Synchronization => By_Entry;
   procedure Try_Lock  (L : in out Spinlock; Success : out Boolean) is abstract
      with Synchronization => Optional;
   procedure Unlock_2 (L : in out Spinlock) is abstract
      with Synchronization => By_Protected_Procedure;
   procedure Lock_2 (L : in out Spinlock) is abstract
      with Synchronization => Optional;
   procedure Lock_3 (L : in out Spinlock) is abstract
      with Synchronization => By_Entry;
   procedure Lock_4 (L : in out Spinlock) is abstract
      with Synchronization => Optional;

   protected type Lock_Type is new Spinlock with
      entry Unlock;                       -- ERROR: Must be protected procedure
      procedure Unlock_2
        with Synchronization => Optional; -- ERROR: Should be By_Prot_Proc
      procedure Lock;                     -- ERROR: Must be entry
      procedure Lock_2
        with Synchronization => By_Entry; -- ERROR: Is procedure
   private
      Unlocked : Boolean := True;
   end Lock_Type;

   procedure Try_Lock
     (L       : in out Lock_Type;
      Success : out Boolean)
   with Synchronization => By_Entry;      -- ERROR: Is procedure

   procedure Lock_3
     (L       : in out Lock_Type)
   with Synchronization => Optional;      -- ERROR: Original is By_Entry

   procedure Lock_4
     (L       : in out Lock_Type)
   with Synchronization => Optional;      -- OK.

end B950002;
