-- C930001.A
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
--      Check when a dependent task and its master both
--      terminate as a result of a terminate alternative that
--      finalization is performed and that the finalization is
--      performed in the proper order.
--
-- TEST DESCRIPTION:
--      A controlled type with finalization is used to determine
--      the order in which finalization occurs.  The finalization
--      procedure records the identity of the object being
--      finalized.
--      Two tasks, one nested inside the other, both contain 
--      objects of the above finalization type.  These tasks
--      cooperatively terminate so the termination and finalization
--      order can be noted.
--
--
-- CHANGE HISTORY:
--      08 Jan 96   SAIC    ACVC 2.1
--      09 May 96   SAIC    Addressed Reviewer comments.
--
--!


with Ada.Finalization;
package C930001_0 is
    Verbose : constant Boolean := False;

    type Ids is range 0..10;
    Finalization_Order : array (Ids) of Ids := (Ids => 0);
    Finalization_Cnt : Ids := 0;

    protected Note is
       -- serializes concurrent access to Finalization_* above
       procedure Done (Id : Ids);
    end Note;

    -- Objects of the following type are used to note the order in
    -- which finalization occurs.
    type Has_Finalization is new Ada.Finalization.Limited_Controlled with
          record
             Id : Ids;
          end record;
    procedure Finalize (Object : in out Has_Finalization);
end C930001_0;
