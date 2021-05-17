
package body C3A0015_0 is

    use System;

    procedure Allocate (Pool : in out C3A0015_0.Pool;
			Storage_Address : out System.Address;
			Size_In_Storage_Elements : in Storage_Count;
			Alignment : in Storage_Count) is
	Unaligned_Address : constant System.Address :=
	   Pool.Contents (Pool.First_Free)'Address;
	Unalignment : Storage_Count;
    begin
	Unalignment := Unaligned_Address mod Alignment;
	if Unalignment = 0 then
	    Storage_Address := Unaligned_Address;
	    Pool.First_Free := Pool.First_Free + Size_In_Storage_Elements;
	else
	    Storage_Address :=
	       Pool.Contents (Pool.First_Free + Alignment - Unalignment)'
		  Address;
	    Pool.First_Free := Pool.First_Free + Size_In_Storage_Elements +
				  Alignment - Unalignment;
	end if;
    end Allocate;

    procedure Deallocate (Pool : in out C3A0015_0.Pool;
			  Storage_Address : in System.Address;
			  Size_In_Storage_Elements : in Storage_Count;
			  Alignment : in Storage_Count) is
    begin
	if Storage_Address + Size_In_Storage_Elements =
	   Pool.Contents (Pool.First_Free)'Address then
	    -- Only deallocate if the block is at the end.
	    Pool.First_Free := Pool.First_Free - Size_In_Storage_Elements;
	end if;
    end Deallocate;

    function Storage_Size (Pool : in C3A0015_0.Pool) return Storage_Count is
    begin
	return Pool.Storage_Size;
    end Storage_Size;

end C3A0015_0;
