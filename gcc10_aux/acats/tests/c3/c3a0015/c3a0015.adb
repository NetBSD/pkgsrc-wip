
with Ada.Exceptions;
use Ada.Exceptions;
with Ada.Unchecked_Deallocation;
with Report;
use Report;
with System.Storage_Elements;
use System.Storage_Elements;
with C3A0015_0;
procedure C3A0015 is

    type Standard_Pool is access Float;
    type Derived_Standard_Pool is new Standard_Pool;
    type Derived_Derived_Standard_Pool is new Derived_Standard_Pool;

    type User_Defined_Pool is access Integer;
    type Derived_User_Defined_Pool is new User_Defined_Pool;
    type Derived_Derived_User_Defined_Pool is new Derived_User_Defined_Pool;

    My_Pool : C3A0015_0.Pool (1024);
    for User_Defined_Pool'Storage_Pool use My_Pool;

    generic
	type Designated is private;
	Value : Designated;
	type Acc is access Designated;
	type Derived_Acc is new Acc;
    procedure Check (Subtest : String; User_Defined_Pool : Boolean);

    procedure Check (Subtest : String; User_Defined_Pool : Boolean) is

	procedure Deallocate is
	   new Ada.Unchecked_Deallocation (Object => Designated,
					   Name => Acc);
	procedure Deallocate is
	   new Ada.Unchecked_Deallocation (Object => Designated,
					   Name => Derived_Acc);

	First_Free : Storage_Count;
	X : Acc;
	Y : Derived_Acc;
    begin
	if User_Defined_Pool then
	    First_Free := My_Pool.First_Free;
	end if;
	X := new Designated'(Value);
	if User_Defined_Pool and then First_Free >= My_Pool.First_Free then
	    Failed (Subtest &
		    " - Allocation didn't consume storage in the pool - 1");
	else
	    First_Free := My_Pool.First_Free;
	end if;

	Y := Derived_Acc (X);
	if User_Defined_Pool and then First_Free /= My_Pool.First_Free then
	    Failed (Subtest &
		    " - Conversion did consume storage in the pool - 1");
	end if;
	if Y.all /= Value then
	    Failed (Subtest &
		    " - Incorrect allocation/conversion of access values - 1");
	end if;

	Deallocate (Y);
	if User_Defined_Pool and then First_Free <= My_Pool.First_Free then
	    Failed (Subtest &
		    " - Deallocation didn't release storage from the pool - 1");
	else
	    First_Free := My_Pool.First_Free;
	end if;

	Y := new Designated'(Value);
	if User_Defined_Pool and then First_Free >= My_Pool.First_Free then
	    Failed (Subtest &
		    " - Allocation didn't consume storage in the pool - 2");
	else
	    First_Free := My_Pool.First_Free;
	end if;

	X := Acc (Y);
	if User_Defined_Pool and then First_Free /= My_Pool.First_Free then
	    Failed (Subtest &
		    " - Conversion did consume storage in the pool - 2");
	end if;
	if X.all /= Value then
	    Failed (Subtest &
		    " - Incorrect allocation/conversion of access values - 2");
	end if;

	Deallocate (X);
	if User_Defined_Pool and then First_Free <= My_Pool.First_Free then
	    Failed (Subtest &
		    " - Deallocation didn't release storage from the pool - 2");
	end if;
    exception
	when E: others =>
	    Failed (Subtest & " - Exception " & Exception_Name (E) &
		    " raised - " & Exception_Message (E));
    end Check;


begin
    Test ("C3A0015", "Check that a dervied access type has the same " &
			"storage pool as its parent");

    Comment ("Access types using the standard storage pool");

    Std:
	declare
	    procedure Check1 is
	       new Check (Designated => Float,
			  Value => 3.0,
			  Acc => Standard_Pool,
			  Derived_Acc => Derived_Standard_Pool);
	    procedure Check2 is
	       new Check (Designated => Float,
			  Value => 4.0,
			  Acc => Standard_Pool,
			  Derived_Acc => Derived_Derived_Standard_Pool);
	    procedure Check3 is
	       new Check (Designated => Float,
			  Value => 5.0,
			  Acc => Derived_Standard_Pool,
			  Derived_Acc => Derived_Derived_Standard_Pool);
	begin
	    Check1 ("Standard_Pool/Derived_Standard_Pool",
		    User_Defined_Pool => False);
	    Check2 ("Standard_Pool/Derived_Derived_Standard_Pool",
		    User_Defined_Pool => False);
	    Check3 ("Derived_Standard_Pool/Derived_Derived_Standard_Pool",
		    User_Defined_Pool => False);
	end Std;

    Comment ("Access types using a user-defined storage pool");

    User:
	declare
	    procedure Check1 is
	       new Check (Designated => Integer,
			  Value => 17,
			  Acc => User_Defined_Pool,
			  Derived_Acc => Derived_User_Defined_Pool);
	    procedure Check2 is
	       new Check (Designated => Integer,
			  Value => 18,
			  Acc => User_Defined_Pool,
			  Derived_Acc => Derived_Derived_User_Defined_Pool);
	    procedure Check3 is
	       new Check (Designated => Integer,
			  Value => 19,
			  Acc => Derived_User_Defined_Pool,
			  Derived_Acc => Derived_Derived_User_Defined_Pool);
	begin
	    Check1 ("User_Defined_Pool/Derived_User_Defined_Pool",
		    User_Defined_Pool => True);
	    Check2 ("User_Defined_Pool/Derived_Derived_User_Defined_Pool",
		    User_Defined_Pool => True);
	    Check3
	       ("Derived_User_Defined_Pool/Derived_Derived_User_Defined_Pool",
		User_Defined_Pool => True);
	end User;

    Result;
end C3A0015;
