pragma Warnings (Off);
pragma Ada_95;
with System;
with System.Parameters;
with System.Secondary_Stack;
package ada_main is

   gnat_argc : Integer;
   gnat_argv : System.Address;
   gnat_envp : System.Address;

   pragma Import (C, gnat_argc);
   pragma Import (C, gnat_argv);
   pragma Import (C, gnat_envp);

   gnat_exit_status : Integer;
   pragma Import (C, gnat_exit_status);

   GNAT_Version : constant String :=
                    "GNAT Version: 10.3.0" & ASCII.NUL;
   pragma Export (C, GNAT_Version, "__gnat_version");

   Ada_Main_Program_Name : constant String := "_ada_c94010a" & ASCII.NUL;
   pragma Export (C, Ada_Main_Program_Name, "__gnat_ada_main_program_name");

   procedure adainit;
   pragma Export (C, adainit, "adainit");

   procedure adafinal;
   pragma Export (C, adafinal, "adafinal");

   function main
     (argc : Integer;
      argv : System.Address;
      envp : System.Address)
      return Integer;
   pragma Export (C, main, "main");

   type Version_32 is mod 2 ** 32;
   u00001 : constant Version_32 := 16#460b6ce9#;
   pragma Export (C, u00001, "c94010aB");
   u00002 : constant Version_32 := 16#050ff2f0#;
   pragma Export (C, u00002, "system__standard_libraryB");
   u00003 : constant Version_32 := 16#a1710c38#;
   pragma Export (C, u00003, "system__standard_libraryS");
   u00004 : constant Version_32 := 16#357666d8#;
   pragma Export (C, u00004, "ada__calendar__delaysB");
   u00005 : constant Version_32 := 16#d86d2f1d#;
   pragma Export (C, u00005, "ada__calendar__delaysS");
   u00006 : constant Version_32 := 16#fc54e290#;
   pragma Export (C, u00006, "ada__calendarB");
   u00007 : constant Version_32 := 16#31350a81#;
   pragma Export (C, u00007, "ada__calendarS");
   u00008 : constant Version_32 := 16#76789da1#;
   pragma Export (C, u00008, "adaS");
   u00009 : constant Version_32 := 16#f832ebf4#;
   pragma Export (C, u00009, "ada__exceptionsB");
   u00010 : constant Version_32 := 16#363575b8#;
   pragma Export (C, u00010, "ada__exceptionsS");
   u00011 : constant Version_32 := 16#5726abed#;
   pragma Export (C, u00011, "ada__exceptions__last_chance_handlerB");
   u00012 : constant Version_32 := 16#cfec26ee#;
   pragma Export (C, u00012, "ada__exceptions__last_chance_handlerS");
   u00013 : constant Version_32 := 16#a6571217#;
   pragma Export (C, u00013, "systemS");
   u00014 : constant Version_32 := 16#ae860117#;
   pragma Export (C, u00014, "system__soft_linksB");
   u00015 : constant Version_32 := 16#6d5d6a61#;
   pragma Export (C, u00015, "system__soft_linksS");
   u00016 : constant Version_32 := 16#1349bf20#;
   pragma Export (C, u00016, "system__secondary_stackB");
   u00017 : constant Version_32 := 16#e3c3ea0e#;
   pragma Export (C, u00017, "system__secondary_stackS");
   u00018 : constant Version_32 := 16#86dbf443#;
   pragma Export (C, u00018, "system__parametersB");
   u00019 : constant Version_32 := 16#eebb463c#;
   pragma Export (C, u00019, "system__parametersS");
   u00020 : constant Version_32 := 16#ced09590#;
   pragma Export (C, u00020, "system__storage_elementsB");
   u00021 : constant Version_32 := 16#8b945813#;
   pragma Export (C, u00021, "system__storage_elementsS");
   u00022 : constant Version_32 := 16#75bf515c#;
   pragma Export (C, u00022, "system__soft_links__initializeB");
   u00023 : constant Version_32 := 16#5697fc2b#;
   pragma Export (C, u00023, "system__soft_links__initializeS");
   u00024 : constant Version_32 := 16#41837d1e#;
   pragma Export (C, u00024, "system__stack_checkingB");
   u00025 : constant Version_32 := 16#28e879ff#;
   pragma Export (C, u00025, "system__stack_checkingS");
   u00026 : constant Version_32 := 16#34742901#;
   pragma Export (C, u00026, "system__exception_tableB");
   u00027 : constant Version_32 := 16#fbf97b55#;
   pragma Export (C, u00027, "system__exception_tableS");
   u00028 : constant Version_32 := 16#ce4af020#;
   pragma Export (C, u00028, "system__exceptionsB");
   u00029 : constant Version_32 := 16#ce347fe1#;
   pragma Export (C, u00029, "system__exceptionsS");
   u00030 : constant Version_32 := 16#69416224#;
   pragma Export (C, u00030, "system__exceptions__machineB");
   u00031 : constant Version_32 := 16#5c74e542#;
   pragma Export (C, u00031, "system__exceptions__machineS");
   u00032 : constant Version_32 := 16#aa0563fc#;
   pragma Export (C, u00032, "system__exceptions_debugB");
   u00033 : constant Version_32 := 16#d8ddebd3#;
   pragma Export (C, u00033, "system__exceptions_debugS");
   u00034 : constant Version_32 := 16#6c2f8802#;
   pragma Export (C, u00034, "system__img_intB");
   u00035 : constant Version_32 := 16#a48cf2d5#;
   pragma Export (C, u00035, "system__img_intS");
   u00036 : constant Version_32 := 16#39df8c17#;
   pragma Export (C, u00036, "system__tracebackB");
   u00037 : constant Version_32 := 16#f875ccd3#;
   pragma Export (C, u00037, "system__tracebackS");
   u00038 : constant Version_32 := 16#9ed49525#;
   pragma Export (C, u00038, "system__traceback_entriesB");
   u00039 : constant Version_32 := 16#a60ce467#;
   pragma Export (C, u00039, "system__traceback_entriesS");
   u00040 : constant Version_32 := 16#1df29216#;
   pragma Export (C, u00040, "system__traceback__symbolicB");
   u00041 : constant Version_32 := 16#46491211#;
   pragma Export (C, u00041, "system__traceback__symbolicS");
   u00042 : constant Version_32 := 16#179d7d28#;
   pragma Export (C, u00042, "ada__containersS");
   u00043 : constant Version_32 := 16#701f9d88#;
   pragma Export (C, u00043, "ada__exceptions__tracebackB");
   u00044 : constant Version_32 := 16#ae2d2db5#;
   pragma Export (C, u00044, "ada__exceptions__tracebackS");
   u00045 : constant Version_32 := 16#e865e681#;
   pragma Export (C, u00045, "system__bounded_stringsB");
   u00046 : constant Version_32 := 16#d1aa330e#;
   pragma Export (C, u00046, "system__bounded_stringsS");
   u00047 : constant Version_32 := 16#e0009d4d#;
   pragma Export (C, u00047, "system__crtlS");
   u00048 : constant Version_32 := 16#5bc565d8#;
   pragma Export (C, u00048, "system__dwarf_linesB");
   u00049 : constant Version_32 := 16#7a1a2f92#;
   pragma Export (C, u00049, "system__dwarf_linesS");
   u00050 : constant Version_32 := 16#5b4659fa#;
   pragma Export (C, u00050, "ada__charactersS");
   u00051 : constant Version_32 := 16#8f637df8#;
   pragma Export (C, u00051, "ada__characters__handlingB");
   u00052 : constant Version_32 := 16#3b3f6154#;
   pragma Export (C, u00052, "ada__characters__handlingS");
   u00053 : constant Version_32 := 16#4b7bb96a#;
   pragma Export (C, u00053, "ada__characters__latin_1S");
   u00054 : constant Version_32 := 16#e6d4fa36#;
   pragma Export (C, u00054, "ada__stringsS");
   u00055 : constant Version_32 := 16#96df1a3f#;
   pragma Export (C, u00055, "ada__strings__mapsB");
   u00056 : constant Version_32 := 16#1e526bec#;
   pragma Export (C, u00056, "ada__strings__mapsS");
   u00057 : constant Version_32 := 16#b8e43522#;
   pragma Export (C, u00057, "system__bit_opsB");
   u00058 : constant Version_32 := 16#0765e3a3#;
   pragma Export (C, u00058, "system__bit_opsS");
   u00059 : constant Version_32 := 16#92d16e94#;
   pragma Export (C, u00059, "system__unsigned_typesS");
   u00060 : constant Version_32 := 16#92f05f13#;
   pragma Export (C, u00060, "ada__strings__maps__constantsS");
   u00061 : constant Version_32 := 16#5ab55268#;
   pragma Export (C, u00061, "interfacesS");
   u00062 : constant Version_32 := 16#a0d3d22b#;
   pragma Export (C, u00062, "system__address_imageB");
   u00063 : constant Version_32 := 16#07bb8f2d#;
   pragma Export (C, u00063, "system__address_imageS");
   u00064 : constant Version_32 := 16#ec78c2bf#;
   pragma Export (C, u00064, "system__img_unsB");
   u00065 : constant Version_32 := 16#0d255263#;
   pragma Export (C, u00065, "system__img_unsS");
   u00066 : constant Version_32 := 16#d7aac20c#;
   pragma Export (C, u00066, "system__ioB");
   u00067 : constant Version_32 := 16#3815e558#;
   pragma Export (C, u00067, "system__ioS");
   u00068 : constant Version_32 := 16#f790d1ef#;
   pragma Export (C, u00068, "system__mmapB");
   u00069 : constant Version_32 := 16#9c26ad70#;
   pragma Export (C, u00069, "system__mmapS");
   u00070 : constant Version_32 := 16#92d882c5#;
   pragma Export (C, u00070, "ada__io_exceptionsS");
   u00071 : constant Version_32 := 16#7188343d#;
   pragma Export (C, u00071, "system__mmap__os_interfaceB");
   u00072 : constant Version_32 := 16#1fc2f713#;
   pragma Export (C, u00072, "system__mmap__os_interfaceS");
   u00073 : constant Version_32 := 16#1e7d913a#;
   pragma Export (C, u00073, "system__mmap__unixS");
   u00074 : constant Version_32 := 16#769e25e6#;
   pragma Export (C, u00074, "interfaces__cB");
   u00075 : constant Version_32 := 16#467817d8#;
   pragma Export (C, u00075, "interfaces__cS");
   u00076 : constant Version_32 := 16#b420f573#;
   pragma Export (C, u00076, "system__os_libB");
   u00077 : constant Version_32 := 16#d872da39#;
   pragma Export (C, u00077, "system__os_libS");
   u00078 : constant Version_32 := 16#ec4d5631#;
   pragma Export (C, u00078, "system__case_utilB");
   u00079 : constant Version_32 := 16#9982a443#;
   pragma Export (C, u00079, "system__case_utilS");
   u00080 : constant Version_32 := 16#2a8e89ad#;
   pragma Export (C, u00080, "system__stringsB");
   u00081 : constant Version_32 := 16#c6413e82#;
   pragma Export (C, u00081, "system__stringsS");
   u00082 : constant Version_32 := 16#5a3f5337#;
   pragma Export (C, u00082, "system__object_readerB");
   u00083 : constant Version_32 := 16#6223cf16#;
   pragma Export (C, u00083, "system__object_readerS");
   u00084 : constant Version_32 := 16#fb020d94#;
   pragma Export (C, u00084, "system__val_lliB");
   u00085 : constant Version_32 := 16#ca3980e7#;
   pragma Export (C, u00085, "system__val_lliS");
   u00086 : constant Version_32 := 16#b8e72903#;
   pragma Export (C, u00086, "system__val_lluB");
   u00087 : constant Version_32 := 16#ff1fe376#;
   pragma Export (C, u00087, "system__val_lluS");
   u00088 : constant Version_32 := 16#269742a9#;
   pragma Export (C, u00088, "system__val_utilB");
   u00089 : constant Version_32 := 16#0af7a4e9#;
   pragma Export (C, u00089, "system__val_utilS");
   u00090 : constant Version_32 := 16#d7bf3f29#;
   pragma Export (C, u00090, "system__exception_tracesB");
   u00091 : constant Version_32 := 16#8288328d#;
   pragma Export (C, u00091, "system__exception_tracesS");
   u00092 : constant Version_32 := 16#8c33a517#;
   pragma Export (C, u00092, "system__wch_conB");
   u00093 : constant Version_32 := 16#bd2a30c5#;
   pragma Export (C, u00093, "system__wch_conS");
   u00094 : constant Version_32 := 16#9721e840#;
   pragma Export (C, u00094, "system__wch_stwB");
   u00095 : constant Version_32 := 16#903b1cc4#;
   pragma Export (C, u00095, "system__wch_stwS");
   u00096 : constant Version_32 := 16#a831679c#;
   pragma Export (C, u00096, "system__wch_cnvB");
   u00097 : constant Version_32 := 16#b29d8a36#;
   pragma Export (C, u00097, "system__wch_cnvS");
   u00098 : constant Version_32 := 16#ece6fdb6#;
   pragma Export (C, u00098, "system__wch_jisB");
   u00099 : constant Version_32 := 16#32ed9317#;
   pragma Export (C, u00099, "system__wch_jisS");
   u00100 : constant Version_32 := 16#51f2d040#;
   pragma Export (C, u00100, "system__os_primitivesB");
   u00101 : constant Version_32 := 16#a1aa77e1#;
   pragma Export (C, u00101, "system__os_primitivesS");
   u00102 : constant Version_32 := 16#e932e590#;
   pragma Export (C, u00102, "ada__real_timeB");
   u00103 : constant Version_32 := 16#69ea8064#;
   pragma Export (C, u00103, "ada__real_timeS");
   u00104 : constant Version_32 := 16#c2216981#;
   pragma Export (C, u00104, "system__taskingB");
   u00105 : constant Version_32 := 16#141170cc#;
   pragma Export (C, u00105, "system__taskingS");
   u00106 : constant Version_32 := 16#d51a3e48#;
   pragma Export (C, u00106, "system__task_primitivesS");
   u00107 : constant Version_32 := 16#bfbf116d#;
   pragma Export (C, u00107, "system__os_interfaceB");
   u00108 : constant Version_32 := 16#7baac831#;
   pragma Export (C, u00108, "system__os_interfaceS");
   u00109 : constant Version_32 := 16#7017a763#;
   pragma Export (C, u00109, "system__task_primitives__operationsB");
   u00110 : constant Version_32 := 16#9fa58b20#;
   pragma Export (C, u00110, "system__task_primitives__operationsS");
   u00111 : constant Version_32 := 16#71c5de81#;
   pragma Export (C, u00111, "system__interrupt_managementB");
   u00112 : constant Version_32 := 16#328bf158#;
   pragma Export (C, u00112, "system__interrupt_managementS");
   u00113 : constant Version_32 := 16#f65595cf#;
   pragma Export (C, u00113, "system__multiprocessorsB");
   u00114 : constant Version_32 := 16#9efb8d64#;
   pragma Export (C, u00114, "system__multiprocessorsS");
   u00115 : constant Version_32 := 16#7d4d4c1d#;
   pragma Export (C, u00115, "system__os_constantsS");
   u00116 : constant Version_32 := 16#e0fce7f8#;
   pragma Export (C, u00116, "system__task_infoB");
   u00117 : constant Version_32 := 16#264daf16#;
   pragma Export (C, u00117, "system__task_infoS");
   u00118 : constant Version_32 := 16#f0965c7b#;
   pragma Export (C, u00118, "system__tasking__debugB");
   u00119 : constant Version_32 := 16#58ee8924#;
   pragma Export (C, u00119, "system__tasking__debugS");
   u00120 : constant Version_32 := 16#fd83e873#;
   pragma Export (C, u00120, "system__concat_2B");
   u00121 : constant Version_32 := 16#a4f7c5c7#;
   pragma Export (C, u00121, "system__concat_2S");
   u00122 : constant Version_32 := 16#2b70b149#;
   pragma Export (C, u00122, "system__concat_3B");
   u00123 : constant Version_32 := 16#ad274eb2#;
   pragma Export (C, u00123, "system__concat_3S");
   u00124 : constant Version_32 := 16#b31a5821#;
   pragma Export (C, u00124, "system__img_enum_newB");
   u00125 : constant Version_32 := 16#c71b14d7#;
   pragma Export (C, u00125, "system__img_enum_newS");
   u00126 : constant Version_32 := 16#9dca6636#;
   pragma Export (C, u00126, "system__img_lliB");
   u00127 : constant Version_32 := 16#b71847c6#;
   pragma Export (C, u00127, "system__img_lliS");
   u00128 : constant Version_32 := 16#6ec3c867#;
   pragma Export (C, u00128, "system__stack_usageB");
   u00129 : constant Version_32 := 16#3a3ac346#;
   pragma Export (C, u00129, "system__stack_usageS");
   u00130 : constant Version_32 := 16#5d91da9f#;
   pragma Export (C, u00130, "ada__tagsB");
   u00131 : constant Version_32 := 16#12a0afb8#;
   pragma Export (C, u00131, "ada__tagsS");
   u00132 : constant Version_32 := 16#796f31f1#;
   pragma Export (C, u00132, "system__htableB");
   u00133 : constant Version_32 := 16#2295a1fd#;
   pragma Export (C, u00133, "system__htableS");
   u00134 : constant Version_32 := 16#089f5cd0#;
   pragma Export (C, u00134, "system__string_hashB");
   u00135 : constant Version_32 := 16#80cbca83#;
   pragma Export (C, u00135, "system__string_hashS");
   u00136 : constant Version_32 := 16#74d3cdd6#;
   pragma Export (C, u00136, "impdefB");
   u00137 : constant Version_32 := 16#ba6af773#;
   pragma Export (C, u00137, "impdefS");
   u00138 : constant Version_32 := 16#f4e097a7#;
   pragma Export (C, u00138, "ada__text_ioB");
   u00139 : constant Version_32 := 16#971fad3a#;
   pragma Export (C, u00139, "ada__text_ioS");
   u00140 : constant Version_32 := 16#10558b11#;
   pragma Export (C, u00140, "ada__streamsB");
   u00141 : constant Version_32 := 16#67e31212#;
   pragma Export (C, u00141, "ada__streamsS");
   u00142 : constant Version_32 := 16#73d2d764#;
   pragma Export (C, u00142, "interfaces__c_streamsB");
   u00143 : constant Version_32 := 16#b1330297#;
   pragma Export (C, u00143, "interfaces__c_streamsS");
   u00144 : constant Version_32 := 16#ec9c64c3#;
   pragma Export (C, u00144, "system__file_ioB");
   u00145 : constant Version_32 := 16#0126f372#;
   pragma Export (C, u00145, "system__file_ioS");
   u00146 : constant Version_32 := 16#86c56e5a#;
   pragma Export (C, u00146, "ada__finalizationS");
   u00147 : constant Version_32 := 16#95817ed8#;
   pragma Export (C, u00147, "system__finalization_rootB");
   u00148 : constant Version_32 := 16#e9a56187#;
   pragma Export (C, u00148, "system__finalization_rootS");
   u00149 : constant Version_32 := 16#5bc888bf#;
   pragma Export (C, u00149, "system__file_control_blockS");
   u00150 : constant Version_32 := 16#91d53f4f#;
   pragma Export (C, u00150, "ada__text_io__modular_auxB");
   u00151 : constant Version_32 := 16#9bb2cffe#;
   pragma Export (C, u00151, "ada__text_io__modular_auxS");
   u00152 : constant Version_32 := 16#181dc502#;
   pragma Export (C, u00152, "ada__text_io__generic_auxB");
   u00153 : constant Version_32 := 16#305a076a#;
   pragma Export (C, u00153, "ada__text_io__generic_auxS");
   u00154 : constant Version_32 := 16#b10ba0c7#;
   pragma Export (C, u00154, "system__img_biuB");
   u00155 : constant Version_32 := 16#54f3e6d9#;
   pragma Export (C, u00155, "system__img_biuS");
   u00156 : constant Version_32 := 16#4e06ab0c#;
   pragma Export (C, u00156, "system__img_llbB");
   u00157 : constant Version_32 := 16#1534f627#;
   pragma Export (C, u00157, "system__img_llbS");
   u00158 : constant Version_32 := 16#3e932977#;
   pragma Export (C, u00158, "system__img_lluB");
   u00159 : constant Version_32 := 16#db186e57#;
   pragma Export (C, u00159, "system__img_lluS");
   u00160 : constant Version_32 := 16#a756d097#;
   pragma Export (C, u00160, "system__img_llwB");
   u00161 : constant Version_32 := 16#bc58d5b1#;
   pragma Export (C, u00161, "system__img_llwS");
   u00162 : constant Version_32 := 16#eb55dfbb#;
   pragma Export (C, u00162, "system__img_wiuB");
   u00163 : constant Version_32 := 16#3ab2614b#;
   pragma Export (C, u00163, "system__img_wiuS");
   u00164 : constant Version_32 := 16#383fd226#;
   pragma Export (C, u00164, "system__val_unsB");
   u00165 : constant Version_32 := 16#a7d7132d#;
   pragma Export (C, u00165, "system__val_unsS");
   u00166 : constant Version_32 := 16#92f3335b#;
   pragma Export (C, u00166, "reportB");
   u00167 : constant Version_32 := 16#df19fbea#;
   pragma Export (C, u00167, "reportS");
   u00168 : constant Version_32 := 16#0780a76b#;
   pragma Export (C, u00168, "system__tasking__stagesB");
   u00169 : constant Version_32 := 16#bfc55b2f#;
   pragma Export (C, u00169, "system__tasking__stagesS");
   u00170 : constant Version_32 := 16#100eaf58#;
   pragma Export (C, u00170, "system__restrictionsB");
   u00171 : constant Version_32 := 16#ed25cb46#;
   pragma Export (C, u00171, "system__restrictionsS");
   u00172 : constant Version_32 := 16#4e315ff7#;
   pragma Export (C, u00172, "system__tasking__initializationB");
   u00173 : constant Version_32 := 16#fc2303e6#;
   pragma Export (C, u00173, "system__tasking__initializationS");
   u00174 : constant Version_32 := 16#55e88911#;
   pragma Export (C, u00174, "system__soft_links__taskingB");
   u00175 : constant Version_32 := 16#e939497e#;
   pragma Export (C, u00175, "system__soft_links__taskingS");
   u00176 : constant Version_32 := 16#3880736e#;
   pragma Export (C, u00176, "ada__exceptions__is_null_occurrenceB");
   u00177 : constant Version_32 := 16#6fde25af#;
   pragma Export (C, u00177, "ada__exceptions__is_null_occurrenceS");
   u00178 : constant Version_32 := 16#263e126a#;
   pragma Export (C, u00178, "system__tasking__task_attributesB");
   u00179 : constant Version_32 := 16#4c97674c#;
   pragma Export (C, u00179, "system__tasking__task_attributesS");
   u00180 : constant Version_32 := 16#cee82bbd#;
   pragma Export (C, u00180, "system__tasking__queuingB");
   u00181 : constant Version_32 := 16#6dba2805#;
   pragma Export (C, u00181, "system__tasking__queuingS");
   u00182 : constant Version_32 := 16#7f6ff536#;
   pragma Export (C, u00182, "system__tasking__protected_objectsB");
   u00183 : constant Version_32 := 16#15001baf#;
   pragma Export (C, u00183, "system__tasking__protected_objectsS");
   u00184 : constant Version_32 := 16#726dd94b#;
   pragma Export (C, u00184, "system__tasking__protected_objects__entriesB");
   u00185 : constant Version_32 := 16#7daf93e7#;
   pragma Export (C, u00185, "system__tasking__protected_objects__entriesS");
   u00186 : constant Version_32 := 16#9322406a#;
   pragma Export (C, u00186, "system__tasking__rendezvousB");
   u00187 : constant Version_32 := 16#d811d710#;
   pragma Export (C, u00187, "system__tasking__rendezvousS");
   u00188 : constant Version_32 := 16#69bd1289#;
   pragma Export (C, u00188, "system__tasking__entry_callsB");
   u00189 : constant Version_32 := 16#6342024e#;
   pragma Export (C, u00189, "system__tasking__entry_callsS");
   u00190 : constant Version_32 := 16#83c8fb63#;
   pragma Export (C, u00190, "system__tasking__protected_objects__operationsB");
   u00191 : constant Version_32 := 16#343fde45#;
   pragma Export (C, u00191, "system__tasking__protected_objects__operationsS");
   u00192 : constant Version_32 := 16#eb894f1f#;
   pragma Export (C, u00192, "system__tasking__utilitiesB");
   u00193 : constant Version_32 := 16#0f670827#;
   pragma Export (C, u00193, "system__tasking__utilitiesS");
   u00194 : constant Version_32 := 16#e31b7c4e#;
   pragma Export (C, u00194, "system__memoryB");
   u00195 : constant Version_32 := 16#ff2a7423#;
   pragma Export (C, u00195, "system__memoryS");

   --  BEGIN ELABORATION ORDER
   --  ada%s
   --  ada.characters%s
   --  ada.characters.latin_1%s
   --  interfaces%s
   --  system%s
   --  system.img_enum_new%s
   --  system.img_enum_new%b
   --  system.img_int%s
   --  system.img_int%b
   --  system.img_lli%s
   --  system.img_lli%b
   --  system.io%s
   --  system.io%b
   --  system.os_primitives%s
   --  system.os_primitives%b
   --  system.parameters%s
   --  system.parameters%b
   --  system.crtl%s
   --  interfaces.c_streams%s
   --  interfaces.c_streams%b
   --  system.restrictions%s
   --  system.restrictions%b
   --  system.storage_elements%s
   --  system.storage_elements%b
   --  system.stack_checking%s
   --  system.stack_checking%b
   --  system.stack_usage%s
   --  system.stack_usage%b
   --  system.string_hash%s
   --  system.string_hash%b
   --  system.htable%s
   --  system.htable%b
   --  system.strings%s
   --  system.strings%b
   --  system.task_info%s
   --  system.task_info%b
   --  system.traceback_entries%s
   --  system.traceback_entries%b
   --  system.unsigned_types%s
   --  system.img_biu%s
   --  system.img_biu%b
   --  system.img_llb%s
   --  system.img_llb%b
   --  system.img_llu%s
   --  system.img_llu%b
   --  system.img_llw%s
   --  system.img_llw%b
   --  system.img_uns%s
   --  system.img_uns%b
   --  system.img_wiu%s
   --  system.img_wiu%b
   --  system.wch_con%s
   --  system.wch_con%b
   --  system.wch_jis%s
   --  system.wch_jis%b
   --  system.wch_cnv%s
   --  system.wch_cnv%b
   --  system.concat_2%s
   --  system.concat_2%b
   --  system.concat_3%s
   --  system.concat_3%b
   --  system.traceback%s
   --  system.traceback%b
   --  ada.characters.handling%s
   --  system.case_util%s
   --  system.os_lib%s
   --  system.secondary_stack%s
   --  system.standard_library%s
   --  ada.exceptions%s
   --  system.exceptions_debug%s
   --  system.exceptions_debug%b
   --  system.soft_links%s
   --  system.val_lli%s
   --  system.val_llu%s
   --  system.val_util%s
   --  system.val_util%b
   --  system.wch_stw%s
   --  system.wch_stw%b
   --  ada.exceptions.last_chance_handler%s
   --  ada.exceptions.last_chance_handler%b
   --  ada.exceptions.traceback%s
   --  ada.exceptions.traceback%b
   --  system.address_image%s
   --  system.address_image%b
   --  system.bit_ops%s
   --  system.bit_ops%b
   --  system.bounded_strings%s
   --  system.bounded_strings%b
   --  system.case_util%b
   --  system.exception_table%s
   --  system.exception_table%b
   --  ada.containers%s
   --  ada.io_exceptions%s
   --  ada.strings%s
   --  ada.strings.maps%s
   --  ada.strings.maps%b
   --  ada.strings.maps.constants%s
   --  interfaces.c%s
   --  interfaces.c%b
   --  system.exceptions%s
   --  system.exceptions%b
   --  system.exceptions.machine%s
   --  system.exceptions.machine%b
   --  ada.characters.handling%b
   --  system.exception_traces%s
   --  system.exception_traces%b
   --  system.memory%s
   --  system.memory%b
   --  system.mmap%s
   --  system.mmap.os_interface%s
   --  system.mmap%b
   --  system.mmap.unix%s
   --  system.mmap.os_interface%b
   --  system.object_reader%s
   --  system.object_reader%b
   --  system.dwarf_lines%s
   --  system.dwarf_lines%b
   --  system.os_lib%b
   --  system.secondary_stack%b
   --  system.soft_links.initialize%s
   --  system.soft_links.initialize%b
   --  system.soft_links%b
   --  system.standard_library%b
   --  system.traceback.symbolic%s
   --  system.traceback.symbolic%b
   --  ada.exceptions%b
   --  system.val_lli%b
   --  system.val_llu%b
   --  ada.exceptions.is_null_occurrence%s
   --  ada.exceptions.is_null_occurrence%b
   --  ada.tags%s
   --  ada.tags%b
   --  ada.streams%s
   --  ada.streams%b
   --  system.file_control_block%s
   --  system.finalization_root%s
   --  system.finalization_root%b
   --  ada.finalization%s
   --  system.file_io%s
   --  system.file_io%b
   --  system.multiprocessors%s
   --  system.multiprocessors%b
   --  system.os_constants%s
   --  system.os_interface%s
   --  system.os_interface%b
   --  system.task_primitives%s
   --  system.interrupt_management%s
   --  system.interrupt_management%b
   --  system.tasking%s
   --  system.task_primitives.operations%s
   --  system.tasking.debug%s
   --  system.tasking.debug%b
   --  system.task_primitives.operations%b
   --  system.tasking%b
   --  system.val_uns%s
   --  system.val_uns%b
   --  ada.calendar%s
   --  ada.calendar%b
   --  ada.calendar.delays%s
   --  ada.calendar.delays%b
   --  ada.real_time%s
   --  ada.real_time%b
   --  ada.text_io%s
   --  ada.text_io%b
   --  ada.text_io.generic_aux%s
   --  ada.text_io.generic_aux%b
   --  ada.text_io.modular_aux%s
   --  ada.text_io.modular_aux%b
   --  system.soft_links.tasking%s
   --  system.soft_links.tasking%b
   --  system.tasking.initialization%s
   --  system.tasking.task_attributes%s
   --  system.tasking.task_attributes%b
   --  system.tasking.initialization%b
   --  system.tasking.protected_objects%s
   --  system.tasking.protected_objects%b
   --  system.tasking.protected_objects.entries%s
   --  system.tasking.protected_objects.entries%b
   --  system.tasking.queuing%s
   --  system.tasking.queuing%b
   --  system.tasking.utilities%s
   --  system.tasking.utilities%b
   --  system.tasking.entry_calls%s
   --  system.tasking.rendezvous%s
   --  system.tasking.protected_objects.operations%s
   --  system.tasking.protected_objects.operations%b
   --  system.tasking.entry_calls%b
   --  system.tasking.rendezvous%b
   --  system.tasking.stages%s
   --  system.tasking.stages%b
   --  report%s
   --  report%b
   --  impdef%s
   --  impdef%b
   --  c94010a%b
   --  END ELABORATION ORDER

end ada_main;
