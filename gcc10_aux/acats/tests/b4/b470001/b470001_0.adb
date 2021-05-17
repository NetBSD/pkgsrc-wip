
package body B470001_0 is -- Document_Manager

   Document : array (Paragraph_Number) of Paragraph_Info;

   procedure Set_Paragraph (Num : in Paragraph_Number;
                            Text : in String;
                            Indent : in Natural := 0) is
      -- Insert paragraph number Num with the given Text and Indent.
   begin
      Document(Num) := (Text => new String'(Text),
                        Indent => Indent,
                        Length => Text'Length);
   end Set_Paragraph;


   procedure Change_Paragraph_Indent (Num : in Paragraph_Number;
                                      Offset : in Integer;
                                      New_Indent : out Natural) is
      -- Change the paragraph indent.
   begin
      Document(Num).Indent := Document(Num).Indent + Offset;
      New_Indent := Document(Num).Indent;
   end Change_Paragraph_Indent;


   function Paragraph (Num : in Paragraph_Number) return Paragraph_Info is
      -- Get the paragraph information for paragraph Num.
      -- We presume the real application would do more than just return
      -- the information passed in.
   begin
      return Document(Num);
   end Paragraph;


   function Paragraph (Num : in Paragraph_Number) return Paragraph_Text is
      -- Get the paragraph text for paragraph Num.
      -- We presume the real application would do more than just return
      -- the information passed in.
   begin
      return Document(Num).Text;
   end Paragraph;


   function Total_Width (P : in Paragraph_Info) return Natural is
      -- Returns the total width for the paragraph P.
   begin
      return P.Length + P.Indent;
   end Total_Width;


   procedure Calc_Width (P : in out Paragraph_Info) is
      -- Calculates the total width for the paragraph P.
   begin
      null;
   end Calc_Width;

end B470001_0;
