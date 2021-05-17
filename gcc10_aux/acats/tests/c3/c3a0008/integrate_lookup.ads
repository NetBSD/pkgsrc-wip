-- C3A0008.A
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
--      Check that subprogram references may be passed as parameters using 
--      access-to-subprogram types. Check that the passed subprograms may 
--      be invoked from within the called subprogram.
--
-- TEST DESCRIPTION:
--      Declare an access to function type in a package specification.  
--      Declare three different trig functions that can be referred to by 
--      the access to function type.  
--
--      In the main program, call each function indirectly by passing the 
--      access to subprogram value as parameter.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!


package Integrate_Lookup is

  TC_Log_Call  : Boolean := False;

  TC_Cos_Call  : Boolean := False;

  TC_Sine_Call : Boolean := False;

  -- Type accesses to functions Log, Sine, or Cos
  type Integrand_Ptr is access function        
     (Angle : Float) return Float;

  function Log  (Angle : in Float) return Float;        

  function Sine (Angle : in Float) return Float;         

  function Cos  (Angle : in Float) return Float;        

  function Integrate  (Func : Integrand_Ptr; From, To: Float) 
    return Float;

end Integrate_Lookup;
