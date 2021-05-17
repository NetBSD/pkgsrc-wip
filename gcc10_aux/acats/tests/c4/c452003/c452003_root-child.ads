
package C452003_Root.Child is

   pragma Assertion_Policy (Check);

   type Child_Type is new Root_Type with record
       Name : String(1..4);
   end record;

   type Any_Child_Ptr is access all Child_Type'Class;

   overriding
   procedure Save (Obj : access Child_Type)
      with Pre => Obj in Any_Root_Ptr;

   overriding
   function Is_Present (Obj : access Child_Type) return Boolean;

   type TC_Result is (Is_Null, Done, Wrong_Tag);

   procedure Force_Save (Obj : access Root_Type'Class;
                         Result : out TC_Result);

end C452003_Root.Child;
