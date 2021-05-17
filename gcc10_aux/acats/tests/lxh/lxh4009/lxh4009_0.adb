
package body LXH4009_0 is

  function Func(F:Float) return Access_Float is
  begin
    return new Float'(F);
  end Func;

end LXH4009_0;
