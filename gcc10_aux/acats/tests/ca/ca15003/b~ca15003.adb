pragma Warnings (Off);
pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b~ca15003.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b~ca15003.adb");
pragma Suppress (Overflow_Check);
with Ada.Exceptions;

package body ada_main is

   E088 : Short_Integer; pragma Import (Ada, E088, "system__os_lib_E");
   E022 : Short_Integer; pragma Import (Ada, E022, "ada__exceptions_E");
   E026 : Short_Integer; pragma Import (Ada, E026, "system__soft_links_E");
   E038 : Short_Integer; pragma Import (Ada, E038, "system__exception_table_E");
   E053 : Short_Integer; pragma Import (Ada, E053, "ada__containers_E");
   E081 : Short_Integer; pragma Import (Ada, E081, "ada__io_exceptions_E");
   E065 : Short_Integer; pragma Import (Ada, E065, "ada__strings_E");
   E067 : Short_Integer; pragma Import (Ada, E067, "ada__strings__maps_E");
   E071 : Short_Integer; pragma Import (Ada, E071, "ada__strings__maps__constants_E");
   E086 : Short_Integer; pragma Import (Ada, E086, "interfaces__c_E");
   E040 : Short_Integer; pragma Import (Ada, E040, "system__exceptions_E");
   E094 : Short_Integer; pragma Import (Ada, E094, "system__object_reader_E");
   E060 : Short_Integer; pragma Import (Ada, E060, "system__dwarf_lines_E");
   E034 : Short_Integer; pragma Import (Ada, E034, "system__soft_links__initialize_E");
   E052 : Short_Integer; pragma Import (Ada, E052, "system__traceback__symbolic_E");
   E114 : Short_Integer; pragma Import (Ada, E114, "ada__tags_E");
   E122 : Short_Integer; pragma Import (Ada, E122, "ada__streams_E");
   E130 : Short_Integer; pragma Import (Ada, E130, "system__file_control_block_E");
   E129 : Short_Integer; pragma Import (Ada, E129, "system__finalization_root_E");
   E127 : Short_Integer; pragma Import (Ada, E127, "ada__finalization_E");
   E126 : Short_Integer; pragma Import (Ada, E126, "system__file_io_E");
   E020 : Short_Integer; pragma Import (Ada, E020, "ada__calendar_E");
   E120 : Short_Integer; pragma Import (Ada, E120, "ada__text_io_E");
   E017 : Short_Integer; pragma Import (Ada, E017, "report_E");
   E007 : Short_Integer; pragma Import (Ada, E007, "ca15003a__empty_elaborate_body_E");

   Sec_Default_Sized_Stacks : array (1 .. 1) of aliased System.Secondary_Stack.SS_Stack (System.Parameters.Runtime_Default_Sec_Stack_Size);

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure finalize_library is
   begin
      E120 := E120 - 1;
      declare
         procedure F1;
         pragma Import (Ada, F1, "ada__text_io__finalize_spec");
      begin
         F1;
      end;
      declare
         procedure F2;
         pragma Import (Ada, F2, "system__file_io__finalize_body");
      begin
         E126 := E126 - 1;
         F2;
      end;
      declare
         procedure Reraise_Library_Exception_If_Any;
            pragma Import (Ada, Reraise_Library_Exception_If_Any, "__gnat_reraise_library_exception_if_any");
      begin
         Reraise_Library_Exception_If_Any;
      end;
   end finalize_library;

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

      Finalize_Library_Objects := finalize_library'access;

      Ada.Exceptions'Elab_Spec;
      System.Soft_Links'Elab_Spec;
      System.Exception_Table'Elab_Body;
      E038 := E038 + 1;
      Ada.Containers'Elab_Spec;
      E053 := E053 + 1;
      Ada.Io_Exceptions'Elab_Spec;
      E081 := E081 + 1;
      Ada.Strings'Elab_Spec;
      E065 := E065 + 1;
      Ada.Strings.Maps'Elab_Spec;
      E067 := E067 + 1;
      Ada.Strings.Maps.Constants'Elab_Spec;
      E071 := E071 + 1;
      Interfaces.C'Elab_Spec;
      E086 := E086 + 1;
      System.Exceptions'Elab_Spec;
      E040 := E040 + 1;
      System.Object_Reader'Elab_Spec;
      E094 := E094 + 1;
      System.Dwarf_Lines'Elab_Spec;
      E060 := E060 + 1;
      System.Os_Lib'Elab_Body;
      E088 := E088 + 1;
      System.Soft_Links.Initialize'Elab_Body;
      E034 := E034 + 1;
      E026 := E026 + 1;
      System.Traceback.Symbolic'Elab_Body;
      E052 := E052 + 1;
      E022 := E022 + 1;
      Ada.Tags'Elab_Spec;
      Ada.Tags'Elab_Body;
      E114 := E114 + 1;
      Ada.Streams'Elab_Spec;
      E122 := E122 + 1;
      System.File_Control_Block'Elab_Spec;
      E130 := E130 + 1;
      System.Finalization_Root'Elab_Spec;
      E129 := E129 + 1;
      Ada.Finalization'Elab_Spec;
      E127 := E127 + 1;
      System.File_Io'Elab_Body;
      E126 := E126 + 1;
      Ada.Calendar'Elab_Spec;
      Ada.Calendar'Elab_Body;
      E020 := E020 + 1;
      Ada.Text_Io'Elab_Spec;
      Ada.Text_Io'Elab_Body;
      E120 := E120 + 1;
      Report'Elab_Body;
      E017 := E017 + 1;
      CA15003A.EMPTY_ELABORATE_BODY'ELAB_BODY;
      E007 := E007 + 1;
   end adainit;

   procedure Ada_Main_Program;
   pragma Import (Ada, Ada_Main_Program, "_ada_ca15003");

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
   --   ./ca15003a.o
   --   ./ca15003a-empty_preelaborate.o
   --   ./ca15003a-empty_pure.o
   --   ./ca15003a-pure.o
   --   ./ca15003a-pure-preelaborate.o
   --   ./ca15003a-pure_instance.o
   --   ./ca15003a-pure_preelaborate_instance.o
   --   /home/fernando/mysandboxfolder/tmp/acats/support/report.o
   --   ./ca15003a-empty_elaborate_body.o
   --   ./ca15003.o
   --   -L./
   --   -L/home/fernando/mysandboxfolder/tmp/acats/support/
   --   -L/home/fernando/mysandboxfolder/usr/pkg/gcc10/lib/gcc/x86_64--netbsd/10.3.0/adalib/
   --   -static
   --   -lgnat
--  END Object file/option list   

end ada_main;
