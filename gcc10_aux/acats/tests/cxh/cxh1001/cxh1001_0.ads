-- CXH1001.A
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
-- OBJECTIVE
--     Check pragma Normalize_Scalars.
--     Check that this configuration pragma causes uninitialized scalar
--     objects to be set to a predictable value.  Check that multiple
--     compilation units are affected.  Check for uninitialized scalar
--     objects that are subcomponents of composite objects, unassigned
--     out parameters, objects that have been allocated without an initial
--     value, and objects that are stand alone.
--
-- TEST DESCRIPTION
--     The test requires that the configuration pragma Normalize_Scalars
--     be processed.  It then defines a few scalar types (some enumeration,
--     some integer) in a few packages.  The scalar types are designed such
--     that the representation will easily allow for an out of range value.
--     Unchecked_Conversion and the 'Valid attribute are both used to verify
--     that the default values of the various kinds of objects are indeed
--     invalid for the type.
--
--     Note that this test relies on having uninitialized objects, compilers
--     may generate several warnings to this effect.
--
-- SPECIAL REQUIREMENTS
--      The implementation must process configuration pragmas which
--      are not part of any Compilation Unit;  the method employed
--      is implementation defined.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Safety and Security Annex.
--
--
-- CHANGE HISTORY:
--      26 OCT 95   SAIC   Initial version
--      04 NOV 96   SAIC   Added cases, upgraded commentary
--
--!

---------------------------- CONFIGURATION PRAGMAS -----------------------

pragma Initialize_Scalars;                                         -- OK
                                                -- configuration pragma

------------------------ END OF CONFIGURATION PRAGMAS --------------------


----------------------------------------------------------------- CXH1001_0

with Impdef.Annex_H;
with Unchecked_Conversion;
package CXH1001_0 is

  package Imp_H renames Impdef.Annex_H;
  use type Imp_H.Small_Number;
  use type Imp_H.Scalar_To_Normalize;

  Global_Object : Imp_H.Scalar_To_Normalize;
  -- if the pragma is in effect, this should come up with the predictable
  -- value

  Global_Number : Imp_H.Small_Number;
  -- if the pragma is in effect, this should come up with the predictable
  -- value

  procedure Package_Check;

  type Num is range 0..2**Imp_H.Scalar_To_Normalize'Size-1;
  for Num'Size use Imp_H.Scalar_To_Normalize'Size;  

  function STN_2_Num is
     new Unchecked_Conversion( Imp_H.Scalar_To_Normalize, Num );

  Small_Last : constant Integer := Integer(Imp_H.Small_Number'Last);

end CXH1001_0;
