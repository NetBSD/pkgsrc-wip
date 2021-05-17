
with BA12018_0.BA12018_1;
private with BA12018_0.BA12018_2;
package BA12018_T0 is
    -- Here, BA12018_0 is directly visible as it is withed as well as private
    -- withed.

    Y : Integer := BA12018_0.Obj;                -- OK. {20;1}

private

    Z : Integer renames BA12018_0.Obj;           -- OK. {25;1}

end BA12018_T0;
