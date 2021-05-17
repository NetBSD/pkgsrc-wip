-- BC51019.A
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
--      Check that a generic formal derived tagged type is a private extension.
--      Specifically, check that, for a generic formal derived type whose
--      ancestor type has a primitive subprogram which is a function with a
--      controlling result, the function must be overridden for non-abstract
--      record extensions of the formal derived type. Check that the function
--      need not be overridden for abstract record extensions, nor for private
--      extensions, although for non-abstract private extensions it must be
--      overridden for the corresponding full type.
--
-- TEST DESCRIPTION:
--      A record extension of the formal derived type inherits the subprograms
--      of the formal derived type, which correspond to those of the ancestor
--      type.
--
--      An inherited subprogram of an abstract (record or private)
--      extension that is a function with a controlling result is an abstract
--      subprogram. In addition, abstract subprograms are inherited as
--      abstract. Recall that type abstractness is never inherited; it
--      always must be specified with the type extension.
--
--      However, an inherited subprogram of a non-abstract record
--      extension that is a function with a controlling result is a
--      concrete subprogram that requires overriding. (Amendment 1
--      provides that such functions do not need to be overridden for
--      a null extension.) Inherited abstract subprograms also require
--      overriding.
--
--
--      Similarly, an inherited subprogram of a non-abstract private
--      extension that is a function with a controlling result is a
--      concrete subprogram, as are inherited abstract subprograms.
--      In this case, the full type is expected
--      to provide the subprogram, so there are no special checks
--      associated with the private extension itself.
--
--
--      This test checks that if a record extension of a formal derived type
--      inherits a subprogram that is a function with a controlling result,
--      the derived type must either be declared abstract, or the inherited
--      subprogram is overridden. It also checks that no inappropriate
--      restrictions are placed in private extensions. Cases are verified for
--      both abstract and non-abstract formal derived types. (Test BC51020
--      checks cases of inherited abstract subprograms.)
--

-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0.
--      22 Mar 07   RLB     Corrected test so that the functions require
--                          overriding as the test is expected; also
--                          corrected the terminology and test description.
--      21 Nov 19   RLB     Added error location indicators.
--!

package BC51019_0 is

   type Ancestor is tagged record                -- Root type of class
      Component : Boolean := False;              -- (non-abstract).
   end record;

   function True_Field return Ancestor;          -- Function with controlling
                                                 -- result.
   -- ...Other operations.

end BC51019_0;
