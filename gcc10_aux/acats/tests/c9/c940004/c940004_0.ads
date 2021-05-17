-- C940004.A
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
-- TEST OBJECTIVE:
--      Check that a protected record can be used to control access to
--      resources (data internal to the protected record).
--
-- TEST DESCRIPTION:
--      Declare a resource descriptor tagged type.  Extend the type and
--      use the extended type in a protected data structure.
--      Implement a binary semaphore type.  Declare an entry for
--      requesting a specific resource and an procedure for releasing the
--      same resource.  Declare an object of this (protected) type.
--      Declare and start three tasks each of which asks for a resource
--      when directed to.  Verify that resources are properly allocated
--      and deallocated.
--
--
-- CHANGE HISTORY:
--
--      12 DEC 93   SAIC    Initial PreRelease version
--      23 JUL 95   SAIC    Second PreRelease version
--      16 OCT 95   SAIC    ACVC 2.1
--      13 MAR 03   RLB     Fixed race condition in test.
--
--!

package C940004_0 is
-- Resource_Pkg

   type ID_Type is new Integer range 0..10;
   type User_Descriptor_Type is tagged record
      Id : ID_Type := 0;
   end record;

end C940004_0; -- Resource_Pkg
