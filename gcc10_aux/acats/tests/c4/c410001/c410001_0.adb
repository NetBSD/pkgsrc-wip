
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C410001_0 is

  -- Note that some failing cases will cause duplicate failure messages;
  -- rather than have the procedure/function bodies be null, the error
  -- checking code makes for a reasonable anti-optimization feature.

  procedure Proc is
  begin
    if Expect_Exception then
      Report.Failed("Expected exception did not occur: Proc");
    end if;
  end Proc;

  function Func(I:Integer) return Integer is
  begin
    if Expect_Exception then
      Report.Failed("Expected exception did not occur: Func");
    end if;
    return Report.Ident_Int(I);
  end Func;

  procedure Proc_Para( Param : Proc_Ref ) is
  begin

    Param.all;        -- call by explicit dereference

    if Expect_Exception then
      Report.Failed("Expected exception did not occur: Proc_Para");
    end if;

  exception
    when Constraint_Error =>
      if not Expect_Exception then
        Report.Failed("Unexpected Constraint_Error: Proc_Para");
      end if;  -- else null; expected the exception
    when others => Report.Failed("Unexpected exception: Proc_Para");
  end Proc_Para;

  function Func_Para( Param : Func_Ref ) return Integer is
  begin

    return Param(1);  -- call by implicit dereference

    if Expect_Exception then
      Report.Failed("Expected exception did not occur: Func_Para");
    end if;
    return 1;  -- really just to avoid warnings

  exception
    when Constraint_Error =>
      if not Expect_Exception then
        Report.Failed("Unexpected Constraint_Error: Func_Para");
        return 0;
      else
        return 1995;  -- any value other than this is unexpected
      end if;
    when others => Report.Failed("Unexpected exception: Func_Para");
                   return -42;
  end Func_Para;

  protected body Prot_Obj is

    procedure Prot_Proc is
    begin
      if Expect_Exception then
        Report.Failed("Expected exception did not occur: Prot_Proc");
      end if;
    end Prot_Proc;

    function Prot_Func return Boolean is
    begin
      if Expect_Exception then
        Report.Failed("Expected exception did not occur: Prot_Func");
      end if;
      return Report.Ident_Bool( True );
    end Prot_Func;

  end Prot_Obj;

end C410001_0;
