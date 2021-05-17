

limited private with BA12016_0.BA12016_1;
package BA12016_0.Parent is

    Y : Float := 0.0;

private

    Z : access BA12016_0.BA12016_1.R := null; -- OK.

end BA12016_0.Parent;
