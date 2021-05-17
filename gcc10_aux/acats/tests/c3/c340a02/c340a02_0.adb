

     --==================================================================--


package body C340A02_0 is


   procedure Update_Pages (Book  : in out Detailed_Book_Type;
                           Pages : in     Natural) is
   begin
      Book.Pages := Pages;
   end Update_Pages;


end C340A02_0;
