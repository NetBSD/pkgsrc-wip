

     --==================================================================--


with BXC6002_0;
package BXC6002_1 is

   generic
      Formal_Object: in out BXC6002_0.Vowels;
   package Vowels_Formal is end;

   generic
      Formal_Object: in out BXC6002_0.Four_Bits;
   package Four_Bits_Formal is end;

   generic
      Formal_Object: in out BXC6002_0.Array_Of_Four_Bits;
   package BitArray_Formal is end;

   generic
      type Formal_Type is private;
      Formal_Object: in out Formal_Type;
   package Private_Formal is end;

end BXC6002_1;
