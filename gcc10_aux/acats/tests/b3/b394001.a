-- B394001.A
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
--      Check that a primitive subprogram of an interface type cannot be a
--      subprogram that is neither an abstract subprogram nor a null procedure.
--
-- CHANGE HISTORY:
--      28 Oct 07   RLB     Created test based on existing ACATS test B393007.
--
--!

package B394001 is

   package Pkg1 is
      type Interf is limited interface;

      procedure My_Op (Obj : in Interf) is null;                      -- OK.
      function "+" (Obj : in Interf) return Interf is abstract;       -- OK.
   end Pkg1;

   package Pkg2 is
      type Interf_2 is interface and Pkg1.Interf;
      procedure My_Op (Obj : in Interf_2) is abstract;                -- OK.
      function "+" (Obj : in Interf_2)
          return Interf_2 is abstract;                                -- OK.
      procedure Another_Op (Obj : in Interf_2);                       -- ERROR:
      function My_Func (Obj : in Interf_2) return Boolean;            -- ERROR:
      procedure Another_Op (Cnt : in Natural; Obj : in Interf_2);     -- ERROR:
      function Acc_Func (Obj : access Interf_2) return Boolean;       -- ERROR:
      function Res_Func (Flag : Boolean) return access Interf_2;      -- ERROR:
      procedure Bad_Op (Ptr : access Interf_2);                       -- ERROR:
      procedure OK_Op (Ptr : access Interf_2) is null;                -- OK.
      function Double_Func (Obj,Obj2 : Interf_2) return Natural;      -- ERROR:
      procedure Copy (Target : out Interf_2; Source : in Interf_2);   -- ERROR:
      function Bool_Func (Obj : in Interf_2'Class) return Boolean;    -- OK.
      procedure Convert (Result : out Interf_2'Class;
                         Source : access Interf_2);                   -- ERROR:
   end Pkg2;

   package Pkg3 is
      type Interf_3 is task interface;
      function "+" (Op : Interf_3) return access Interf_3 is abstract;-- OK.
      function "-" (Op : Interf_3) return access Interf_3;            -- ERROR:
      procedure An_Op (Op : in out Interf_3) is null;                 -- OK.
      procedure Second_Op (Op : Interf_3);                            -- ERROR:
      procedure Third_Op (Code : in Character; Obj : in out Interf_3);-- ERROR:
   end Pkg3;

   package Pkg4 is
      type Interf_4 is protected interface and Pkg1.Interf;
      procedure My_Op (Obj : in Interf_4) is abstract;                -- OK.
      function "+" (Obj : in Interf_4)
         return Interf_4 is abstract;                                 -- OK.
      package Nested is
         -- These subprograms aren't primitive.
         procedure Second_Op (Op : in out Interf_4);                  -- OK:
         procedure Acc_Op (Ptr : access Interf_4);                    -- OK.
         function My_Func (Obj : Interf_4) return Boolean;            -- OK.
      end Nested;
   end Pkg4;

   generic
   package Pkg5 is
      type Interf_5 is limited interface and Pkg1.Interf;
      procedure My_Op (Obj : in Interf_5);                            -- ERROR:
      function "+" (Obj : in Interf_5)
          return Interf_5 is abstract;                                -- OK.
      procedure Another_Op (Obj : in Interf_5);                       -- ERROR:
      function My_Func (Obj : Interf_5) return Natural;               -- ERROR:
      procedure Third_Op (Obj : access Interf_5);                     -- ERROR:
   end Pkg5;

   generic
   package Pkg6 is
      type Interf6 is synchronized interface;
      procedure Pub_Op (Pi : in Float; Obj : in out Interf6)
           is abstract;                                               -- OK.
      procedure Another_Op (Obj : access Interf6);                    -- ERROR:
      function My_Func (Obj : access Interf6)
         return Natural;                                              -- ERROR:
      function Acc_Func (Count : Natural)
         return access Interf6;                                       -- ERROR:
      procedure Third_Op (Obj : access Interf6);                      -- ERROR:
   end Pkg6;

end B394001;
