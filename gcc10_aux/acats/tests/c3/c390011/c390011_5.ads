
----------------------------------------------------------------- C390011_5

with C390011_3;
with C390011_4;
package C390011_5 is

  type Table_3 is new C390011_3.Table with record
    Serial_Number : Integer;
  end record;

  type Table_4 is new C390011_4.Table with record
    Serial_Number : Integer;
  end record;

end C390011_5;
