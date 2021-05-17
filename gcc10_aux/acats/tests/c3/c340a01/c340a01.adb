

     --==================================================================--


with Report;

with F340A001;   -- Book definitions.
with C340A01_0;  -- Raw book data.
with C340A01_1;  -- Instance.

use  F340A001;   -- Primitive operations of Book_Type directly visible.
use  C340A01_1;  -- Operations inherited by Node_Type directly visible.

procedure C340A01 is


   List_Of_Books : Node_Ptr := null;  -- Head of linked list of books.


          --========================================================--


   procedure Create_List (Title, Author : in     C340A01_0.Data_List;
                          Head          : in out Node_Ptr) is

      Book     : Node_Type;  -- Object of extended type.
      Book_Ptr : Node_Ptr;

   begin
      for I in C340A01_0.Number_Of_Books loop
         Create_Book (Title (I), Author (I), Book);    -- Call inherited
                                                       -- operation.
         Book_Ptr := new Node_Type'(Book);
         Add (Book_Ptr, Head);
      end loop;
   end Create_List;


          --========================================================--


   function Bad_List_Contents return Boolean is
   begin
      return (List_Of_Books.Title.all            /= "Ulysses"           or
              List_Of_Books.Author.all           /= "Joyce, James"      or
              List_Of_Books.Next.Title.all       /= "Heart of Darkness" or
              List_Of_Books.Next.Author.all      /= "Conrad, Joseph"    or
              List_Of_Books.Next.Next.Title.all  /= "Wuthering Heights" or
              List_Of_Books.Next.Next.Author.all /= "Bronte, Emily");
   end Bad_List_Contents;


          --========================================================--


begin  -- Main program.

   Report.Test ("C340A01", "Inheritance of primitive operations: record " &
                "extension of formal tagged private type; actual is " &
                "an ultimate ancestor type");

   -- Create linked list using inherited operation:
   Create_List (C340A01_0.Title_List, C340A01_0.Author_List, List_Of_Books);

   -- Verify results:
   if Bad_List_Contents then
      Report.Failed ("Wrong values after call to inherited operation");
   end if;

   Report.Result;

end C340A01;
