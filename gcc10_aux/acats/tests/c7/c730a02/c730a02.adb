

     --==================================================================--


with Report;

with C730A02_0; -- Extended book abstraction.
with C730A02_1; -- Raw book data.
with C730A02_2; -- Instance.

use  C730A02_0; -- Primitive operations of Detailed_Book_Type directly visible.
use  C730A02_2; -- Operations inherited by Priv_Node_Type directly visible.

procedure C730A02 is


   List_Of_Books : Priv_Node_Ptr := null;  -- Head of linked list of books.


          --========================================================--


   procedure Create_List (Title, Author : in     C730A02_1.Data_List;
                          Pages         : in     C730A02_1.Page_Counts;
                          Head          : in out Priv_Node_Ptr) is

      Book     : Priv_Node_Type;  -- Object of extended type.
      Book_Ptr : Priv_Node_Ptr;

   begin
      for I in C730A02_1.Number_Of_Books loop
         Create_Book (Title (I), Author (I), Book);    -- Call twice-inherited
                                                       -- operation.
         Update_Pages (Book, Pages (I));               -- Call inherited op.
         Book_Ptr := new Priv_Node_Type'(Book);
         Add (Book_Ptr, Head);
      end loop;
   end Create_List;


          --========================================================--


   function Bad_List_Contents return Boolean is
      Book1_Ptr : Priv_Node_Ptr;
      Book2_Ptr : Priv_Node_Ptr;
      Book3_Ptr : Priv_Node_Ptr;
   begin

      Remove (List_Of_Books, Book1_Ptr);
      Remove (List_Of_Books, Book2_Ptr);
      Remove (List_Of_Books, Book3_Ptr);

      return (Book1_Ptr.Title.all   /= "Ulysses"           or   -- Inherited
              Book1_Ptr.Author.all  /= "Joyce, James"      or   -- components
              Book2_Ptr.Title.all   /= "Heart of Darkness" or   -- should still
              Book2_Ptr.Author.all  /= "Conrad, Joseph"    or   -- be visible
              Book3_Ptr.Title.all   /= "Wuthering Heights" or   -- in private
              Book3_Ptr.Author.all  /= "Bronte, Emily"     or   -- "generic"
                                                                -- extension.
              -- Call inherited operations using dereferenced pointers.
              Get_Pages (Book1_Ptr.all) /= 456             or
              Get_Pages (Book2_Ptr.all) /= 215             or
              Get_Pages (Book3_Ptr.all) /= 237);

   end Bad_List_Contents;


          --========================================================--


begin  -- Main program.

   Report.Test ("C730A02", "Inheritance of primitive operations: private " &
                "extension of formal tagged private type; actual is " &
                "a private extension");

   -- Create linked list using inherited operation:
   Create_List (C730A02_1.Title_List, C730A02_1.Author_List,
                C730A02_1.Page_List,  List_Of_Books);

   -- Verify results:
   if Bad_List_Contents then
      Report.Failed ("Wrong values after call to inherited operations");
   end if;

   Report.Result;

end C730A02;
