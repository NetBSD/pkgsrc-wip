

     --==================================================================--


package body C730A02_0 is


   procedure Update_Pages (Book  : in out Detailed_Book_Type;
                           Pages : in     Natural) is
   begin
      Book.Pages := Pages;
   end Update_Pages;


   function Get_Pages (Book : in Detailed_Book_Type) return Natural is
   begin
      return (Book.Pages);
   end Get_Pages;


end C730A02_0;
