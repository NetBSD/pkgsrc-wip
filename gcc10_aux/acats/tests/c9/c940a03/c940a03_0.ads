-- C940A03.A
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
--      Check that a protected object provides coordinated access to
--      shared data.  Check that it can implement a semaphore-like construct
--      controlling access to shared data through procedure parameters to
--      allow a specific maximum number of tasks to run and exclude all
--      others.
--
-- TEST DESCRIPTION:
--      Declare a resource descriptor tagged type.  Extend the type and
--      use the extended type in a protected data structure.
--      Implement a counting semaphore type that can be initialized to a 
--      specific number of available resources.  Declare an entry for 
--      requesting a specific resource and an procedure for releasing the 
--      same resource it.  Declare an object of this (protected) type, 
--      initialized to two resources.  Declare and start three tasks each 
--      of which asks for a resource.  Verify that only two resources are 
--      granted and that the last task in is queued.
--
--      This test models a multi-user operating system that allows a limited
--      number of logins.  Users requesting login are modeled by tasks.
--
--
-- TEST FILES:
--      This test depends on the following foundation code:
--
--         F940A00
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      13 Nov 95   SAIC    Fixed bugs for ACVC 2.0.1
--
--!

package C940A03_0 is
      --Resource_Pkg

  -- General type declarations that will be extended to model available
  -- logins

  type Resource_ID_Type is range 0..10;
  type Resource_Type is tagged record 
    Id : Resource_ID_Type := 0;
  end record;

end C940A03_0;
