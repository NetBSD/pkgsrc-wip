-- B3A2014.A
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
--      Check that, for X'Access of a general access type A, if the designated
--      type is tagged, the type of the view denoted by X must be covered by
--      the designated type. Check that if the designated type is not tagged,
--      the type of the view must be the same, and either A's designated
--      subtype must statically match the nominal subtype of the view, or the
--      designated subtype must be discriminated and unconstrained.
--
-- TEST DESCRIPTION:
--      For tagged designated types:
--
--         A specific tagged type covers only itself. A class-wide type covers
--         all the types in its class. 
--
--         Declare the following type hierarchy:
--
--                                    T
--                            New_T_1   New_T_2
--                                              NNew_T_2
--
--         Declare a general access type with designated type New_T_2, and
--         attempt to assign X'Access to an object of this type. Verify that
--         X'Access is legal if X is of type New_T_2, but illegal if X is of 
--         type T, NNew_T_2, or New_T_2'Class.
--
--         Declare a general access type with designated type New_T_2'Class,
--         and attempt to assign X'Access to an object of this type. Verify
--         that X'Access is legal if X is of type New_T_2, NNew_T_2, or 
--         NNew_T_2'Class, but illegal if X is of type T, New_T_1, or T'Class.
--
--         Test cases where X is a formal subprogram parameter or a stand-alone
--         object. Include discriminated types within the hierarchy.
--
--
--      For non-tagged designated types:
--
--         Declare a discriminated record type with defaulted discriminants
--         and various constrained and unconstrained subtypes. Declare general
--         access types designating the various subtypes, and attempt to
--         assign X'Access to objects of these types. Verify that X'Access
--         is legal if the designated subtype statically matches the nominal
--         subtype of X or if the designated subtype is discriminated and
--         unconstrained, and is illegal otherwise. Include a case where X is
--         constrained implicitly by its initial value, such that its actual
--         subtype statically matches the designated subtype, but its nominal
--         subtype does not.
--
--         Declare various constrained and unconstrained subtypes of the
--         unconstrained array type String, as well as a type derived from
--         String. Declare general access types designating the various
--         subtypes, and attempt to assign X'Access to objects of these types.
--         Verify that X'Access is legal if the designated type statically
--         matches the nominal subtype of X, and is illegal otherwise.
--         Include a case where X is constrained implicitly by its initial
--         value, such that its actual subtype statically matches the
--         designated subtype, but its nominal subtype does not.
--
--
-- CHANGE HISTORY:
--      20 Apr 95   SAIC    Initial prerelease version.
--      10 MAY 96   SAIC    Modified test description.  Added a new case.
--
--!

package B3A2014 is

--
-- Tagged types:
--

   type Tag_Type is tagged record
     I : Integer;
   end record;

   procedure Op1 (P: in out Tag_Type);

   type New_Tag_1 is new Tag_Type with record
     B : Boolean;
   end record;
   
   type New_Tag_2 is new Tag_Type with record   
     B : Boolean;
   end record;

   type AccNew_Tag_2     is access all New_Tag_2;
   type AccNew_Tag2Class is access all New_Tag_2'Class;

   procedure Op2 (P: in out New_Tag_2);

   type NNew_Tag_2 is new New_Tag_2 with record
      S : String (1 .. 10);
   end record;

   procedure Op3 (P: in out NNew_Tag_2'Class);

   procedure Op4 (P: in out Tag_Type'Class);

--
-- Record types:
--

   subtype Disc is Natural range 1 .. 10;

   type Rec (D : Disc := 2) is record
      S : String (1 .. D);
   end record;

   subtype Rec2_Subtype is Rec (D => 2);
   subtype Rec_Subtype is Rec;

   type AccRec           is access all Rec;
   type AccRec2_Subtype  is access all Rec2_Subtype;
   type AccRec2          is access all Rec (2);
   type AccRec_Subtype   is access all Rec_Subtype;

   XRec          : aliased Rec;    
   XRec2_Subtype : aliased Rec2_Subtype;


--
-- Array types:
--

   subtype Str4   is String (1 .. 4);
   subtype SStr   is String;
   type My_String is new String;

   type AccStr   is access all String;
   type AccStr4  is access all Str4;
   type AccSStr  is access all SStr;
   type AccMyStr is access all My_String;

   XStr  : aliased String          := "shoe";  -- Constrained by initial value.
   XStr4 : aliased String (1 .. 4) := "kite";

end B3A2014;
