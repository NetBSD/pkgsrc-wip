-- C761002.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making
--     this public release, the Government intends to confer upon all
--     recipients unlimited rights  equal to those held by the Government.
--     These rights include rights to use, duplicate, release or disclose the
--     released technical data and computer software in whole or in part, in
--     any manner and for any purpose whatsoever, and to have or permit others
--     to do so.
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
--      Check that objects of a controlled type that are created
--      by an allocator for a named access type are finalized at the
--      appropriate time.  In particular, check that such objects are
--      not finalized due to completion of the master in which they were
--      allocated if the corresponding access type is declared outside of
--      that master.
--
--      Check that Unchecked_Deallocation of a controlled
--      object causes finalization of that object.
--
-- TEST DESCRIPTION:
--      This test derives a type from Ada.Finalization.Controlled, and
--      declares named access types to that type in various scope scenarios.
--      The dispatching procedure Finalize is redefined for the derived
--      type to perform a check that it has been called at the
--      correct time.  This is accomplished using a global variable
--      which indicates what state the software is currently
--      executing.  The test utilizes the TCTouch facilities to
--      verify that Finalize is called the correct number of times, at
--      the correct times.  Several calls are made to validate passing
--      the null string to check that Finalize has NOT been called at
--      that point.
--
--      Finalization is supposed to happen (reverse) at the first freezing
--      point of the access type. The test keeps other finalization out of
--      each scope so this doesn't matter.
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0.
--      10 Apr 14   RLB     Adjusted objective for Ada 2012 to reflect that
--                          the rules for named and anonymous access types
--                          differ (this test only covers named access types).


--
--!

with Ada.Finalization;
package C761002_0 is
  type Global is new Ada.Finalization.Controlled with null record;
  procedure Finalize( It: in out Global );

  type Second is new Ada.Finalization.Limited_Controlled with null record;
  procedure Finalize( It: in out Second );
end C761002_0;
