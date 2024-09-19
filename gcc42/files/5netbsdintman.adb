------------------------------------------------------------------------------
--                                                                          --
--                GNU ADA RUN-TIME LIBRARY (GNARL) COMPONENTS               --
--                                                                          --
--           S Y S T E M . I N T E R R U P T _ M A N A G E M E N T          --
--                                                                          --
--                                  B o d y                                 --
--                                                                          --
--          Copyright (C) 1992-2002, Free Software Foundation, Inc.         --
--                                                                          --
-- GNARL is free software; you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 2,  or (at your option) any later ver- --
-- sion. GNARL is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNARL; see file COPYING.  If not, write --
-- to  the Free Software Foundation,  59 Temple Place - Suite 330,  Boston, --
-- MA 02111-1307, USA.                                                      --
--                                                                          --
-- As a special exception,  if other files  instantiate  generics from this --
-- unit, or you link  this unit with other files  to produce an executable, --
-- this  unit  does not  by itself cause  the resulting  executable  to  be --
-- covered  by the  GNU  General  Public  License.  This exception does not --
-- however invalidate  any other reasons why  the executable file  might be --
-- covered by the  GNU Public License.                                      --
--                                                                          --
-- GNARL was developed by the GNARL team at Florida State University.       --
-- Extensive contributions were provided by Ada Core Technologies, Inc.     --
--                                                                          --
------------------------------------------------------------------------------

--  This is the NetBSD threads version of this package

--  PLEASE DO NOT add any dependences on other packages. ??? why not ???
--  This package is designed to work with or without tasking support.

--  See the other warnings in the package specification before making
--  any modifications to this file.

--  Make a careful study of all signals available under the OS, to see which
--  need to be reserved, kept always unmasked, or kept always unmasked. Be on
--  the lookout for special signals that may be used by the thread library.

--  Since this is a multi target file, the signal <-> exception mapping
--  is simple minded. If you need a more precise and target specific
--  signal handling, create a new s-intman.adb that will fit your needs.

--  This file assumes that:

--    sigfpe, sigill, sigsegv and sigbus exist. They are mapped as follows:
--      sigfpe  => Constraint_Error
--      sigill  => Program_Error
--      sigill  => Storage_Error
--      sigbus  => Storage_Error

--    sigint exists and will be kept unmasked unless the pragma
--     Unreserve_All_Interrupts is specified anywhere in the application.

--    System.OS_Interface contains the following:
--      SIGADAABORT: the signal that will be used to abort tasks.
--      Unmasked: the OS specific set of signals that should be unmasked in
--                all the threads. SIGADAABORT is unmasked by
--                default
--      Reserved: the OS specific set of signals that are reserved.

with Interfaces.C;
--  used for int and other types

with System.OS_Interface;
--  used for various Constants, Signal and types

package body System.Interrupt_Management is

   use Interfaces.C;
   use System.OS_Interface;

   type Interrupt_List is array (Interrupt_ID range <>) of Interrupt_ID;
   Exception_Interrupts : constant Interrupt_List :=
     (sigfpe, sigill, sigsegv, sigbus);

   Unreserve_All_Interrupts : Interfaces.C.int;
   pragma Import
     (C, Unreserve_All_Interrupts, "__gl_unreserve_all_interrupts");

   -----------------------
   -- Local Subprograms --
   -----------------------

   procedure Notify_Exception (signo : Signal);
   --  This function identifies the Ada exception to be raised using
   --  the information when the system received a synchronous signal.
   --  Since this function is machine and OS dependent, different code
   --  has to be provided for different target.

   ----------------------
   -- Notify_Exception --
   ----------------------

   Signal_Mask : aliased sigset_t;
   --  The set of signals handled by Notify_Exception

   procedure Notify_Exception (signo : Signal) is
      Result  : Interfaces.C.int;

   begin
      --  With the __builtin_longjmp, the signal mask is not restored, so we
      --  need to restore it explicitely.

      Result := pthread_sigmask (SIG_UNBLOCK, Signal_Mask'Access, null);
      pragma Assert (Result = 0);

      --  Check that treatment of exception propagation here
      --  is consistent with treatment of the abort signal in
      --  System.Task_Primitives.Operations.

      case signo is
         when sigfpe =>
            raise Constraint_Error;
         when sigill =>
            raise Program_Error;
         when sigbus | sigsegv =>
            raise Storage_Error;
         when others =>
            null;
      end case;
   end Notify_Exception;

   ---------------------------
   -- Initialize_Interrupts --
   ---------------------------

   --  Nothing needs to be done on this platform.

   procedure Initialize_Interrupts is
   begin
      null;
   end Initialize_Interrupts;

-------------------------
-- Package Elaboration --
-------------------------

begin
   declare
      act     : aliased struct_sigaction;
      old_act : aliased struct_sigaction;
      Result  : System.OS_Interface.int;

      function State (Int : Interrupt_ID) return Character;
      pragma Import (C, State, "__gnat_get_interrupt_state");
      --  Get interrupt state.  Defined in a-init.c
      --  The input argument is the interrupt number,
      --  and the result is one of the following:

      User    : constant Character := 'u';
      Runtime : constant Character := 'r';
      Default : constant Character := 's';
      --    'n'   this interrupt not set by any Interrupt_State pragma
      --    'u'   Interrupt_State pragma set state to User
      --    'r'   Interrupt_State pragma set state to Runtime
      --    's'   Interrupt_State pragma set state to System (use "default"
      --           system handler)

   begin
      --  Need to call pthread_init very early because it is doing signal
      --  initializations.

      pthread_init;

      Abort_Task_Interrupt := SIGADAABORT;

      act.sa_handler := Notify_Exception'Address;

      act.sa_flags := 0;

      --  On some targets, we set sa_flags to SA_NODEFER so that during the
      --  handler execution we do not change the Signal_Mask to be masked for
      --  the Signal.

      --  This is a temporary fix to the problem that the Signal_Mask is
      --  not restored after the exception (longjmp) from the handler.
      --  The right fix should be made in sigsetjmp so that we save
      --  the Signal_Set and restore it after a longjmp.

      --  Since SA_NODEFER is obsolete, instead we reset explicitely
      --  the mask in the exception handler.

      Result := sigemptyset (Signal_Mask'Access);
      pragma Assert (Result = 0);

      --  Add signals that map to Ada exceptions to the mask.
      for J in Exception_Interrupts'Range loop
         if State (Exception_Interrupts (J)) /= Default  then
            Result :=
            sigaddset (Signal_Mask'Access, Signal (Exception_Interrupts (J)));
            pragma Assert (Result = 0);
         end if;
      end loop;

      act.sa_mask := Signal_Mask;

      pragma Assert (Keep_Unmasked = (Interrupt_ID'Range => False));
      pragma Assert (Reserve = (Interrupt_ID'Range => False));

      --  Process state of exception signals
      for J in Exception_Interrupts'Range loop
         if State (Exception_Interrupts (J)) /= User then
            Keep_Unmasked (Exception_Interrupts (J)) := True;
            Reserve (Exception_Interrupts (J)) := True;

            if State (Exception_Interrupts (J)) /= Default then
               Result :=
                 sigaction
                 (Signal (Exception_Interrupts (J)), act'Unchecked_Access,
                  old_act'Unchecked_Access);
               pragma Assert (Result = 0);
            end if;
         end if;
      end loop;

      if State (Abort_Task_Interrupt) /= User then
         Keep_Unmasked (Abort_Task_Interrupt) := True;
         Reserve (Abort_Task_Interrupt) := True;
      end if;

      --  Set sigint to unmasked state as long as it is not in "User"
      --  state. Check for Unreserve_All_Interrupts last

      if State (sigint) /= User then
         Keep_Unmasked (sigint) := True;
         Reserve (sigint) := True;
      end if;

      --  Check all signals for state that requires keeping them
      --  unmasked and reserved

      for J in Interrupt_ID'Range loop
         if State (J) = Default or else State (J) = Runtime then
            Keep_Unmasked (J) := True;
            Reserve (J) := True;
         end if;
      end loop;

      --  Add the set of signals that must always be unmasked for this target

      for J in Unmasked'Range loop
         Keep_Unmasked (Interrupt_ID (Unmasked (J))) := True;
         Reserve (Interrupt_ID (Unmasked (J))) := True;
      end loop;

      --  Add target-specific reserved signals

      for J in Reserved'Range loop
         Reserve (Interrupt_ID (Reserved (J))) := True;
      end loop;

      --  Process pragma Unreserve_All_Interrupts. This overrides any
      --  settings due to pragma Interrupt_State:

      if Unreserve_All_Interrupts /= 0 then
         Keep_Unmasked (sigint) := False;
         Reserve (sigint) := False;
      end if;

      --  We do not have Signal 0 in reality. We just use this value
      --  to identify non-existent signals (see s-intnam.ads). Therefore,
      --  Signal 0 should not be used in all signal related operations hence
      --  mark it as reserved.

      Reserve (0) := True;
   end;
end System.Interrupt_Management;
