

     --==================================================================--


package body BC51022_2 is

   package body Uses_Of_Untagged_Incomplete_Formal_Type is

      procedure Proc (I : in out Untagged_Incomplete) is          -- ERROR: (G)
      begin
         Sink_1 (I);                                              -- ERROR: (H)
      end Proc;

      function Func return Untagged_Incomplete is                 -- ERROR: (E)
      begin
         return Constructor_1;                                    -- ERROR: (F)
      end Func;

   end Uses_Of_Untagged_Incomplete_Formal_Type;

   package body Uses_Of_Tagged_Incomplete_Formal_Type is

      procedure Proc (I : in out Tagged_Incomplete) is            -- OK.
      begin
         Sink_2 (I);                                              -- OK.
      end Proc;

      function Func return Tagged_Incomplete is                   -- ERROR: (E)
      begin
         return Constructor_2;                                    -- ERROR: (F)
      end Func;

      procedure Proc_CW (I : in out Tagged_Incomplete'Class) is   -- OK.
      begin
         Sink_3 (I);                                               -- OK.
      end Proc_CW;

      function Func_CW return Tagged_Incomplete'Class is          -- ERROR: (E)
      begin
         return Constructor_2;                                    -- ERROR: (F)
      end Func_CW;

   end Uses_Of_Tagged_Incomplete_Formal_Type;

end BC51022_2;




