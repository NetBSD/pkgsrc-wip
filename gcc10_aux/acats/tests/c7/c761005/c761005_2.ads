
-----------------------------------------------------------------------------
with C761005_1;
package C761005_2 is
  
  type Final_Child is new C761005_1.Final_Abstract with null record;
  type Ltd_Final_Child is
       new C761005_1.Ltd_Final_Abstract_Child with null record;

end C761005_2;
