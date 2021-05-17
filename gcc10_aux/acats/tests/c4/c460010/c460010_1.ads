

     --==================================================================--


with Report;
pragma Elaborate (Report);

package C460010_1 is

  One  : Integer := Report.Ident_Int(1);
  Ten  : Integer := Report.Ident_Int(10);

  subtype Integer_Subtype is Integer range One .. Ten;


  Two  : Integer := Report.Ident_Int(2);
  Four : Integer := Report.Ident_Int(4);

  type Array_Integer_Index is array (Integer_Subtype range <>) of Boolean;

  subtype Array_Static_Integer_Constraint    is Array_Integer_Index(2..4);
  subtype Array_Nonstatic_Integer_Constraint is Array_Integer_Index(Two..Four);

end C460010_1;
