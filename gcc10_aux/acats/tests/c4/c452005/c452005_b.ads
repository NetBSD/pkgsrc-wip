
with C452005_A;
package C452005_B is

   MAX : constant := 5;

   type Lim_List is array (1 .. MAX) of C452005_A.Lim_Data_Type;

   function "=" (Left, Right : Lim_List) return Boolean;

   type Nonlim_List is array (1 .. MAX) of C452005_A.Nonlim_Data_Type;

   function "=" (Left, Right : Nonlim_List) return Boolean;

   procedure Append (Obj : in out Nonlim_List;
                     Val : in C452005_A.Nonlim_Data_Type);

end C452005_B;
