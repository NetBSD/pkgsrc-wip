
package body C470001_0 is -- Document_Manager

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

end C470001_0;
