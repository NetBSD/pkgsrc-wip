-- F611A00.A
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
--*
--
-- FOUNDATION DESCRIPTION:
--      This foundation declares a set of objects and types used to determine
--      if various precondition and postcondition expressions are evaluated
--      as expected.
--
-- CHANGE HISTORY:
--      21 Mar 16   JAC     Initial pre-release version.
--      24 Mar 16   RLB     Added foundation description.
--      29 Mar 16   RLB     Added TC_Order_Error so that the foundation isn't
--                          including messages for particular tests.
--      31 Mar 16   RLB     Removed duplicative versions of flags that aren't
--                          needed in individual tests.
--      24 Dec 16   JAC	    Add flags for interface tests.
--
--!
package F611A00 is

   TC_Order_Error : exception;

   TC_Object_Distance_Called                 : Boolean;
   TC_Object_Distance_Is_Positive_Called     : Boolean;
   TC_Object_Not_Too_Far_Called              : Boolean;
   TC_Object_Not_Too_Near_Called             : Boolean;
   TC_Object_Distance_Post_Class_Called      : Boolean;
   TC_Object_Distance_Pre_Class_Called       : Boolean;
   TC_Object_Distance_Specific_Post_Called   : Boolean;
   TC_Object_Distance_Specific_Pre_Called    : Boolean;
   TC_Object_X_Coord_Called                  : Boolean;
   TC_Object_X_Coord_Specific_Post_Called    : Boolean;
   TC_Object_X_Coord_Specific_Pre_Called     : Boolean;
   TC_Object_Y_Coord_Called                  : Boolean;
   TC_Object_Y_Coord_Specific_Post_Called    : Boolean;
   TC_Object_Y_Coord_Specific_Pre_Called     : Boolean;
   TC_Point_Distance_Post_Class_Called       : Boolean;
   TC_Point_Distance_Pre_Class_Called        : Boolean;
   TC_Triangle_Distance_Called               : Boolean;
   TC_Triangle_Distance_Is_Positive_Called   : Boolean;
   TC_Triangle_Not_Too_Far_Called            : Boolean;
   TC_Triangle_Not_Too_Near_Called           : Boolean;
   TC_Triangle_Distance_Post_Class_Called    : Boolean;
   TC_Triangle_Distance_Pre_Class_Called     : Boolean;
   TC_Triangle_Distance_Specific_Post_Called : Boolean;
   TC_Triangle_Distance_Specific_Pre_Called  : Boolean;
   TC_Triangle_X_Coord_Called                : Boolean;
   TC_Triangle_Y_Coord_Called                : Boolean;

   procedure TC_Clear;

   function TC_Log_Object_Distance_Post_Class_Called      return Boolean;

   function TC_Log_Object_Distance_Pre_Class_Called       return Boolean;

   function TC_Log_Object_Distance_Specific_Post_Called   return Boolean;

   function TC_Log_Object_Distance_Specific_Pre_Called    return Boolean;

   function TC_Log_Object_X_Coord_Specific_Post_Called    return Boolean;

   function TC_Log_Object_X_Coord_Specific_Pre_Called     return Boolean;

   function TC_Log_Object_Y_Coord_Specific_Post_Called    return Boolean;

   function TC_Log_Object_Y_Coord_Specific_Pre_Called     return Boolean;

   function TC_Log_Point_Distance_Post_Class_Called       return Boolean;

   function TC_Log_Point_Distance_Pre_Class_Called        return Boolean;

   function TC_Log_Triangle_Distance_Post_Class_Called    return Boolean;

   function TC_Log_Triangle_Distance_Pre_Class_Called     return Boolean;

   function TC_Log_Triangle_Distance_Specific_Post_Called return Boolean;

   function TC_Log_Triangle_Distance_Specific_Pre_Called  return Boolean;

   procedure TC_Output;

end F611A00;
