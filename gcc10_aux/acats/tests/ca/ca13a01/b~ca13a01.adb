pragma Warnings (Off);
pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b~ca13a01.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b~ca13a01.adb");
pragma Suppress (Overflow_Check);
with Ada.Exceptions;

package body ada_main is

   E090 : Short_Integer; pragma Import (Ada, E090, "system__os_lib_E");
   E024 : Short_Integer; pragma Import (Ada, E024, "ada__exceptions_E");
   E029 : Short_Integer; pragma Import (Ada, E029, "system__soft_links_E");
   E041 : Short_Integer; pragma Import (Ada, E041, "system__exception_table_E");
   E056 : Short_Integer; pragma Import (Ada, E056, "ada__containers_E");
   E083 : Short_Integer; pragma Import (Ada, E083, "ada__io_exceptions_E");
   E068 : Short_Integer; pragma Import (Ada, E068, "ada__strings_E");
   E070 : Short_Integer; pragma Import (Ada, E070, "ada__strings__maps_E");
   E074 : Short_Integer; pragma Import (Ada, E074, "ada__strings__maps__constants_E");
   E088 : Short_Integer; pragma Import (Ada, E088, "interfaces__c_E");
   E043 : Short_Integer; pragma Import (Ada, E043, "system__exceptions_E");
   E096 : Short_Integer; pragma Import (Ada, E096, "system__object_reader_E");
   E063 : Short_Integer; pragma Import (Ada, E063, "system__dwarf_lines_E");
   E037 : Short_Integer; pragma Import (Ada, E037, "system__soft_links__initialize_E");
   E055 : Short_Integer; pragma Import (Ada, E055, "system__traceback__symbolic_E");
   E116 : Short_Integer; pragma Import (Ada, E116, "ada__tags_E");
   E124 : Short_Integer; pragma Import (Ada, E124, "ada__streams_E");
   E132 : Short_Integer; pragma Import (Ada, E132, "system__file_control_block_E");
   E131 : Short_Integer; pragma Import (Ada, E131, "system__finalization_root_E");
   E129 : Short_Integer; pragma Import (Ada, E129, "ada__finalization_E");
   E128 : Short_Integer; pragma Import (Ada, E128, "system__file_io_E");
   E022 : Short_Integer; pragma Import (Ada, E022, "ada__calendar_E");
   E122 : Short_Integer; pragma Import (Ada, E122, "ada__text_io_E");
   E005 : Short_Integer; pragma Import (Ada, E005, "fa13a00_1_E");
   E013 : Short_Integer; pragma Import (Ada, E013, "fa13a00_1__fa13a00_2_E");
   E015 : Short_Integer; pragma Import (Ada, E015, "fa13a00_1__fa13a00_3_E");
   E011 : Short_Integer; pragma Import (Ada, E011, "fa13a00_1__ca13a01_4_E");
   E008 : Short_Integer; pragma Import (Ada, E008, "fa13a00_1__ca13a01_5_E");
   E017 : Short_Integer; pragma Import (Ada, E017, "fa13a00_1__ca13a01_6_E");
   E019 : Short_Integer; pragma Import (Ada, E019, "report_E");

   Sec_Default_Sized_Stacks : array (1 .. 1) of aliased System.Secondary_Stack.SS_Stack (System.Parameters.Runtime_Default_Sec_Stack_Size);

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure finalize_library is
   begin
      E122 := E122 - 1;
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
         E128 := E128 - 1;
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
      E041 := E041 + 1;
      Ada.Containers'Elab_Spec;
      E056 := E056 + 1;
      Ada.Io_Exceptions'Elab_Spec;
      E083 := E083 + 1;
      Ada.Strings'Elab_Spec;
      E068 := E068 + 1;
      Ada.Strings.Maps'Elab_Spec;
      E070 := E070 + 1;
      Ada.Strings.Maps.Constants'Elab_Spec;
      E074 := E074 + 1;
      Interfaces.C'Elab_Spec;
      E088 := E088 + 1;
      System.Exceptions'Elab_Spec;
      E043 := E043 + 1;
      System.Object_Reader'Elab_Spec;
      E096 := E096 + 1;
      System.Dwarf_Lines'Elab_Spec;
      E063 := E063 + 1;
      System.Os_Lib'Elab_Body;
      E090 := E090 + 1;
      System.Soft_Links.Initialize'Elab_Body;
      E037 := E037 + 1;
      E029 := E029 + 1;
      System.Traceback.Symbolic'Elab_Body;
      E055 := E055 + 1;
      E024 := E024 + 1;
      Ada.Tags'Elab_Spec;
      Ada.Tags'Elab_Body;
      E116 := E116 + 1;
      Ada.Streams'Elab_Spec;
      E124 := E124 + 1;
      System.File_Control_Block'Elab_Spec;
      E132 := E132 + 1;
      System.Finalization_Root'Elab_Spec;
      E131 := E131 + 1;
      Ada.Finalization'Elab_Spec;
      E129 := E129 + 1;
      System.File_Io'Elab_Body;
      E128 := E128 + 1;
      Ada.Calendar'Elab_Spec;
      Ada.Calendar'Elab_Body;
      E022 := E022 + 1;
      Ada.Text_Io'Elab_Spec;
      Ada.Text_Io'Elab_Body;
      E122 := E122 + 1;
      E005 := E005 + 1;
      E013 := E013 + 1;
      E015 := E015 + 1;
      E011 := E011 + 1;
      E008 := E008 + 1;
      E017 := E017 + 1;
      Report'Elab_Body;
      E019 := E019 + 1;
   end adainit;

   procedure Ada_Main_Program;
   pragma Import (Ada, Ada_Main_Program, "_ada_ca13a01");

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
   --   ./fa13a00_0.o
   --   /home/fernando/mysandboxfolder/tmp/acats/support/fa13a00_1.o
   --   /home/fernando/mysandboxfolder/tmp/acats/support/fa13a00_1-fa13a00_2.o
   --   /home/fernando/mysandboxfolder/tmp/acats/support/fa13a00_1-fa13a00_3.o
   --   ./fa13a00_1-ca13a01_4.o
   --   ./fa13a00_1-ca13a01_5.o
   --   ./fa13a00_1-ca13a01_6.o
   --   /home/fernando/mysandboxfolder/tmp/acats/support/report.o
   --   ./ca13a01.o
   --   -L./
   --   -L/home/fernando/mysandboxfolder/tmp/acats/support/
   --   -L/home/fernando/mysandboxfolder/usr/pkg/gcc10/lib/gcc/x86_64--netbsd/10.3.0/adalib/
   --   -static
   --   -lgnat
--  END Object file/option list   

end ada_main;
