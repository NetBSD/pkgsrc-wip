

with Report;
with C651001_0; use C651001_0;
procedure C651001 is

   procedure Check_Raise (Test : in Natural) is
      Code : Error_Code;
   begin
      begin
         Do_Something (Oper => Report.Ident_Int (Test), Result => Code);
         if Code /= SUCCESS then
            Raise_Error (Code);
            Report.Failed ("Nonreturning procedure returned normally");
         else
            Report.Comment ("Success?");
         end if;
      exception
         when Invalid_Error =>
            if Code /= 2 then
               Report.Failed ("Wrong exception (Inv) raised for" &
                                      Error_Code'Image(Code));
            -- else expected.
            end if;
         when OS_Error =>
            if Code <= 2 then
               Report.Failed ("Wrong exception (OS) raised for" &
                                      Error_Code'Image(Code));
            -- else expected.
            end if;
         when Not_Found_Error =>
            if Code /= 1 then
               Report.Failed ("Wrong exception (NF) raised for" &
                                      Error_Code'Image(Code));
            -- else expected.
            end if;
      end;
   end Check_Raise;


   function A_Mess (Code : Error_Code) return String is
   begin
      return " code" & Integer'Image(-Code);
   end A_Mess;

   procedure Inst_Raise_Error is new Generic_Raise_Error (A_Mess);

   procedure Check_Inst_Raise (Test : in Natural) is
      Code : Error_Code;
   begin
      begin
         Do_Something (Oper => Report.Ident_Int (Test), Result => Code);
         if Code /= SUCCESS then
            Inst_Raise_Error (Code);
            Report.Failed ("Generic nonreturning procedure returned " &
                           "normally");
         else
            Report.Comment ("Success?");
         end if;
      exception
         when Invalid_Error =>
            if Code /= 2 then
               Report.Failed ("Wrong exception (Gen Inv) raised for" &
                                      Error_Code'Image(Code));
            -- else expected.
            end if;
         when OS_Error =>
            if Code <= 2 then
               Report.Failed ("Wrong exception (Gen OS) raised for" &
                                      Error_Code'Image(Code));
            -- else expected.
            end if;
         when Not_Found_Error =>
            if Code /= 1 then
               Report.Failed ("Wrong exception (Gen NF) raised for" &
                                      Error_Code'Image(Code));
            -- else expected.
            end if;
      end;
   end Check_Inst_Raise;

begin

   Report.Test
     ("C651001",
      "Check that a nonreturning procedure can propagate an exception to " &
      """return"" to the caller. Check that a nonreturning procedure raises " &
      "Program_Error if it attempts to return normally. Case 1: pragma " &
      "No_Return");

   Check_Raise (Test => 2);

   Check_Raise (Test => 5);

   Check_Raise (Test => 1);

   begin -- Try mistakenly calling Raise_Error with SUCCESS (this will
         -- attempt to return normally.
       Raise_Error (SUCCESS);
       Report.Failed ("Nonreturning procedure returned normally - Success");
   exception
      when Program_Error =>
         null;
   end;

   Check_Inst_Raise (Test => 1);

   Check_Inst_Raise (Test => 2);

   Check_Inst_Raise (Test => 7);

   Check_Inst_Raise (Test => 1);

   begin -- Try mistakenly calling Raise_Error with SUCCESS (this will
         -- attempt to return normally.
       Inst_Raise_Error (SUCCESS);
       Report.Failed ("Generic nonreturning procedure returned normally - " &
                      "Success");
   exception
      when Program_Error =>
         null;
   end;

   Report.Result;

end C651001;
