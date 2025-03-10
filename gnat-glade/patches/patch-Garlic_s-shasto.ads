$NetBSD: patch-Garlic_s-shasto.ads,v 1.0 2025/02/13 21:00:00 dkazankov Exp $

Remove unsupported old specification

--- Garlic/s-shasto.ads.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-shasto.ads
@@ -1,206 +0,0 @@
-------------------------------------------------------------------------------
---                                                                          --
---                            GLADE COMPONENTS                              --
---                                                                          --
---                S Y S T E M . S H A R E D _ S T O R A G E                 --
---                                                                          --
---                                 S p e c                                  --
---                                                                          --
---         Copyright (C) 1996-2006 Free Software Foundation, Inc.           --
---                                                                          --
--- GARLIC is free software;  you can redistribute it and/or modify it under --
--- terms of the  GNU General Public License  as published by the Free Soft- --
--- ware Foundation;  either version 2,  or (at your option)  any later ver- --
--- sion.  GARLIC is distributed  in the hope that  it will be  useful,  but --
--- WITHOUT ANY WARRANTY;  without even the implied warranty of MERCHANTABI- --
--- LITY or  FITNESS FOR A PARTICULAR PURPOSE.  See the  GNU General Public  --
--- License  for more details.  You should have received  a copy of the GNU  --
--- General Public License  distributed with GARLIC;  see file COPYING.  If  --
--- not, write to the Free Software Foundation, 59 Temple Place - Suite 330, --
--- Boston, MA 02111-1307, USA.                                              --
---                                                                          --
--- As a special exception,  if other files  instantiate  generics from this --
--- unit, or you link  this unit with other files  to produce an executable, --
--- this  unit  does not  by itself cause  the resulting  executable  to  be --
--- covered  by the  GNU  General  Public  License.  This exception does not --
--- however invalidate  any other reasons why  the executable file  might be --
--- covered by the  GNU Public License.                                      --
---                                                                          --
---               GLADE  is maintained by ACT Europe.                        --
---               (email: glade-report@act-europe.fr)                        --
---                                                                          --
-------------------------------------------------------------------------------
-
-with Ada.Streams.Stream_IO;
-
-package System.Shared_Storage is
-
-   --  This package manages the shared/persistant memory required for
-   --  full implementation of variables in Shared_Passive packages,
-   --  more precisely variables whose enclosing dynamic scope is a
-   --  shared passive package.
-
-   --  -------------------------
-   --  -- Shared Storage Model --
-   --  -------------------------
-
-   --  The basic model used is that each partition that references the
-   --  Shared_Passive package has a local copy of the package data
-   --  that is initialized in accordance with the declarations of the
-   --  package in the normal manner. The routines in
-   --  System.Shared_Memory are then used to ensure that the values in
-   --  these separate copies are properly synchronized with the state
-   --  of the overall system.
-
-   --  This synchronization is ensured by maintaining a set of files
-   --  in a designated directory. The directory is designated by
-   --  setting the environment variable SHARED_MEMORY_DIRECTORY. This
-   --  variable must be set for all partitions. If the environment
-   --  variable is not defined, then the current directory is used.
-
-   --  There is one file for each variable. The name is the fully
-   --  qualified name of the variable with all letters forced to lower
-   --  case. For example, the variable Key_Name in the Shared_Passive
-   --  package Shared_Data results in the file name
-   --  shared_data.key_name.
-
-   --  If the file does not exist, it indicates that no partition has
-   --  assigned a new value, so that the initial value is the correct
-   --  one. This is the critical component of the model. It means that
-   --  there is no system-wide synchronization required for
-   --  initializing the package, since the shared memory files need
-   --  not (and do not) reflect the initial state. There is therefore
-   --  no issue of synchronizing initialization and read/write
-   --  accress.
-
-   --  If the file does exist, it is a Stream_IO file that contains
-   --  the most recently assigned value of the variable, as written by
-   --  the use of the typ'Write stream attribute.
-
-   --  -----------------------
-   --  -- Read/Write Access --
-   --  -----------------------
-
-   --  The approach is as follows:
-
-   --    For each shared variable, var, an access routine varR is
-   --  created whose body has the following form (this example is for
-   --  Pkg.Var):
-
-   --      procedure varR is
-   --         S : Ada.Streams.Stream_IO.Stream_Access;
-   --      begin
-   --         S := Shared_Mem_RFile ("pkg", "var");
-   --         if S /= null then
-   --            typ'Read (S);
-   --         end if;
-   --      end varR;
-
-   --  The routine Shared_Mem_RFile in package System.Shared_Memory
-   --  either returns null if the file does not exist, or otherwise a
-   --  Stream_Access value that references the corresponding shared
-   --  memory file, positioned at start of the file, ready to read the
-   --  current value.
-
-   --  Each reference to the shared variable, var, is preceded by a
-   --  call to the corresponding varR procedure, which either leaves
-   --  the initial value unchanged if the file does not exist, or
-   --  reads the current value from the shared memory file.
-
-   --  In addition, for each shared variable, var, an assignment
-   --  routine is created whose body has the following form (again for
-   --  Pgg.Var)
-
-   --      procedure VarA is
-   --      begin
-   --         typ'Write (Shared_Mem_WFile ("pkg", "var"), var);
-   --      end VarA;
-
-   --  The routine Shared_Mem_WFile is package System.Shared_Memory
-   --  returns a Stream_Access value that references the corresponding
-   --  shared memory file, positioned at the start, ready to write the
-   --  new value.
-
-   --  Each assignment to the shared variable, var, is followed by a
-   --  call to the corresponding varA procedure, which writes the new
-   --  value to the shared memory file.
-
-   --  Note that there is no synchronization for these file read and
-   --  write operations, since it is assumed that a correctly
-   --  operating programs will provide appropriate synchronization. In
-   --  particular, variables can be protected using protected types
-   --  with no entries.
-
-   --  Note: a special circuit allows the use of stream attributes
-   --  Read and Write for limited types (using the corresponding
-   --  attribute for the full type), but there are limitations on the
-   --  data that can be placed in shared passive partitions. See
-   --  sem_smem.ads/adb for details.
-
-   --  ----------------------------------------------------------------
-   --  -- Handling of Protected Objects in Shared Passive Partitions --
-   --  ----------------------------------------------------------------
-
-   --  During the execution of a protected subprogram call, access is
-   --  locked out using a global locking mechanism, as provided by the
-   --  GNAT.Lock_Files capability. This package contains the lock and
-   --  unlock calls, and the expander generates a call to the lock
-   --  routine before the protected call and a call to the unlock
-   --  routine after the protected call.
-
-   --  Within the code of the protected subprogram, the access to the
-   --  protected object itself uses the local copy, without any
-   --  special synchronization.  Since global access is locked out, no
-   --  other task or partition can attempt to read or write this data
-   --  as long as the lock is held.
-
-   --  The data in the local copy does however need synchronizing with
-   --  the global values in the shared memory file. This is achieved
-   --  as follows:
-
-   --  The protected object generates a read and assignment routine as
-   --  described for other shared passive variables. The code for the
-   --  'Read and 'Write attributes (not normally allowed, but allowed
-   --  in this special case) simply reads or writes the values of the
-   --  components in the protected record.
-
-   --  The lock call is followed by a call to the shared read routine
-   --  to synchronize the local copy to contain the proper global
-   --  value.
-
-   --  The unlock call in the procedure case only is preceded by a
-   --  call to the shared assign routine to synchronize the global
-   --  shared memory files with the (possibly modified) local copy.
-
-   --  These calls to the read and assign routines, as well as the
-   --  lock and unlock routines, are inserted by the expander (see
-   --  exp_smem.adb).
-
-   package SIO renames Ada.Streams.Stream_IO;
-
-   function Shared_Var_ROpen (Var : String) return SIO.Stream_Access;
-   --  As described above, this routine returns null if the corresponding
-   --  shared memory file does not exist, and otherwise, if the file does
-   --  exist, a Stream_Access value that references the shared memory file,
-   --  positioned to the start, ready to read the current value.
-
-   function Shared_Var_WOpen (Var : String) return SIO.Stream_Access;
-   --  As described above, this routine returns a Stream_Access value that
-   --  references the shared memory file, positioned to the start, ready to
-   --  write the new value. The file is created by this call if it does not
-   --  already exist.
-
-   procedure Shared_Var_Lock (Var : String);
-   --  This procedure claims the global shared memory lock. It is used for
-   --  protected types in shared passive packages. A call to this locking
-   --  routine is generated as the first operation in the code for the body
-   --  of a protected subprogram, and it busy waits if the lock is busy.
-
-   procedure Shared_Var_Unlock (Var : String);
-   --  This procedure releases the lock obtaind by a prior call to the
-   --  Shared_Mem_Lock procedure, and is to be generated as the last
-   --  operation in the body of a protected subprogram.
-
-   procedure Shared_Var_Close (Var : in out SIO.Stream_Access);
-
-end System.Shared_Storage;
