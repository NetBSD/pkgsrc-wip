
with C452003_Root.Child;
package C452003A is

   pragma Assertion_Policy (Check);

   -- Note: We have to do most of the tests in a package, since they require
   -- declaring library-level objects.

   procedure Do_Tests (Nested_Obj : access C452003_Root.Root_Type'Class;
                       Is_Root : in Boolean);

end C452003A;
