
with BA12014_0.BA12014_2;
private with BA12014_0.BA12014_1;
private with BA12014_F;
package BA12014_0.Parent is

    Y : Float := BA12014_0.BA12014_2.BA12014_F (3); -- OK.

private

    Z : Integer renames BA12014_0.BA12014_1.X; -- OK.

end BA12014_0.Parent;
