

     --==================================================================--


with Report;

with C340A02_0; -- Extended book abstraction.
with C340A02_1; -- Raw book data.
with C340A02_2; -- Instance.

use  C340A02_0; -- Primitive operations of Detailed_Book_Type directly visible.
use  C340A02_2; -- Operations inherited by Node_Type directly visible.

procedure C340A02 is


   List_Of_Books : Node_Ptr := null;  -- Head of linked list of books.


          --========================================================--


   procedure Create_List (Title, Author : in     C340A02_1.Data_List;
                          Pages         : in     C340A02_1.Page_Counts;
                          Head          : in out Node_Ptr) is

      Book     : Node_Type;  -- Object of extended type.
      Book_Ptr : Node_Ptr;

   begin
      for I in C340A02_1.Number_Of_Books loop
         Create_Book (Title (I), Author (I), Book);    -- Call twice-inherited
                                                       -- operation.
         Update_Pages (Book, Pages (I));               -- Call inherited op.
         Book_Ptr := new Node_Type'(Book);
         Add (Book_Ptr, Head);
      end loop;
   end Create_List;


          --========================================================--


   function Bad_List_Contents return Boolean is
   begin
      return (List_Of_Books.Title.all            /= "Ulysses"           or
              List_Of_Books.Author.all           /= "Joyce, James"      or
              List_Of_Books.Pages                /= 456                 or
              List_Of_Books.Next.Title.all       /= "Heart of Darkness" or
              List_Of_Books.Next.Author.all      /= "Conrad, Joseph"    or
              List_Of_Books.Next.Pages           /= 215                 or
              List_Of_Books.Next.Next.Title.all  /= "Wuthering Heights" or
              List_Of_Books.Next.Next.Author.all /= "Bronte, Emily"     or
              List_Of_Books.Next.Next.Pages      /= 237);

   end Bad_List_Contents;


          --========================================================--


begin  -- Main program.

   Report.Test ("C340A02", "Inheritance of primitive operations: record " &
                "extension of formal tagged private type; actual is " &
                "a record extension");

   -- Create linked list using inherited operation:
   Create_List (C340A02_1.Title_List, C340A02_1.Author_List,
                C340A02_1.Page_List,  List_Of_Books);

   -- Verify results:
   if Bad_List_Contents then
      Report.Failed ("Wrong values after call to inherited operations");
   end if;

   Report.Result;

end C340A02;
