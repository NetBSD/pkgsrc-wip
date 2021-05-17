-- BXC5001.A
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
--      Check that pragma Discard_Names may only be declared immediately
--      within a declarative part, immediately within a package
--      specification or as a configuration pragma.
--      Check that its parameter, if present, may denote only a non-derived
--      enumeration subtype, tagged subtype or an exception.
--
-- TEST DESCRIPTION:
--      This test defines one of each major type category available in the
--      language and applies pragma Discard_Names to it.  The test also
--      checks pragma discard used with and without parameters, in package
--      specification, and without parameters in a procedure declaration.
--
-- SPECIAL REQUIREMENTS:
--      The implementation must process a configuration pragma which is not
--      part of any compilation unit.  The method employed is
--      implementation defined.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Systems Programming Annex.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      13 Dec 94   SAIC    Add dummy procedure to BXC5001_2
--      06 Feb 96   SAIC    Reordered to reduce splitting for 2.1
--
--!

---------------------------- CONFIGURATION PRAGMAS -----------------------

pragma Discard_Names;                                             -- OK

----------------------------------------------------------------- BXC5001_2

package BXC5001_2 is
  procedure Require_Package_Body;
end BXC5001_2;
