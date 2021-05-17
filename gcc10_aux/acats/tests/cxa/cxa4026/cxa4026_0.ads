-- CXA4026.A
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
--      Check that Ada.Strings.Fixed procedures Head, Tail, and Trim, as well 
--      as the versions of subprograms Translate (procedure and function), 
--      Index, and Count, available in the package which use a 
--      Maps.Character_Mapping_Function input parameter, produce correct 
--      results.
--
-- TEST DESCRIPTION:
--      This test examines the operation of several subprograms contained in
--      the Ada.Strings.Fixed package.  
--      This includes procedure versions of Head, Tail, and Trim, as well as
--      four subprograms that use a Character_Mapping_Function as a parameter 
--      to provide the mapping capability.
--      
--      Two functions are defined to provide the mapping.  Access values 
--      are defined to refer to these functions.  One of the functions will
--      map upper case characters in the range 'A'..'Z' to their lower case
--      counterparts, while the other function will map lower case characters
--      ('a'..'z', or a character whose position is in one of the ranges 
--      223..246 or 248..255, provided the character has an upper case form)
--      to their upper case form.
--      
--      Function Index uses the mapping function access value to map the input
--      string prior to searching for the appropriate index value to return.
--      Function Count uses the mapping function access value to map the input
--      string prior to counting the occurrences of the pattern string.
--      Both the Procedure and Function version of Translate use the mapping
--      function access value to perform the translation.
--
--      Results of all subprograms are compared with expected results.
--      
--       
-- CHANGE HISTORY:
--      10 Feb 95   SAIC    Initial prerelease version
--      21 Apr 95   SAIC    Modified definition of string variable Str_2.
--
--!


package CXA4026_0 is

   -- Function Map_To_Lower_Case will return the lower case form of 
   -- Characters in the range 'A'..'Z' only, and return the input
   -- character otherwise.

   function Map_To_Lower_Case (From : Character) return Character;


   -- Function Map_To_Upper_Case will return the upper case form of 
   -- Characters in the range 'a'..'z', or whose position is in one
   -- of the ranges 223..246 or 248..255, provided the character has
   -- an upper case form.               

   function Map_To_Upper_Case (From : Character) return Character;

end CXA4026_0;
