

     --==================================================================--


with F730A001;        -- Book definitions. 
package C730A02_1 is  -- Raw data to be used in creating book elements.


   Book_Count : constant := 3;

   subtype Number_Of_Books is Integer range 1 .. Book_Count;

   type Data_List   is array (Number_Of_Books) of F730A001.Text_Ptr;
   type Page_Counts is array (Number_Of_Books) of Natural;

   Title_List  : Data_List   := (new String'("Wuthering Heights"),
                                 new String'("Heart of Darkness"),
                                 new String'("Ulysses"));

   Author_List : Data_List   := (new String'("Bronte, Emily"),
                                 new String'("Conrad, Joseph"),
                                 new String'("Joyce, James"));

   Page_List   : Page_Counts := (237, 215, 456);

end C730A02_1;
