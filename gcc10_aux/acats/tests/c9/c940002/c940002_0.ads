-- C940002.A
--
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
--      Check that a protected object provides coordinated access to shared 
--      data.  Check that it can implement a semaphore-like construct using a
--      parameterless procedure which allows a specific maximum number of tasks
--      to run and excludes all others
--
-- TEST DESCRIPTION:
--      Implement a counting semaphore type that can be initialized to a 
--      specific number of available resources.  Declare an entry for 
--      requesting a resource and a procedure for releasing it.  Declare an 
--      object of this type, initialized to two resources.  Declare and start 
--      three tasks each of which asks for a resource.  Verify that only two 
--      resources are granted and that the last task in is queued.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!


package C940002_0 is
     -- Semaphores

  protected type Semaphore_Type (Resources_Available : Integer :=1) is
    entry Request;
    procedure Release;
    function Available return Integer;
  private
    Currently_Available : Integer := Resources_Available;
  end Semaphore_Type;

  Max_Resources : constant Integer := 2;
  Resource      : Semaphore_Type (Max_Resources);

end C940002_0;
