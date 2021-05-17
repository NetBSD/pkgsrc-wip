-- C760009.A
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
--      Check that for an extension_aggregate whose ancestor_part is a
--      subtype_mark (i.e. Typemark'( Subtype with Field => x, etc.) )
--      Initialize is called on all controlled subcomponents of the
--      ancestor part; if the type of the ancestor part is itself controlled,
--      the Initialize procedure of the ancestor type is called, unless that
--      Initialize procedure is abstract.
--
--      Check that the utilization of a controlled type for a generic actual
--      parameter supports the correct behavior in the instantiated package.
--
-- TEST DESCRIPTION:
--      Declares a generic package instantiated to check that controlled
--      types are not impacted by the "generic boundary."
--      This instance is then used to perform the tests of various
--      aggregate formations of the controlled type.  After each operation
--      in the main program that should cause implicit calls, the "state" of
--      the software is checked.  The "state" of the software is maintained in
--      several variables which count the calls to the Initialize, Adjust and
--      Finalize procedures in each context.  Given the nature of the
--      language rules, the test specifies a minimum number of times that
--      these subprograms should have been called.  The test also checks cases
--      where the subprograms should not have been called.
--     
--      As per the example in AARM 7.6(11a..d);6.0, the distinctions between
--      the presence/absence of default values is tested.
--
-- DATA STRUCTURES
--
--      C760009_3.Master_Control is derived from
--        C760009_2.Control is derived from
--          Ada.Finalization.Controlled
--
--      C760009_1.Simple_Control is derived from
--        Ada.Finalization.Controlled
--
--      C760009_3.Master_Control contains
--        Standard.Integer
--
--      C760009_2.Control contains
--        C760009_1.Simple_Control (default value)
--        C760009_1.Simple_Control (default initialized)
--
--
-- CHANGE HISTORY:
--      01 MAY 95   SAIC    Initial version
--      19 FEB 96   SAIC    Fixed elaboration Initialize count
--      14 NOV 96   SAIC    Allowed for 7.6(21) optimizations
--      13 FEB 97   PWB.CTA Initialized counters at lines 127-129
--      26 JUN 98   EDS     Added pragma Elaborate_Body to C760009_0
--                          to avoid possible instantiation error
--!

---------------------------------------------------------------- C760009_0

with Ada.Finalization;
generic

  type Private_Formal is private;

  with procedure TC_Validate( APF: in out Private_Formal );

package C760009_0 is -- Check_1

  pragma Elaborate_Body;
  procedure TC_Check_1( APF: in     Private_Formal );
  procedure TC_Check_2( APF:    out Private_Formal );
  procedure TC_Check_3( APF: in out Private_Formal );

end C760009_0;
