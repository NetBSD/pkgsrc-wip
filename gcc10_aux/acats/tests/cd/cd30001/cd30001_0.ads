-- CD30001.A
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
--      Check that X'Address produces a useful result when X is an aliased
--      object.
--      Check that X'Address produces a useful result when X is an object of
--      a by-reference type.
--      Check that X'Address produces a useful result when X is an entity
--      whose Address has been specified.
--
--      Check that aliased objects and subcomponents are allocated on storage
--      element boundaries.  Check that objects and subcomponents of by
--      reference types are allocated on storage element boundaries.
--
--      Check that for an array X, X'Address points at the first component
--      of the array, and not at the array bounds.
--   
-- TEST DESCRIPTION:
--      This test defines a data structure (an array of records) where each
--      aspect of the data structure is aliased.  The test checks 'Address
--      for each "layer" of aliased objects.
--
-- APPLICABILITY CRITERIA:
--      All implementations must attempt to compile this test.
--
--      For implementations validating against Systems Programming Annex (C):
--        this test must execute and report PASSED.
--
--      For implementations not validating against Annex C:
--        this test may report compile time errors at one or more points
--        indicated by "-- ANX-C RQMT", in which case it may be graded as inapplicable.
--        Otherwise, the test must execute and report PASSED.
--
--
-- CHANGE HISTORY:
--      22 JUL 95   SAIC   Initial version
--      08 MAY 96   SAIC   Reinforced for 2.1
--      16 FEB 98   EDS    Modified documentation
--!

----------------------------------------------------------------- CD30001_0

with SPPRT13;
package CD30001_0 is

  --    Check that X'Address produces a useful result when X is an aliased
  --    object.
  --    Check that X'Address produces a useful result when X is an object of
  --    a by-reference type.
  --    Check that X'Address produces a useful result when X is an entity
  --    whose Address has been specified.
  --    (using the new form of "for X'Address use ...")
  --
  --    Check that aliased objects and subcomponents are allocated on storage
  --    element boundaries.  Check that objects and subcomponents of by
  --    reference types are allocated on storage element boundaries.

  type Simple_Enum_Type is (Just, A, Little, Bit);

  type Data is record
    Aliased_Comp_1 : aliased Simple_Enum_Type;
    Aliased_Comp_2 : aliased Simple_Enum_Type;
  end record;

  type Array_W_Aliased_Comps is array(1..2) of aliased Data;

  Aliased_Object  : aliased Array_W_Aliased_Comps;

  Specific_Object : aliased Array_W_Aliased_Comps;
  for Specific_Object'Address use SPPRT13.Variable_Address2;  -- ANX-C RQMT.

  procedure TC_Check_Aliased_Addresses;

  procedure TC_Check_Specific_Addresses;

  procedure TC_Check_By_Reference_Types;

end CD30001_0;
