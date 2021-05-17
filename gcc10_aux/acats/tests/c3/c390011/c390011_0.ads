-- C390011.A
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
--     Check that tagged types declared within generic package declarations
--     generate distinct tags for each instance of the generic.
--
-- TEST DESCRIPTION:
--     This test defines a very simple generic package (with the expectation
--     that it should be easily be shared), and a few instances of that
--     package.  In true user-like fashion, two of the instances are identical
--     (to wit: IIO is new Integer_IO(Integer)).  The tags generated for each
--     of them are placed into a list.  The last action of the test is to
--     check that everything in the list is unique.
--
--     Almost as an aside, this test defines functions that return T'Base and
--     T'Class, and then exercises these functions.
--
--     (JPR) persistent objects really need a function like:
--        function Get_Object return T'class;
--
--
-- CHANGE HISTORY:
--      20 OCT 95   SAIC   Initial version
--      23 APR 96   SAIC   Commentary Corrections 2.1
--
--!

----------------------------------------------------------------- C390011_0

with Ada.Tags;
package C390011_0 is

  procedure Add_Tag_To_List( T : Ada.Tags.Tag; X_Name, X_Tag: String );

  procedure Check_List_For_Duplicates;

end C390011_0;
