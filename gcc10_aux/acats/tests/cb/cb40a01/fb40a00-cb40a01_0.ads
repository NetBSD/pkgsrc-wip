-- CB40A01.A
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
--      Check that a user defined exception is correctly propagated out of
--      a public child package.
--
-- TEST DESCRIPTION:
--      Declare a public child package containing a procedure used to 
--      analyze the alphanumeric content of a particular text string.
--      The procedure contains a processing loop that continues until the
--      range of the text string is exceeded, at which time a user defined
--      exception is raised.  This exception propagates out of the procedure
--      through the parent package, to the main test program.
--
--      Exception Type Raised:
--        * User Defined
--          Predefined  
--
--      Hierarchical Structure Employed For This Test:  
--        * Parent Package
--        * Public Child Package
--          Private Child Package
--          Public Child Subprogram
--          Private Child Subprogram
--
-- TEST FILES:
--      This test depends on the following foundation code:
--         FB40A00.A
--
--       
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!


package FB40A00.CB40A01_0 is    -- package Text_Parser.Processing

   procedure Process_Text (Text : in String_Pointer_Type);

end FB40A00.CB40A01_0;
