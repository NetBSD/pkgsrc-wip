-- CXAC002.A
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
--      Check that the subprograms defined in package Ada.Streams.Stream_IO
--      are accessible, and that they provide the appropriate functionality.
--
-- TEST DESCRIPTION:
--      This test simulates a user filter designed to capitalize the
--      characters of a string.  It utilizes a variety of the subprograms
--      contained in the package Ada.Streams.Stream_IO.
--      Its purpose is to demonstrate the use of a variety of the capabilities
--      found in the Ada.Streams.Stream_IO package.
--
-- APPLICABILITY CRITERIA:
--      This test is applicable to all implementations capable of supporting
--      external Stream_IO files.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      14 Nov 95   SAIC    Corrected visibility problems; corrected
--                          subtest validating result from function Name
--                          for ACVC 2.0.1.
--      05 Oct 96   SAIC    Removed calls to Close/Open in test and replaced
--                          them with a single call to Reset (per AI95-0001)
--      26 Feb 97   PWB.CTA Allowed for non-support of some IO operations.
--      09 Feb 01   RLB     Corrected non-support check to avoid unintended
--                          failures.
--!

package CXAC002_0 is

   -- This function searches for the first instance of a specified substring
   -- within a specified string, returning boolean result. (Case insensitive
   -- analysis)

   function Find (Str : in String; Sub : in String) return Boolean;

end CXAC002_0;
