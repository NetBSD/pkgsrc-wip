
with B8300025_1; use B8300025_1;
package B8300025_1_Unrelated is

    -- These ones are OK, because we're not in a child of the package
    -- where the parent types are declared.

    type T10 is new T2 with
        record
            Same_Name: Boolean; -- OK
        end record;
    type T11(Same_Name: Natural) -- OK
      is new T2 with null record;
    type T12 is new T2 with
        record
            Same_Name: Natural := Natural'Last; -- OK
        end record;
    type T13(Different_Name: Natural) is
      new T3(Same_Name => Different_Name) with
        record
            Same_Name: Natural; -- OK; old discriminant is gone.
        end record;
end B8300025_1_Unrelated;
