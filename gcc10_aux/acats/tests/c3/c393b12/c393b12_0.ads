-- C393B12.A
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
--      Check that an extended type can be derived in the specification of a
--      generic package when the parent is an abstract type in a library
--      package.
--
-- TEST DESCRIPTION:
--      Extend an abstract type in the visible part of a generic package.
--      Make all of the procedures which override abstract procedures
--      available as part of the generic interface.  Instantiate the generic.
--
-- TEST FILES: 
--      This test depends on the following foundation code:
--
--         F393B00.A  Package Alert_Foundation
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      14 Oct 95   SAIC    Update and repair for ACVC 2.0.1
--      27 Feb 97   PWB.CTA Add pragma Elaborate for C393B12_0.
--!

----------------------------------------------------------------- C393B12_0

with F393B00;
  -- Alert_Foundation
generic 
  type Generic_Status_Enum is (<>);

package C393B12_0 is
     -- Alert_Functions

  type Generic_Alert_Type is new F393B00.Alert with record
    Status : Generic_Status_Enum := Generic_Status_Enum'First;
  end record;
                                     -- extension of an abstract type

  procedure Handle (GA : in out Generic_Alert_Type);
                                     -- override of abstract procedure

  function Query_Status (GA : Generic_Alert_Type)
    return Generic_Status_Enum;      -- new primitive operation for
                                     -- Generic_Alert_Type
end C393B12_0;
