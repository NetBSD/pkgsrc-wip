pragma Warnings (Off);
pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b~send_sigint_to_parent.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b~send_sigint_to_parent.adb");
pragma Suppress (Overflow_Check);

package body ada_main is

   E70 : Short_Integer; pragma Import (Ada, E70, "system__os_lib_E");
   E14 : Short_Integer; pragma Import (Ada, E14, "ada__exceptions_E");
   E09 : Short_Integer; pragma Import (Ada, E09, "system__soft_links_E");
   E07 : Short_Integer; pragma Import (Ada, E07, "system__exception_table_E");
   E33 : Short_Integer; pragma Import (Ada, E33, "ada__containers_E");
   E63 : Short_Integer; pragma Import (Ada, E63, "ada__io_exceptions_E");
   E47 : Short_Integer; pragma Import (Ada, E47, "ada__strings_E");
   E49 : Short_Integer; pragma Import (Ada, E49, "ada__strings__maps_E");
   E53 : Short_Integer; pragma Import (Ada, E53, "ada__strings__maps__constants_E");
   E68 : Short_Integer; pragma Import (Ada, E68, "interfaces__c_E");
   E18 : Short_Integer; pragma Import (Ada, E18, "system__exceptions_E");
   E76 : Short_Integer; pragma Import (Ada, E76, "system__object_reader_E");
   E42 : Short_Integer; pragma Import (Ada, E42, "system__dwarf_lines_E");
   E94 : Short_Integer; pragma Import (Ada, E94, "system__soft_links__initialize_E");
   E32 : Short_Integer; pragma Import (Ada, E32, "system__traceback__symbolic_E");
   E04 : Short_Integer; pragma Import (Ada, E04, "gnat_E");

   Sec_Default_Sized_Stacks : array (1 .. 1) of aliased System.Secondary_Stack.SS_Stack (System.Parameters.Runtime_Default_Sec_Stack_Size);

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure adafinal is
      procedure s_stalib_adafinal;
      pragma Import (C, s_stalib_adafinal, "system__standard_library__adafinal");

      procedure Runtime_Finalize;
      pragma Import (C, Runtime_Finalize, "__gnat_runtime_finalize");

   begin
      if not Is_Elaborated then
         return;
      end if;
      Is_Elaborated := False;
      Runtime_Finalize;
      s_stalib_adafinal;
   end adafinal;

   type No_Param_Proc is access procedure;
   pragma Favor_Top_Level (No_Param_Proc);

   procedure adainit is
      Main_Priority : Integer;
      pragma Import (C, Main_Priority, "__gl_main_priority");
      Time_Slice_Value : Integer;
      pragma Import (C, Time_Slice_Value, "__gl_time_slice_val");
      WC_Encoding : Character;
      pragma Import (C, WC_Encoding, "__gl_wc_encoding");
      Locking_Policy : Character;
      pragma Import (C, Locking_Policy, "__gl_locking_policy");
      Queuing_Policy : Character;
      pragma Import (C, Queuing_Policy, "__gl_queuing_policy");
      Task_Dispatching_Policy : Character;
      pragma Import (C, Task_Dispatching_Policy, "__gl_task_dispatching_policy");
      Priority_Specific_Dispatching : System.Address;
      pragma Import (C, Priority_Specific_Dispatching, "__gl_priority_specific_dispatching");
      Num_Specific_Dispatching : Integer;
      pragma Import (C, Num_Specific_Dispatching, "__gl_num_specific_dispatching");
      Main_CPU : Integer;
      pragma Import (C, Main_CPU, "__gl_main_cpu");
      Interrupt_States : System.Address;
      pragma Import (C, Interrupt_States, "__gl_interrupt_states");
      Num_Interrupt_States : Integer;
      pragma Import (C, Num_Interrupt_States, "__gl_num_interrupt_states");
      Unreserve_All_Interrupts : Integer;
      pragma Import (C, Unreserve_All_Interrupts, "__gl_unreserve_all_interrupts");
      Detect_Blocking : Integer;
      pragma Import (C, Detect_Blocking, "__gl_detect_blocking");
      Default_Stack_Size : Integer;
      pragma Import (C, Default_Stack_Size, "__gl_default_stack_size");
      Default_Secondary_Stack_Size : System.Parameters.Size_Type;
      pragma Import (C, Default_Secondary_Stack_Size, "__gnat_default_ss_size");
      Leap_Seconds_Support : Integer;
      pragma Import (C, Leap_Seconds_Support, "__gl_leap_seconds_support");
      Bind_Env_Addr : System.Address;
      pragma Import (C, Bind_Env_Addr, "__gl_bind_env_addr");

      procedure Runtime_Initialize (Install_Handler : Integer);
      pragma Import (C, Runtime_Initialize, "__gnat_runtime_initialize");

      Finalize_Library_Objects : No_Param_Proc;
      pragma Import (C, Finalize_Library_Objects, "__gnat_finalize_library_objects");
      Binder_Sec_Stacks_Count : Natural;
      pragma Import (Ada, Binder_Sec_Stacks_Count, "__gnat_binder_ss_count");
      Default_Sized_SS_Pool : System.Address;
      pragma Import (Ada, Default_Sized_SS_Pool, "__gnat_default_ss_pool");

   begin
      if Is_Elaborated then
         return;
      end if;
      Is_Elaborated := True;
      Main_Priority := -1;
      Time_Slice_Value := -1;
      WC_Encoding := 'b';
      Locking_Policy := ' ';
      Queuing_Policy := ' ';
      Task_Dispatching_Policy := ' ';
      Priority_Specific_Dispatching :=
        Local_Priority_Specific_Dispatching'Address;
      Num_Specific_Dispatching := 0;
      Main_CPU := -1;
      Interrupt_States := Local_Interrupt_States'Address;
      Num_Interrupt_States := 0;
      Unreserve_All_Interrupts := 0;
      Detect_Blocking := 0;
      Default_Stack_Size := -1;
      Leap_Seconds_Support := 0;

      ada_main'Elab_Body;
      Default_Secondary_Stack_Size := System.Parameters.Runtime_Default_Sec_Stack_Size;
      Binder_Sec_Stacks_Count := 1;
      Default_Sized_SS_Pool := Sec_Default_Sized_Stacks'Address;

      Runtime_Initialize (1);

      Finalize_Library_Objects := null;

      Ada.Exceptions'Elab_Spec;
      System.Soft_Links'Elab_Spec;
      System.Exception_Table'Elab_Body;
      E07 := E07 + 1;
      Ada.Containers'Elab_Spec;
      E33 := E33 + 1;
      Ada.Io_Exceptions'Elab_Spec;
      E63 := E63 + 1;
      Ada.Strings'Elab_Spec;
      E47 := E47 + 1;
      Ada.Strings.Maps'Elab_Spec;
      E49 := E49 + 1;
      Ada.Strings.Maps.Constants'Elab_Spec;
      E53 := E53 + 1;
      Interfaces.C'Elab_Spec;
      E68 := E68 + 1;
      System.Exceptions'Elab_Spec;
      E18 := E18 + 1;
      System.Object_Reader'Elab_Spec;
      E76 := E76 + 1;
      System.Dwarf_Lines'Elab_Spec;
      E42 := E42 + 1;
      System.Os_Lib'Elab_Body;
      E70 := E70 + 1;
      System.Soft_Links.Initialize'Elab_Body;
      E94 := E94 + 1;
      E09 := E09 + 1;
      System.Traceback.Symbolic'Elab_Body;
      E32 := E32 + 1;
      E14 := E14 + 1;
      Gnat'Elab_Spec;
      E04 := E04 + 1;
   end adainit;

   procedure Ada_Main_Program;
   pragma Import (Ada, Ada_Main_Program, "_ada_send_sigint_to_parent");

   function main
     (argc : Integer;
      argv : System.Address;
      envp : System.Address)
      return Integer
   is
      procedure Initialize (Addr : System.Address);
      pragma Import (C, Initialize, "__gnat_initialize");

      procedure Finalize;
      pragma Import (C, Finalize, "__gnat_finalize");
      SEH : aliased array (1 .. 2) of Integer;

      Ensure_Reference : aliased System.Address := Ada_Main_Program_Name'Address;
      pragma Volatile (Ensure_Reference);

   begin
      if gnat_argc = 0 then
         gnat_argc := argc;
         gnat_argv := argv;
      end if;
      gnat_envp := envp;

      Initialize (SEH'Address);
      adainit;
      Ada_Main_Program;
      adafinal;
      Finalize;
      return (gnat_exit_status);
   end;

--  BEGIN Object file/option list
   --   ./send_sigint_to_parent.o
   --   -L./
   --   -L/home/fernando/mysandboxfolder/usr/pkg/gcc10/lib/gcc/x86_64--netbsd/10.3.0/adalib/
   --   -static
   --   -lgnat
--  END Object file/option list   

end ada_main;
