
with Ada.Strings.Fixed;
package body Test_Summary is

   DEBUG : constant Boolean := True;

   procedure Write_Summary_Record (Summary_File : in Ada.Text_IO.File_Type;
                                   Rec : in Test_Summary.Info_Record) is
      use Test_Summary;
   begin
      case Rec.Kind is
         when Test_Summary.Unknown =>
            Ada.Text_IO.Put (Summary_File, "UNKN,");
            if DEBUG then
                Ada.Text_IO.Put ("Writing Unknown at line");
            end if;
         when Test_Summary.Error =>
            Ada.Text_IO.Put (Summary_File, "ERROR,");
            if DEBUG then
                Ada.Text_IO.Put ("Writing Error at line");
            end if;
         when Test_Summary.Optional_Error =>
            Ada.Text_IO.Put (Summary_File, "OERROR,");
            if DEBUG then
                Ada.Text_IO.Put ("Writing Optional Error at line");
            end if;
         when Test_Summary.Possible_Error =>
            Ada.Text_IO.Put (Summary_File, "PERROR,");
            if DEBUG then
                Ada.Text_IO.Put ("Writing Possible Error at line");
            end if;
         when Test_Summary.NA_Error =>
            Ada.Text_IO.Put (Summary_File, "NAERR,");
            if DEBUG then
                Ada.Text_IO.Put ("Writing Not Applicable Error at line");
            end if;
         when Test_Summary.OK =>
            Ada.Text_IO.Put (Summary_File, "OK,");
            if DEBUG then
                Ada.Text_IO.Put ("Writing OK Error at line");
            end if;
         when Test_Summary.Annex_C_Requirement =>
            Ada.Text_IO.Put (Summary_File, "ACRQMT,");
            if DEBUG then
                Ada.Text_IO.Put ("Writing Annex C Rqmnt at line");
            end if;
         when Test_Summary.Compilation_Unit =>
            case Rec.Unit_Kind is
               when Test_Summary.Package_Specification =>
                  Ada.Text_IO.Put (Summary_File, "UPACKSPEC,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing pack spec starting at line");
                  end if;
               when Test_Summary.Function_Specification =>
                  Ada.Text_IO.Put (Summary_File, "UFUNCSPEC,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing func spec starting at line");
                  end if;
               when Test_Summary.Procedure_Specification =>
                  Ada.Text_IO.Put (Summary_File, "UPROCSPEC,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing proc spec starting at line");
                  end if;
               when Test_Summary.Generic_Package =>
                  Ada.Text_IO.Put (Summary_File, "UGENPACK,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing generic pack starting at line");
                  end if;
               when Test_Summary.Generic_Function =>
                  Ada.Text_IO.Put (Summary_File, "UGENFUNC,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing generic func starting at line");
                  end if;
               when Test_Summary.Generic_Procedure =>
                  Ada.Text_IO.Put (Summary_File, "UGENPROC,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing generic proc starting at line");
                  end if;
               when Test_Summary.Package_Body =>
                  Ada.Text_IO.Put (Summary_File, "UPACKBODY,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing pack body starting at line");
                  end if;
               when Test_Summary.Function_Body =>
                  Ada.Text_IO.Put (Summary_File, "UFUNCBODY,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing func body starting at line");
                  end if;
               when Test_Summary.Procedure_Body =>
                  Ada.Text_IO.Put (Summary_File, "UPROCBODY,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing proc body starting at line");
                  end if;
               when Test_Summary.Package_Instantiation =>
                  Ada.Text_IO.Put (Summary_File, "UPACKINST,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing pack inst starting at line");
                  end if;
               when Test_Summary.Function_Instantiation =>
                  Ada.Text_IO.Put (Summary_File, "UFUNCINST,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing func inst starting at line");
                  end if;
               when Test_Summary.Procedure_Instantiation =>
                  Ada.Text_IO.Put (Summary_File, "UPROCINST,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing proc inst starting at line");
                  end if;
               when Test_Summary.Package_Renaming =>
                  Ada.Text_IO.Put (Summary_File, "UPACKREN,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing pack rename starting at line");
                  end if;
               when Test_Summary.Function_Renaming =>
                  Ada.Text_IO.Put (Summary_File, "UFUNCREN,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing func rename starting at line");
                  end if;
               when Test_Summary.Procedure_Renaming =>
                  Ada.Text_IO.Put (Summary_File, "UPROCREN,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing proc rename starting at line");
                  end if;
               when Test_Summary.Generic_Package_Renaming =>
                  Ada.Text_IO.Put (Summary_File, "UGPACKREN,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing gen pack ren starting at line");
                  end if;
               when Test_Summary.Generic_Function_Renaming =>
                  Ada.Text_IO.Put (Summary_File, "UGFUNCREN,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing gen func ren starting at line");
                  end if;
               when Test_Summary.Generic_Procedure_Renaming =>
                  Ada.Text_IO.Put (Summary_File, "UGPROCREN,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing gen proc ren starting at line");
                  end if;
               when Test_Summary.Package_Subunit =>
                  Ada.Text_IO.Put (Summary_File, "PACKSUB,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing pack subunit starting at line");
                  end if;
               when Test_Summary.Procedure_Subunit =>
                  Ada.Text_IO.Put (Summary_File, "PROCSUB,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing proc subunit starting at line");
                  end if;
               when Test_Summary.Function_Subunit =>
                  Ada.Text_IO.Put (Summary_File, "FUNCSUB,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing func subunit starting at line");
                  end if;
               when Test_Summary.Task_Subunit =>
                  Ada.Text_IO.Put (Summary_File, "TASKSUB,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing task subunit starting at line");
                  end if;
               when Test_Summary.Protected_Subunit =>
                  Ada.Text_IO.Put (Summary_File, "PROTSUB,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing prot subunit starting at line");
                  end if;
               when Test_Summary.Configuration_Pragma =>
                  Ada.Text_IO.Put (Summary_File, "PRAGMA,");
                  if DEBUG then
                     Ada.Text_IO.Put ("Writing pragma starting at line");
                  end if;
            end case;
      end case;

      Ada.Text_IO.Put (Summary_File,
                       Ada.Strings.Fixed.Trim (Rec.Source_Name,
                          Ada.Strings.Both) & ',');

      Ada.Text_IO.Put (Summary_File,
                       Ada.Strings.Fixed.Trim (
                          Trace.Line_Number_Type'Image(Rec.Start_Line),
                          Ada.Strings.Both) & ',');
      if DEBUG then
         Ada.Text_IO.Put (Trace.Line_Number_Type'Image(Rec.Start_Line));
      end if;

      Ada.Text_IO.Put (Summary_File,
                       Ada.Strings.Fixed.Trim (
                          Trace.Line_Position_Type'Image(Rec.Start_Position),
                          Ada.Strings.Both) & ',');

      Ada.Text_IO.Put (Summary_File,
                       Ada.Strings.Fixed.Trim (
                          Trace.Line_Number_Type'Image(Rec.End_Line),
                          Ada.Strings.Both) & ',');

      Ada.Text_IO.Put (Summary_File,
                       Ada.Strings.Fixed.Trim (
                          Trace.Line_Position_Type'Image(Rec.End_Position),
                          Ada.Strings.Both) & ',');

      case Rec.Kind is
         when Possible_Error =>
            Ada.Text_IO.Put (Summary_File,
                             Ada.Strings.Fixed.Trim (Rec.Set_Label,
                                Ada.Strings.Both) & ',');
            if DEBUG then
               Ada.Text_IO.Put ("; with label=" & Ada.Strings.Fixed.Trim (
                                Rec.Set_Label, Ada.Strings.Both));
            end if;
         when Compilation_Unit =>
            Ada.Text_IO.Put (Summary_File,
                             Ada.Strings.Fixed.Trim (Rec.Unit_Name,
                                Ada.Strings.Both) & ',');
            if DEBUG then
               Ada.Text_IO.Put ("; with name=" & Ada.Strings.Fixed.Trim (
                                Rec.Unit_Name, Ada.Strings.Both));
            end if;
            if Rec.Is_Main then
               if Rec.Optional then
                  Ada.Text_IO.Put (Summary_File, "OPTMAIN");
               else
                  Ada.Text_IO.Put (Summary_File, "MAIN");
               end if;
            else
               if Rec.Optional then
                  Ada.Text_IO.Put (Summary_File, "OPT");
               else
                  null; -- No flags.
               end if;
            end if;

         when Error | Optional_Error | NA_Error | Annex_C_Requirement |
              OK | Unknown =>
            Ada.Text_IO.Put (Summary_File,",");
      end case;

      Ada.Text_IO.New_Line (Summary_File);
      if DEBUG then
         Ada.Text_IO.New_Line;
      end if;
   end Write_Summary_Record;

end Test_Summary;
