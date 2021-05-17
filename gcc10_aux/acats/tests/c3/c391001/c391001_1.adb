 
 package body C391001_1 is
   Counter : Natural := 0;
   procedure Create( The_Plaque : in out Object ) is
   begin
     if The_Plaque.Serial_Number = 0 then
       Counter := Counter +1;
       The_Plaque.Serial_Number := Counter;
     else
       raise Reserialized;
     end if;
   end Create;
 
   function "="( Left_Plaque,Right_Plaque : Object ) return Boolean is
   begin
     return (Left_Plaque.Serial_Number = Right_Plaque.Serial_Number)
            and then -- two uninitialized plates are unequal
              (Left_Plaque.Serial_Number /= 0);
   end "=";
 
   function TC_Match( Left_Plaque : Object; Right_Natural : Natural )
     return Boolean is
   begin
     return (Left_Plaque.Serial_Number = Right_Natural);
   end TC_Match;
 
   function Serial_Number( A_Plaque : Object ) return Natural is
   begin
     if A_Plaque.Serial_Number = 0 then
       raise Unserialized;
     end if;
     return A_Plaque.Serial_Number;
   end Serial_Number;
 end C391001_1;
