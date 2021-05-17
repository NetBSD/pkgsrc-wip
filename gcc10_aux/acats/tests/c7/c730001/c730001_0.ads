-- C730001.A
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
--      Check that the full view of a private extension may be derived
--      indirectly from the ancestor type (i.e., the parent type of the full
--      type may be any descendant of the ancestor type). Check that, for
--      a primitive subprogram of the private extension that is inherited from
--      the ancestor type and not overridden, the formal parameter names and
--      default expressions come from the corresponding primitive subprogram
--      of the ancestor type, while the body comes from that of the parent
--      type.  Check both dispatching and non-dispatching cases.
--
-- TEST DESCRIPTION:
--      Consider:
--
--      package P is
--         type Ancestor is tagged ...
--         procedure Op (P1: Ancestor; P2: Boolean := True);
--      end P;
--
--      with P;
--      package Q is
--         type Derived is new P.Ancestor with ...
--         procedure Op (X: Ancestor; Y: Boolean := False);
--      end Q;
--
--      with P, Q;
--      package R is
--         type Priv_Ext is new P.Ancestor with private;   -- (A)
--         -- Inherits procedure Op (P1: Priv_Ext; P2: Boolean := True);
--         -- But body executed is that of Q.Op.
--      private
--         type Priv_Ext is new Q.Derived with record ...  -- (B)
--      end R;
--
--      The ancestor type in (A) differs from the parent type in (B); the
--      parent of the full type is descended from the ancestor type of the
--      private extension. For a call to Op (from outside the scope of the
--      full view) with an operand of type Priv_Ext, the formal parameter
--      names and default expression come from that of P.Op (the ancestor
--      type's version), but the body executed will be that of 
--      Q.Op (the parent type's version)
--
--      One half of the test mirrors the above template, where an inherited
--      subprogram (Set_Display) is called using the formal parameter 
--      name (C) and default parameter expression of the ancestor type's 
--      version (type Clock), but the version of the body executed is from
--      the parent type.
--
--      The test also includes an examination of the dynamic evaluation
--      case, where correct body associations are required through dispatching 
--      calls.  As described for the non-dispatching case above, the formal
--      parameter name and default values of the ancestor type's (Phone) 
--      version of the inherited subprogram (Answer) are used in the 
--      dispatching call, but the body executed is from the parent type.
--      
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package C730001_0 is

   type Display_Kind      is (None, Analog, Digital);
   type Illumination_Type is (None, Light, Phosphorescence);
   type Capability_Type   is (Available, In_Use, Call_Waiting, Conference);
   type Indicator_Type    is (None, Light, Bell, Buzzer, Click, Modem);

   type Clock is abstract tagged record           -- ancestor type associated
      Display      : Display_Kind      := None;   -- with non-dispatching case.
      Illumination : Illumination_Type := None;
   end record;

   type Phone is tagged record                    -- ancestor type associated
      Status    : Capability_Type := Available;   -- with dispatching case.
      Indicator : Indicator_Type  := None;
   end record;

   -- The Set_Display procedure for type Clock implements a basic, no-frills
   -- clock display.
   procedure Set_Display (C   : in out Clock;
                          Disp: in     Display_Kind := Digital);

   -- The Answer procedure for type Phone implements a phone status change
   -- operation.
   procedure Answer (The_Phone : in out Phone;
                     Ind       : in     Indicator_Type := Light);
   -- ...Other general clock and/or phone operations (not specified in this
   -- test scenario).

end C730001_0;
