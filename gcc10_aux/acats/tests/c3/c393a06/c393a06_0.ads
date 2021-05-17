-- C393A06.A
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
--      Check that a type that inherits abstract operations but
--      overrides each of these operations is not required to be
--      abstract, and that objects of the type and its class-wide type
--      may be declared and passed in calls to the overriding
--      subprograms.
--
-- TEST DESCRIPTION:
--      This test derives a type from the root abstract type available
--      in foundation F393A00.  It declares subprograms as required by
--      the language to override the abstract subprograms, allowing the
--      derived type itself to be not abstract.  It also declares
--      operations on the new type, as well as on the associated class-
--      wide type.  The main program then uses two objects of the type
--      and two objects of the class-wide type as parameters for each of
--      the subprograms.  Correct execution is determined by path
--      analysis and value checking.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         F393A00.A   (foundation code)
--         C393A06.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      19 Dec 94   SAIC    Removed RM references from objective text.
--
--!
 
 with F393A00_1;
 package C393A06_0 is
   type Organism is new F393A00_1.Object with private;
   type Kingdoms is ( Animal, Vegetable, Unspecified );
 
   procedure Swap( A,B: in out Organism );
   function  Create return Organism;
 
   procedure Initialize( The_Entity     : in out Organism;
                         In_The_Kingdom : Kingdoms );
   function  Kingdom( Of_The_Entity : Organism ) return Kingdoms;
 
   procedure TC_Check( An_Entity   : Organism'Class;
                       In_Kingdom  : Kingdoms;
                       Initialized : Boolean );
 
   Incompatible : exception;
 
 private
   type Organism is new F393A00_1.Object with
     record
       In_Kingdom : Kingdoms;
     end record;
 end C393A06_0;
