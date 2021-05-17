-- B393003.A
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
--      Check that:
--      Bodies are not allowed for abstract subprograms.
--      An abstract subprogram defined using a combination of concrete and 
--      abstract types remains abstract upon derivation from the concrete type.
--      The target of an assignment operation may not be abstract.
--      Subprogram bodies in a package body that are homographs of inherited
--      primitive abstract operations are illegal.
--      
-- TEST DESCRIPTION:
--      This test declares abstract (private) types, abstract (private)
--      extension, and abstract subprograms.  Verify that bodies of abstract 
--      subprograms are illegal.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      16 Nov 95   SAIC    Fixed problems for ACVC 2.0.1
--      18 Aug 96   SAIC    ACVC 2.1: Modified test objective and ERROR 
--                          comments.
--
--!

package B393003 is

   type Tagged_Type is tagged 
     record
        Field_1 : boolean;
     end record;

   function Func return Tagged_Type;

   type Untagged_Rec is record
      Field_2 : Tagged_Type;
   end record;

   type Short is range 0 .. 10;

   type Abstract_Visible is abstract tagged null record;

   procedure Abstract_Vis_Proc (P : Abstract_Visible) is abstract;

   function Abstract_Vis_Func (P : Abstract_Visible) return Short is abstract;

   procedure Untag_Abs_Proc (P1 : Abstract_Visible;
                             P2 : Untagged_Rec) is abstract;

   -----------------------------------------------------------------
   type New_Abs_Vis is abstract new Abstract_Visible with record
      New_Field_1 : Short;
   end record;
   -- Inherited:
   --    procedure Abstract_Vis_Proc (P : New_Abs_Vis) is abstract;
   --    function Abstract_Vis_Func (P : New_Abs_Vis) return Short is abstract;
   --    procedure Untag_Abs_Proc (P1 : New_Abs_Vis; 
   --                              P2 : Untagged_Rec) is abstract;

   -----------------------------------------------------------------
   type New_Untag_Rec is new Untagged_Rec;
   -- Inherited:
   --    procedure Untag_Abs_Proc (P1 : Abstract_Visible; 
   --                              P2 : New_Untag_Rec) is abstract;

   -----------------------------------------------------------------
   type New_New_Abs_Vis is abstract new New_Abs_Vis with record
      New_New_Field : Untagged_Rec;
   end record;
   -- Inherited:
   --    procedure Abstract_Vis_Proc (P : New_New_Abs_Vis) is abstract;
   --    function Abstract_Vis_Func (P : New_New_Abs_Vis) 
   --                                return Short is abstract;
   --    procedure Untag_Abs_Proc (P1 : New_New_Abs_Vis; 
   --                              P2 : Untagged_Rec) is abstract;

   -----------------------------------------------------------------
   type Abs_Tag_Lim is abstract tagged limited record
      Field_3 : Short;
   end record;

   procedure Abs_Tag_Lim_Proc (P : Abs_Tag_Lim) is abstract;

   -----------------------------------------------------------------
   type New_Abs_Tag_Lim is abstract new Abs_Tag_Lim with record
      New_Field_2 : Short;
   end record;
   -- Inherited:
   --    procedure Abs_Tag_Lim_Proc (P : New_Abs_Tag_Lim) is abstract;

   -----------------------------------------------------------------
   type Abstract_Private is abstract tagged private;

   type Another_Short is range 0 .. 10;

   function Abstract_Func (P : Abstract_Private) 
     return Abstract_Private is abstract;

   procedure Abstract_Pri_Proc (P1 : Abstract_Private;
                                P2 : Another_Short := 0) is abstract;

   -----------------------------------------------------------------
   type New_Abs_Pri is abstract new Abstract_Visible with private;
   -- Inherited:
   --    procedure Abstract_Vis_Proc (P : New_Abs_Pri) is abstract;
   --    function Abstract_Vis_Func (P : New_Abs_Pri) return Short is abstract;
   --    procedure Untag_Abs_Proc (P1 : New_Abs_Pri;
   --                              P2 : Untagged_Rec) is abstract;

   -----------------------------------------------------------------
   type Other_Abstract is abstract tagged record
     I : Integer;
   end record;

   type Non_Abstract_Extension is new Other_Abstract with null record;

private
   type Abstract_Private is abstract tagged record
      Field_4 : Short;
   end record;

   -----------------------------------------------------------------
   type New_Abs_Pri is abstract new Abstract_Visible with record
      New_Field_3 : boolean;
   end record;

   -----------------------------------------------------------------
   type New_Short is new Another_Short;
   -- Inherited:
   --    procedure Abstract_Pri_Proc (P1 : Abstract_Private;
   --                                 P2 : New_Short := 0) is abstract;
   --    function Abstract_Vis_Func (P : New_Abs_Pri) return New_Short 
   --      is abstract;

end B393003;
