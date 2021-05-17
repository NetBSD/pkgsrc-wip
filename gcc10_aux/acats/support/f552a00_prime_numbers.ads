--  F552A00.A
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
--
--*
--
--  FOUNDATION DESCRIPTION:
--      This package declares packages that contain iterator_types that may
--      be used for tests that exercise General Loop Iteration for both
--      generalized iterators and container element iterators.
--
--  CHANGE HISTORY:
--      30 Sep 13   BJM     Created foundation.
--      31 May 14   RLB     Readied for release: added foundation prefix to
--                          each package name.
--      01 Jun 14   RLB     Renamed Call_History to TC_Call_History to reflect
--                          that the history exists to check test objectives
--                          rather than the usage-oriented structure of the
--                          rest of the code.
--      02 Jun 14   RLB     Changed indexing information for Sparse_Arrays to
--                          counters to allow testing additional objectives.
--      16 Jun 14   RLB     Corrected sparse arrays to not require variables
--                          for iterators. Removed cursor creation/destruction
--                          counts (as those are unreliable in the face of
--                          allowed optimizations).
--      17 Jul 15   RLB     Replaced Constant_Reference for Bingo_Balls with
--                          The_Call to eliminate accessibility failure.
--
--!

with Ada.Iterator_Interfaces;
with Ada.Strings.Unbounded; use Ada;

package F552A00_Prime_Numbers is

   --  This package defines a simple Iterator Type that represents a
   --  set of prime numbers from 1 to N.

   function Is_Prime (Value : Natural) return Boolean;

   package Prime_Number_Iterator is new Ada.Iterator_Interfaces (
      Cursor      => Natural,
      Has_Element => Is_Prime);

   type Prime_Number_Set (Max_Value : Natural) is new
     Prime_Number_Iterator.Forward_Iterator with null record;
   --  A Prime_Number_Set represents all the prime numbers between
   --  1 and Max_Value. Two is not considered to be a prime number.
   --  Max_Value may or may not be a prime number

   overriding function First (Object : Prime_Number_Set) return Natural;

   overriding function Next
     (Object : Prime_Number_Set;
      Value  : Natural)
      return   Natural;

   function Iterate
     (Set  : Prime_Number_Set)
      return Prime_Number_Iterator.Forward_Iterator'Class;

   TC_Call_History : Strings.Unbounded.Unbounded_String;
   --
   --  A string capturing the call sequence to the above subprogams.
   --  The following gets appended to the history for the above calls;
   --      Iterate  => I
   --      First    => 1
   --      Next     => N( nn)        where nn is the next prime number
   --      Is_Prime => H:{T|F}( nn)  H is the Has_Element function
   --                                  T means Has_Element returned True
   --                                  F means Has_Element returns False
   --                                  nn is the current prime number

end F552A00_Prime_Numbers;
