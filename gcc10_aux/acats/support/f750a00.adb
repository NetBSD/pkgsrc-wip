

package body F750A00 is

    function Func_Lim_Rec return Lim_Rec is
    begin
       return (A => 45, B => False);
    end Func_Lim_Rec;

    function Func_Lim_Array return Short_Lim_Array is
    begin
       return (1 .. 3 => (A => 4, B => False));
    end Func_Lim_Array;

    function Func_Lim_Tagged (Ext : in Boolean) return Lim_Tagged'Class is
    begin
       if Ext then
          return Lim_Ext'(R => (A => 15, B => False), N => 31, G => 5);
       else
          return Lim_Tagged'(R => (A => 15, B => False), N => 31);
       end if;
    end Func_Lim_Tagged;

    function Func_New_One return Lim_Tagged is
    begin
       return (R => (A => 4, B => False), N => 9);
    end Func_New_One;

    function Func_New_One return Lim_Ext is
    begin
       return (R => (A => 7, B => True), N => 5, G => 8);
    end Func_New_One;

    function Func_Lim_Ext return Lim_Ext is
    begin
       return (R => (A => 7, B => True), N => 5, G => 8);
    end Func_Lim_Ext;

    function Func_Lim_Tagged_Access (Ext : in Boolean) return Any_Tagged_Access is
    begin
       if Ext then
          return Var_Lim_Ext'Access;
       else
          return Var_Lim_Tagged'Access;
       end if;
    end Func_Lim_Tagged_Access;

    function Func_Lim_Ext_Access return access Lim_Ext is
    begin
       return Var_Lim_Ext'Access;
    end Func_Lim_Ext_Access;

    function Func_Lim_Comp return Lim_Comp is
    begin
       return (N => 382, P => <>);
    end Func_Lim_Comp;

    protected body Prot is
       function Get return Natural is
       begin
          return Value;
       end Get;

       procedure Set (Val : in Natural) is
       begin
          Value := Val;
       end Set;
    end Prot;

end F750A00;

