-- CC51009.A
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
-- OBJECTIVE:
--      Check that a generic unit with incomplete formal types can be
--      instantiated with a private type prior to the full declaration
--      of that type and that such instantiations can be passed as actuals
--      to formal packages.
--
-- TEST DESCRIPTION:
--      A generic package, modeling a set signature, is declared with formal
--      incomplete type parameters and with several formal operations with
--      parameters or results of the formal incomplete type. The generic
--      package is instantiated in the visible part with a private type
--      (which necessarily will occur before the full type declaration).
--      The instance is associated with a formal package in another
--      instantiation. The functioning of the set abstraction is tested
--      by making calls to the formal operations of the formal package.
--
-- CHANGE HISTORY:
--      15 Jan 2012   GJD     Initial version.
--      26 Mar 2014   RLB     Renamed for ACATS.
--      02 Apr 2014   RLB     Removed incomplete type case as it is artifical
--                            and should be tested properly in a separate test.
--
--!

package CC51009_0 is

   generic
      type Element;
      type Set;
      with procedure Add (Elem : Element; To_Set : in out Set) is <>;
      with function Union (Left, Right : Set) return Set is <>;
      with function Intersection (Left, Right : Set) return Set is <>;
   package Set_Signature is

   end Set_Signature;

end CC51009_0;
