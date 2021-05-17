-- CB20006.A
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
--      Check that exceptions are raised and properly handled (including 
--      propagation by reraise) in protected operations.
--
-- TEST DESCRIPTION:
--      Declare a package with a protected type, including protected operation
--      declarations and private data, simulating a counting semaphore.
--      In the main procedure, perform calls on protected operations 
--      of the protected object designed to induce the raising of exceptions.
--
--      The exceptions raised are to be initially handled in the protected
--      operations, but this handling involves the reraise of the exception
--      and the propagation of the exception to the caller.
--
--      Ensure that the exceptions are raised, handled / reraised successfully
--      in protected procedures and functions.  Use "others" handlers in the
--      protected operations.
--
--       
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package CB20006_0 is               -- Package Semaphore.

   Reraised_In_Function,
   Reraised_In_Procedure,
   Handled_In_Function_Caller,
   Handled_In_Procedure_Caller   : Boolean := False;

   Resource_Overflow,
   Resource_Underflow            : exception;

   protected type Counting_Semaphore (Max_Resources : Integer) is
      procedure Secure;
      function  Resource_Limit_Exceeded return Boolean;
      procedure Release;
   private
      Count : Integer := Max_Resources;
   end Counting_Semaphore;

end CB20006_0;
