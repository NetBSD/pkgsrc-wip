-- BXC5001.A
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
--      Check that pragma Discard_Names may only be declared immediately
--      within a declarative part, immediately within a package
--      specification or as a configuration pragma.
--      Check that its parameter, if present, may denote only a non-derived
--      enumeration subtype, tagged subtype or an exception.
--
-- TEST DESCRIPTION:
--      This test defines one of each major type category available in the
--      language and applies pragma Discard_Names to it.  The test also
--      checks pragma discard used with and without parameters, in package
--      specification, and without parameters in a procedure declaration.
--
-- SPECIAL REQUIREMENTS:
--      The implementation must process a configuration pragma which is not
--      part of any compilation unit.  The method employed is
--      implementation defined.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Systems Programming Annex.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      13 Dec 94   SAIC    Add dummy procedure to BXC5001_2
--      06 Feb 96   SAIC    Reordered to reduce splitting for 2.1
--
--!

---------------------------- CONFIGURATION PRAGMAS -----------------------

pragma Discard_Names;                                             -- OK

-- body is found after next compilation unit

------------------------------------------------------------------- BXC5001

procedure BXC5001 is
  pragma Discard_Names;                                           -- OK

  type Enumeration is (Purple, Lavender, Violent);

  type Tagged_Type is tagged record
    Field : String(1..10);
    Meadow: Natural;
  end record;

  Somethings_Terribly_Wrong_Here : exception;

  type Integer_Type   is range 1..100;
  type Modular_Type   is mod   256;
  type Floating_Point is digits 5;
  type Fixed_Point    is delta 0.5  range 0.0  ..  10.0;
  type Decimal        is delta 0.01 range 0.00 .. 100.00;
  type Array_Type     is array(Integer_Type) of Modular_Type;

  type Plain_Record   is record
    Calm_Ponent : Integer;
  end record;

  task type Task_Type is
    entry E(P:Decimal);
  end Task_Type;

  protected type Protected_Type is
    entry E(P:Decimal);
  end Protected_Type;

  task body Task_Type is
  begin
    accept E(P:Decimal);
  end Task_Type;

  protected body Protected_Type is
    entry E(P:Decimal) when True is
    begin
      null;
    end E;
  end Protected_Type;

begin
  null;
end BXC5001;
