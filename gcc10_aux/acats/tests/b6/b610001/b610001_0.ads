-- B610001.A
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
--     Check that access parameters may have default expressions.
--     Check that the expected type of the actual access parameter is
--     the nominal subtype of the formal anonymous access parameter.
--
-- TEST DESCRIPTION:
--     This test declares a record type, tagged types, type extensions, and
--     subprogram.  Check the following formal and actual access types:
--
--     Formal type                           Actual type                
--     ----------------------------------------------------------------------
--     Specific type T                       Correct specific type
--            "                              Wrong specific type
--            "                              Class-wide type T'Class
--            "                              Class-wide type descendent'Class
--            "                              Class-wide type ancestor'Class
--     Class-wide type T'Class               Specific type in T'Class
--            "                              Specific type in descendent'Class
--            "                              Specific type in ancestor'Class
--            "                              Class-wide type T'Class
--            "                              Class-wide type descendent'Class
--            "                              Class-wide type ancestor'Class
--            "                              Specific type not in T'Class
--            "                              Specific type unrelated'Class
--
--
-- CHANGE HISTORY:
--      07 AUG 95   SAIC   Initial version
--      17 APR 96   SAIC   Incorporated Reviewer comments for 2.1
--      26 FEB 97   PWB.CTA Flagged errors where "cover" is wrong order
--	01 JUN 98   EDS    Remove ambiguous, by ARM 3.10.2(2) and 8.6(27),
--                         procedure calls.
--!

package B610001_0 is

   type Rec is record
      C : Integer;
   end record;

   procedure Acc_Rec_Proc (P : access Rec); 

   function Acc_W_Default (P : access Rec := new Rec'(C => 25))      -- OK.
     return Integer;

   procedure Acc_Float_Proc (P : access Float); 

   --------------------------------------------------------------------------
   type Tag is tagged record
      C1 : Integer;
   end record;

   procedure Acc_CW_Tag_Proc (P : access Tag'Class); 

   --------------------------------------------------------------------------
   type TagType is tagged record
      C1 : Integer;
   end record;

   type NewTag is new Tag with record
      C2 : Boolean;
   end record;

   procedure Acc_NTag_Proc (P : access NewTag); 

   procedure Acc_CW_NTag_Proc (P : access NewTag'Class); 

   --------------------------------------------------------------------------
   type NNewTag is new NewTag with record
      C3 : String (1..5);
   end record;


end B610001_0;
