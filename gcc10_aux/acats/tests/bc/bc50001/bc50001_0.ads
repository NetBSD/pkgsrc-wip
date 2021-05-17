-- BC50001.A
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
--      Check that, for a generic formal derived type, the actual must be
--      in the class rooted at the ancestor subtype. Check for scalar,
--      array, and access types.
--
-- TEST DESCRIPTION:
--      For each type category considered, define a derivation class:
--
--                                    Root
--                                   /    \
--                           <Ancestor>   Sibling
--                               /            \
--                            Child          Nephew
--                            /
--                       Grandchild
--
--      Use Ancestor as the ancestor type of the generic formal derived
--      type. Instantiate the generic for each of the types in the
--      derivation class. Ancestor, Child, Grandchild, and subtypes thereof
--      are legal as actuals. Root, Sibling, Nephew and their subtypes are
--      illegal as actuals.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      09 Nov 95   SAIC    ACVC 2.0.1 fixes: removed unknown discriminant
--                          parts. Changed all non-scalar constrained actual
--                          subtypes to unconstrained subtypes.
--
--!

package BC50001_0 is  -- Type definitions.

--
-- Scalar types:
--
                                                    -- "Root" type is Float.
   subtype Float250 is Float range 0.0 .. 250.0;    -- Subtype of "Root."

   type Weight is new Float250;                     -- "Ancestor" type (derived
                                                    -- from subtype).
   subtype LightWt is Weight range 0.0 .. 200.0;    -- Subtype of "Ancestor."

   type Pounds is new Weight range 0.0 .. 150.0;    -- "Child" type (derived
                                                    -- from specific type).
   subtype Lbs100 is Pounds range 0.0 .. 100.0;     -- Subtype of "Child."

   type UpTo10Lbs is new Lbs100 range 0.0 .. 10.0;  -- "Grandchild" type
                                                    -- (derived from subtype).
   subtype FeatherWt is UpTo10Lbs range 0.0 .. 5.0; -- Subtype of "Grandchild."

   type Distance is new Float;                      -- "Sibling" type (derived
                                                    -- from specific type).
   subtype Nearby is Distance range 0.0 .. 100.0;   -- Subtype of "Sibling."

   type Miles is new Nearby;                        -- "Nephew" type (derived
                                                    -- from subtype).
   subtype StonesThrow is Miles range 0.0 .. 10.0;  -- Subtype of "Nephew."


--
-- Array types:
--
                                                    -- "Root" type is String.
   subtype StringSub is String;                     -- Subtype of "Root."

   type Names is new String;                        -- "Ancestor" type (derived
                                                    -- from specific type).
   subtype NameSub is Names;                        -- Subtype of "Ancestor."

   type LastNames is new NameSub;                   -- "Child" type (derived
                                                    -- from subtype).

   type LastNamesA_L is new LastNames;              -- "Grandchild" type (der.
                                                    -- from specific type).

   type ReservedWords is new StringSub;             -- "Sibling" type (derived
                                                    -- from subtype).

   type NewReservedWords is new ReservedWords;      -- "Nephew" type (derived
                                                    -- from specific type).

--
-- Access types:
--

   type StringPtr is access String;                 -- "Root" type.
   subtype StrSubPtr is StringPtr;                  -- Subtype of "Root."

   type NamePtr is new StringPtr;                   -- "Ancestor" type (derived
                                                    -- from specific type).
   subtype NameSubPtr is NamePtr;                   -- Subtype of "Ancestor."

   type LastNamePtr is new NameSubPtr;              -- "Child" type (derived
                                                    -- from subtype).

   type LastA_LPtr is new LastNamePtr;              -- "Grandchild" type (der.
                                                    -- from specific type).

   type ReservedWordPtr is new StrSubPtr;           -- "Sibling" type (derived
                                                    -- from subtype).

   type NewReservedWdPtr is new ReservedWordPtr;    -- "Nephew" type (derived
                                                    -- from specific type).

end BC50001_0;
