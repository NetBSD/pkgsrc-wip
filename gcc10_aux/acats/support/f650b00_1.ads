-- F650B00.A
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
-- FOUNDATION DESCRIPTION:
--      This foundation provides a simple background for a class family
--      based on an abstract type. It is based on foundation F393A00,
--      updated for testing various rules for return statements.
--
--  type                       procedures                  functions
--  ----                       ----------                  ---------
--  Object                     Initialize, Swap(abstract)  Create(abstract)
--        Object'Class                                     Initialized
--    Windmill is new Object   Swap, Stop, Add_Spin        Create, Spin
--      Pump is new Windmill   Set_Rate                    Create, Rate
--      Mill is new Windmill   Swap, Stop                  Create
--
-- CHANGE HISTORY:
--      19 Aug 2015   RLB   Created foundation from F393A00.
--
--!

package F650B00_1 is
   type Object is abstract tagged private;
   procedure Initialize( An_Object: in out Object );
   function  Initialized( An_Object: Object'Class ) return Boolean;
   procedure Swap( A,B: in out Object ) is abstract;
   function  Create return Object is abstract;
private
   type Object is abstract tagged record
     Initialized : Boolean := False;
   end record;
end F650B00_1;
