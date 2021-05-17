-- SPECIAL.A
--
--                             Grant of Unlimited Rights
--
--     The Ada Conformity Assessment Authority (ACAA) holds unlimited
--     rights in the software and documentation contained herein. Unlimited
--     rights are the same as those granted by the U.S. Government for older
--     parts of the Ada Conformity Assessment Test Suite, and are defined
--     in DFAR 252.227-7013(a)(19). By making this public release, the ACAA
--     intends to confer upon all recipients unlimited rights equal to those
--     held by the ACAA. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever, and
--     to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS. THE ACAA MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
--
-- PURPOSE:
--      This package provides information about tests that require
--      special handling by the test summary (Summary.A).
--      This information is maintained by the ACAA; please report
--      any suggested changes to the ACAA at agent@ada-auth.org.
--
-- CHANGE HISTORY:
--     20 May 2016   RLB  Split from Summary tool.
--     22 May 2016   RLB  Added Do_Special.
--     23 Mar 2017   RLB  Added test BA21005 to the optional unit list.
--     13 Feb 2018   RLB  Added additional tests to the optional unit list.
--                        Also, fixed some comments.
--     15 Feb 2018   RLB  Added a new test to the optional unit list.
--     13 Jun 2018   RLB  Added some existing tests to the optional unit list.
--     06 Sep 2018   RLB  Added a new test to the optional unit list.

with Trace, Test_Summary, Ada.Text_IO;
package Special_Handling is

   function Optional_Unit_for_Test
               (Source_Name : Trace.Name_Subtype;
                Unit_Name   : Test_Summary.Comp_Unit_Name;
                Unit_Kind   : Test_Summary.Compilation_Unit_Kinds)
      return Boolean;
      -- Returns True if the test in the source file Source_Name
      -- has an optional unit Unit_Name with Unit_Kind according to the
      -- Optional_Unit_List. Returns False otherwise.


   type Special_Kind is (Not_Special, No_Parse, Fully_Manual);
   type Acc_WSR is access procedure (Rec : in Test_Summary.Info_Record);

   function Do_Special_for_Test_File
               (Source_Name  : Trace.Name_Subtype;
                Summary_File : Ada.Text_IO.File_Type)
      return Special_Kind;
      -- Checks if Source_Name needs special handling; if so, writes the
      -- needed records to Summary_File and returns the appropriate Kind.
      -- If this routine returns Not_Special, the unit should be parsed
      -- normally. If this routine returns No_Parse, the unit should not be
      -- parsed, but it should be split into tokens (so the error tags are
      -- processed). This is used for tests which are lexically fine, but have
      -- severe parse errors that the summary tool cannot handle. This routine
      -- will have written the compilation unit records for the test file.
      -- If this routine returns Fully_Manual, no processing should be done on
      -- the unit. This is used for tests with lexical errors that the summary
      -- tool cannot handle. This routine will have written the entire summary
      -- for the test file.

end Special_Handling;
