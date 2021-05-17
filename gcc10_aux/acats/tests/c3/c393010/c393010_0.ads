-- C393010.A
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
-- TEST OBJECTIVE:
--      Check that an extended type can be derived from an abstract type and
--      that a call on an abstract operation is a dispatching operation.
--      Check that such a call can dispatch to an overriding operation
--      declared in the private part of a package.
--
-- TEST DESCRIPTION:
--      Taking from a classroom example of a typical usage: declare a basic
--      abstract type containing data germane to the entire class structure,
--      derive from that a type with specific data, and derive from that
--      another type merely providing a "secret" override.  The abstract type
--      provides a concrete procedure that itself "redispatches" to an
--      abstract procedure; the abstract procedure must be provided by one or
--      more of the concrete types derived from the abstract type, and hence
--      upon re-evaluating the actual type of the operand should dispatch
--      accordingly.
--
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      15 Mar 96   SAIC    ACVC 2.1
--
--!

----------------------------------------------------------------- C393010_0

package C393010_0 is

  type Ticket is abstract tagged record
    Flight        : Natural;
    Serial_Number : Natural;
  end record;

  function Issue return Ticket is abstract;
  procedure Label( T: Ticket ) is abstract;

  procedure Print( T: Ticket );

end C393010_0;
