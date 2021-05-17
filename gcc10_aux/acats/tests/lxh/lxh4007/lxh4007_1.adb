
package body LXH4007_1 is

  function Do_Nothing_Special( Value : Float) return Boolean is
  begin
    return Value in 0.0..1.0;
  end Do_Nothing_Special;

end LXH4007_1;
