-- CD10002.A
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
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--    Check that operational items are allowed in some contexts where
--    representation items are not:
--
--       1 - Check that the name of an incompletely defined type can be used
--           when specifying an operational item. (RM95/TC1 7.3(5)).
--
--       2 - Check that operational items can be specified for a descendant of
--           a generic formal untagged type. (RM95/TC1 13.1(10)).
--
--       3 - Check that operational items can be specified for a derived
--           untagged type even if the parent type is a by-reference type or
--           has user-defined primitive subprograms. (RM95/TC1 13.1(11/1)).
--
--    (Defect Report 8652/0009, as reflected in Technical Corrigendum 1).
--
-- CHANGE HISTORY:
--    19 JAN 2001   PHL   Initial version.
--     3 DEC 2001   RLB   Reformatted for ACATS.
--     3 OCT 2002   RLB   Corrected incorrect type derivations.
--    19 MAR 2007   RLB   Eliminated illegal (by Amendment 1) returns,
--                        and removed now unneeded objects.
--    07 AUG 2007   RLB   Removed additional errors.
--    25 OCT 2007   RLB   Fixed type R10 so default initialization has non-null
--                        discriminant.
--
--!
with Ada.Streams;
use Ada.Streams;
package CD10002_0 is

    type Kinds is (Read, Write, Input, Output);
    type Counts is array (Kinds) of Natural;

    generic
        type T is private;
    package Nonlimited_Stream_Ops is

        procedure Write (Stream : access Root_Stream_Type'Class; Item : T);
        function Input (Stream : access Root_Stream_Type'Class) return T;
        procedure Read (Stream : access Root_Stream_Type'Class; Item : out T);
        procedure Output (Stream : access Root_Stream_Type'Class; Item : T);

        function Get_Counts return Counts;

    end Nonlimited_Stream_Ops;

    generic
        type T is limited private; -- Should be self-initializing.
    package Limited_Stream_Ops is

        procedure Write (Stream : access Root_Stream_Type'Class; Item : T);
        function Input (Stream : access Root_Stream_Type'Class) return T;
        procedure Read (Stream : access Root_Stream_Type'Class; Item : out T);
        procedure Output (Stream : access Root_Stream_Type'Class; Item : T);

        function Get_Counts return Counts;

    end Limited_Stream_Ops;

end CD10002_0;
