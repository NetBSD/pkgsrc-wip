

     --==================================================================--


with Report;

with F730A001;   -- Book definitions.
with C730A01_0;  -- Raw book data.
with C730A01_1;  -- Instance.

use  F730A001;   -- Primitive operations of Book_Type directly visible.
use  C730A01_1;  -- Operations inherited by Node_Type directly visible.

procedure C730A01 is


   List_Of_Books : Priv_Node_Ptr := null;  -- Head of linked list of books.


          --========================================================--


   procedure Create_List (Title, Author : in     C730A01_0.Data_List;
                          Head          : in out Priv_Node_Ptr) is

      Book     : Priv_Node_Type;  -- Object of extended type.
      Book_Ptr : Priv_Node_Ptr;

   begin
      for I in C730A01_0.Number_Of_Books loop
         Create_Book (Title (I), Author (I), Book);    -- Call inherited
                                                       -- operation.
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
      return (Book1_Ptr.Title.all  /= "Ulysses"           or   -- Inherited
              Book1_Ptr.Author.all /= "Joyce, James"      or   -- components
              Book2_Ptr.Title.all  /= "Heart of Darkness" or   -- should still
              Book2_Ptr.Author.all /= "Conrad, Joseph"    or   -- be visible in
              Book3_Ptr.Title.all  /= "Wuthering Heights" or   -- private
              Book3_Ptr.Author.all /= "Bronte, Emily");        -- extension.

   end Bad_List_Contents;


          --========================================================--


begin  -- Main program.

   Report.Test ("C730A01", "Inheritance of primitive operations: private " &
                "extension of formal tagged private type; actual is " &
                "an ultimate ancestor type");

   -- Create linked list using inherited operation:
   Create_List (C730A01_0.Title_List, C730A01_0.Author_List, List_Of_Books);

   -- Verify results:
   if Bad_List_Contents then
      Report.Failed ("Wrong values after call to inherited operation");
   end if;

   Report.Result;

end C730A01;
