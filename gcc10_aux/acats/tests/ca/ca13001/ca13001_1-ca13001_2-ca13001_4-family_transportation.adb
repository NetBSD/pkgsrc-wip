
     --==================================================================--

separate (CA13001_1.CA13001_2.CA13001_4)
protected body Family_Transportation is

   procedure Get_Vehicle (Who : in     Family;
                          Key :    out Key_Type) is
   begin
      case Who is
         when Father|Mother => 
            -- Drive new car to work

            -- Reference package with'ed by the subunit parent's body.
            if Destination(Who) = Work then

               -- Reference type declared in the private parent of the subunit
               -- parent's body.
               -- Reference type declared in the visible part of the 
               -- subunit parent's body.
               if not Vehicles(New_Car).In_Use and Fuel(New_Car) 

                 -- Reference type declared in the public sibling of the 
                 -- subunit parent's body.
                 and not CA13001_1.CA13001_2.CA13001_3.Flat_Tire(New_Car) then
                    Vehicles(New_Car).In_Use := true;

                    -- Reference type declared in the private part of the 
                    -- protected subunit.
                    Keys(New_Car).Available := false;
                    Key                     := Transportation'pos(New_Car);
               else
                 -- Reference type declared in the grandparent of the subunit
                 -- parent's body.
                 Walking := true;
               end if;

            -- Drive clunker to other destinations.
            else
               if not Vehicles(Clunker).In_Use and Fuel(Clunker) and not 
                 CA13001_1.CA13001_2.CA13001_3.Flat_Tire(Clunker) then
                    Vehicles(Clunker).In_Use := true;
                    Keys(Clunker).Available  := false;
                    Key                      := Transportation'pos(Clunker);
               else
                 Walking := true;
                 Key     := Transportation'pos(Bicycle);
               end if;
            end if;
    
         -- Similar for Teen.
         when Teen => 
            if not Vehicles(Clunker).In_Use and Fuel(Clunker) and not 
              CA13001_1.CA13001_2.CA13001_3.Flat_Tire(Clunker) then
                 Vehicles(Clunker).In_Use := true;
                 Keys(Clunker).Available  := false;
                 Key                      := Transportation'pos(Clunker);
            else
               Walking := true;
               Key     := Transportation'pos(Bicycle);
            end if;
      end case;

   end Get_Vehicle;

   ----------------------------------------------------------------

   -- Any family member can bring back the transportation with the key.

   procedure Return_Vehicle (Tr : in Transportation) is
   begin
      Vehicles(Tr).In_Use := false;
      Keys(Tr).Available  := true;
   end Return_Vehicle;

   ----------------------------------------------------------------

   function TC_Verify (What : Transportation) return boolean is
   begin
      return Keys(What).Available;
   end TC_Verify;
   
end Family_Transportation;
