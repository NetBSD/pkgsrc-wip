
     --==================================================================--

-- Public child package of an elevator application.  This package provides
-- an emergency operation.

package FA13A00_1.CA13A01_5 is            -- Emergency Operation

   -- Other type definitions in real application.

   procedure Emergency;

private
   type Bell_Type is (Inactive, Active);

end FA13A00_1.CA13A01_5;
