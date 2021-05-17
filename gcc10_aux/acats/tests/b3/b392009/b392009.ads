

     --===================================================================--


with B392009_0;
package B392009 is

--
-- Parameters in designated profiles are of specific type:
--

   type Root_Proc is access procedure (P: in B392009_0.Root);
   type Root_Func is access function (P: B392009_0.Root) return B392009_0.Root;

   Proc_Ptr : Root_Proc := B392009_0.Proc'Access;    -- Designates Root's Proc.
   Func_Ptr : Root_Func := B392009_0.Func'Access;    -- Designates Root's Func.

   Root_Obj       : B392009_0.Root;
   Child_Obj      : B392009_0.Child;
   Root_Class_Obj : B392009_0.Root'Class := Root_Obj;


   procedure Dynamically_Tagged_Actuals (P : in out B392009_0.Root'Class);



--
-- Parameters in designated profiles are access parameters:
--
   -- Note that values of Acc_Parm_Proc will designate class-wide operations,
   -- while values of Acc_Parm_Func (may) designate primitive operations.

   type Acc_Parm_Proc is access procedure (P: access B392009_0.Root'Class);
   type Acc_Parm_Func is access function (P: not null access B392009_0.Root)
     return B392009_0.Root;

   Acc_Proc_Ptr : Acc_Parm_Proc := B392009_0.Access_Parm_Proc'Access;
   Acc_Func_Ptr : Acc_Parm_Func :=
     B392009_0.Access_Parm_Func'Access;              -- Designates Root's op.

   type Root_Acc  is access B392009_0.Root;
   type Child_Acc is access B392009_0.Child;
   type Class_Acc is access B392009_0.Root'Class;

   Root_Ptr       : Root_Acc  := new B392009_0.Root'(Root_Obj);
   Child_Ptr      : Child_Acc := new B392009_0.Child'(Child_Obj);
   Root_Class_Ptr : Class_Acc := new B392009_0.Root'(Root_Obj);


   procedure Not_Primitive_Operation;


end B392009;
