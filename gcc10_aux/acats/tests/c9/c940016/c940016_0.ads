-- C940016.A
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
--      Check that an Unchecked_Deallocation of a protected object
--      performs the required finalization on the protected object.
--
-- TEST DESCRIPTION:
--      Test that finalization takes place when an Unchecked_Deallocation
--      deallocates a protected object with queued callers. 
--      Try protected objects that have no other finalization code and
--      protected objects with user defined finalization.
--
--
-- CHANGE HISTORY:
--      16 Jan 96   SAIC    ACVC 2.1
--      10 Jul 96   SAIC    Fixed race condition noted by reviewers.
--
--!


with Ada.Finalization;
package C940016_0 is
    Verbose : constant Boolean := False;
    Finalization_Occurred : Boolean := False;

    type Has_Finalization is new Ada.Finalization.Limited_Controlled with
          record
             Placeholder : Integer;
          end record;
    procedure Finalize (Object : in out Has_Finalization);
end C940016_0;
