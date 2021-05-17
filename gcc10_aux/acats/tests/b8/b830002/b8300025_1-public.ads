
package B8300025_1.Public is

    type New_T2 is tagged private;
    type New_T3 is new T3 with null record;
    type New_T3_Diff(Different_Name: Natural) is
      new T3(Same_Name => Different_Name) with null record;

private

    type New_T2 is new T2 with null record;

end B8300025_1.Public;
