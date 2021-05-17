-- C392011.A
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
--     Check that if a function call with a controlling result is itself
--     a controlling operand of an enclosing call on a dispatching operation,
--     then its controlling tag value is determined by the controlling tag
--     value of the enclosing call.
--
-- TEST DESCRIPTION:
--      The test builds and traverses a "ragged" list; a linked list which
--      contains data elements of three different types (all rooted at
--      Level_0'Class).  The traversal of this list checks the objective
--      by calling the dispatching operation "Check" using an item from the
--      list, and calling the function create; thus causing the controlling
--      result of the function to be determined by evaluating the value of
--      the other controlling parameter to the two-parameter Check.
--
--
-- CHANGE HISTORY:
--      22 SEP 95   SAIC   Initial version
--      23 APR 96   SAIC   Corrected commentary, differentiated integer.
--
--!

----------------------------------------------------------------- C392011_0

package C392011_0 is

  type Level_0 is tagged record
    Ch_Item : Character;
  end record;

  function Create return Level_0;
    -- primitive dispatching function

  procedure Check( Left, Right: in Level_0 );
    -- has controlling parameters

end C392011_0;
