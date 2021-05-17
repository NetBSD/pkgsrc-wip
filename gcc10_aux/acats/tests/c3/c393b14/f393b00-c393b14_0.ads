-- C393B14.A
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
--      Check that an extended type can be derived in a private child package
--      from an abstract type defined in a library package.
--
-- TEST DESCRIPTION:
--      Add a private child package to Alert_Foundation.  Using Private_Alert
--      as parent type, declare an extended type adding a new record component.
--      Override procedure Handle.  Declare an object of the new type in the
--      child specification. Use type definitions from the private part of the
--      parent in the body of the child.
--
-- TEST FILES: 
--      This test depends on the following foundation code:
--
--         F393B00.A  Package Alert_Foundation
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

private package F393B00.C393B14_0 is
             -- Alert_Foundation.Private_Child

  type Implementation_Specific_Alert_Type is new Private_Alert with record
    New_Private_Field : Implementation_Detail 
                        := Implementation_Detail'Last;
  end record;

  procedure Handle (PA : in out Implementation_Specific_Alert_Type);
                             -- overrides abstract Handle, as required
  PA : Implementation_Specific_Alert_Type;

end F393B00.C393B14_0;
