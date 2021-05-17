

     --===================================================================--


with C640001_0;
with C640001_1;
with C640001_2;

with Report;
procedure C640001 is

   package Table_Support is new C640001_2 (C640001_0.Table);

   Sub_Ptr   : Table_Support.Proc_Ptr;
   My_List   : Table_Support.Op_List;
   My_Table1 : C640001_0.Table;             -- Initial values of both Row1 &
                                            -- Row2 are (T,F,T,F,T,F,T,F,T,F).
   My_Table2 : C640001_0.Table2;            -- Initial values of both Row1 &
                                            -- Row2 are (T,F,T,F,T,F,T,F,T,F).
begin
   Report.Test ("C640001", "Check that, for an access-to-subprogram type " &
                           "whose designated profile contains parameters " &
                           "of a tagged generic formal type, an access-" &
                           "to-subprogram value may designate dispatching " &
                           "and non-dispatching operations");

   --
   -- Add subprogram access values to list:
   --

   Sub_Ptr := C640001_0.Clear'Access;       -- Designates dispatching op.
   Table_Support.Add_Op (Sub_Ptr, My_List); -- (1st operation on My_List).

   Sub_Ptr := C640001_1.Clear'Access;       -- Designates non-dispatching op.
   Table_Support.Add_Op (Sub_Ptr, My_List); -- (2nd operation on My_List).

   Sub_Ptr := C640001_0.Reset'Access;       -- Designates re-dispatching op.
   Table_Support.Add_Op (Sub_Ptr, My_List); -- (3rd operation on My_List).


   --
   -- Call dispatching operation:
   --

   Table_Support.Process_Operand (My_Table1, My_List, 1, 1);   -- Call 1st op.
   
   if not C640001_0.Is_False (My_Table1.Row1) then
      Report.Failed ("Wrong result after calling dispatching operation");
   end if;


   --
   -- Call non-dispatching operation:
   --

   Table_Support.Process_Operand (My_Table1, My_List, 2, 2);   -- Call 2nd op.
   
   if not C640001_0.Is_True (My_Table1.Row2) then
      Report.Failed ("Wrong result after calling non-dispatching operation");
   end if;


   --
   -- Call re-dispatching operation:
   --

   Table_Support.Process_Operand (C640001_0.Table(My_Table2),  -- View conv.
                                  My_List, 3, 3);              -- Call 3rd op.
   
   if not C640001_0.Is_True (My_Table2.Row1) then
      Report.Failed ("Wrong result after calling re-dispatching operation");
   end if;


   Report.Result;
end C640001;
