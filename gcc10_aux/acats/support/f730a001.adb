

     --==================================================================--


package body F730A001 is  -- Book definitions.


   procedure Create_Book (Title  : in     Text_Ptr;
                          Author : in     Text_Ptr;
                          Book   :    out Book_Type) is
   begin
      Book.Title  := Title;
      Book.Author := Author;
   end Create_Book;
                          

end F730A001;
