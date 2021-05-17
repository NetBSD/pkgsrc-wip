

with Report;
with C470001_0; use C470001_0;
procedure C470001 is

begin

   Report.Test
     ("C470001",
      "Check that a qualified expression is a name, and thus can be used " &
      "where a name is required");

   Set_Paragraph (1, Text => "The quick brown fox jumped over the " &
                             "lazy Ada implementor.");

   Set_Paragraph (2, Text => "May you have a punny day!",
                     Indent => 4);

   Set_Paragraph (3, Text => "This is a test. This is only a test. Had" &
                             " this been a real application, you would have" &
                             " needed instructions on how to use it.");

   -- Indexing of qualified expression:
   if String'(Paragraph (1).all)(1) /= 'T' then
      Report.Failed ("Incorrect character (1A)");
   end if;

   -- Indexing of qualified expression with implicit dereference:
   if Paragraph_Text'(Paragraph (2))(25) /= '!' then
      Report.Failed ("Incorrect character (2A)");
   end if;

   -- Slice of qualified expression:
   if String'(Paragraph (3).all)(17..36) /= "This is only a test." then
      Report.Failed ("Incorrect slice (3A)");
   end if;

   -- Slice of qualified expression with implicit dereference:
   if Paragraph_Text'(Paragraph (2))(16..20) /= "punny" then
      Report.Failed ("Incorrect slice (2B)");
   end if;

   -- Explicit dereference of qualified expression:
   if Paragraph_Text'(Paragraph (2)).all /= "May you have a punny day!" then
      Report.Failed ("Incorrect string (2C)");
   end if;

   -- Indexed explicit dereference of qualified expression:
   if Paragraph_Text'(Paragraph (1)).all(19) /= 'x' then
      Report.Failed ("Incorrect character (1B)");
   end if;

   -- Sliced explicit dereference of qualified expression:
   if Paragraph_Text'(Paragraph (1)).all(37..40) /= "lazy" then
      Report.Failed ("Incorrect slice (1C)");
   end if;

   -- Modify sliced explicit dereference of qualified expression:
   Paragraph_Text'(Paragraph (2)).all(16..20) := "sunny";
   if Paragraph_Text'(Paragraph (2)).all(16) /= 's' then
      Report.Failed ("Incorrect character (2D)");
   end if;

   -- Selection of qualified expression:
   if Paragraph_Info'(Paragraph (2)).Indent /= 4 then
      Report.Failed ("Incorrect indent (2E)");
   end if;

   -- Selection of qualified expression (with implicit dereference and slice):
   if Paragraph_Info'(Paragraph (1)).Text(37..40) /= "lazy" then
      Report.Failed ("Incorrect slice (1D)");
   end if;

   -- Qualified expression as prefix of attribute:
   if Natural'(Paragraph (1).Indent)'Image /= " 0" then
      Report.Failed ("Incorrect image (1E)");
   end if;

   -- Qualified expression as prefix of attribute:
   if Natural'(Paragraph_Info'(Paragraph (2)).Length)'Image /= " 25" then
      Report.Failed ("Incorrect image (2F)");
   end if;

   declare
      -- Qualified expression as renamed entity in an object renaming:
      Two_Length : Natural renames Natural'(Paragraph (2).Length);
      Three_Text : Paragraph_Text renames Paragraph_Text'(Paragraph (3));
   begin
      if Two_Length /= 25 then
         Report.Failed ("Incorrect length (2G)");
      end if;
      Three_Text(94..123) := "official instructions.        ";
      if Three_Text(1..15) /= "This is a test." then
         Report.Failed ("Incorrect text (3B)");
      end if;
      if Paragraph_Text'(Paragraph (3))(117) /= ' ' then
         Report.Failed ("Incorrect character (3C)");
      end if;
   end;

   Report.Result;

end C470001;
