
package B7310016_1.Places.P.Q is
    -- For specification errors, see B7310016_1.Places.P.R.
    package R is
        type Comp2 is limited private;
        type A is array(Integer range <>) of Comp2;
        function A_Func_1 return A;
        function A_Func_2 return A;
    private

        type Comp2 is new Comp1;
        -- A becomes nonlimited here.
        -- "="(A, A) return Boolean is implicitly declared here.

        A1: A := A_Func_1; -- OK
        B3: Boolean := A_Func_1 = A_Func_2; -- OK
        B4: Boolean := A_Func_1 /= A_Func_2; -- OK
    end R;
private
    -- Now we find out what Comp1 really is, which reveals
    -- more information about Comp2, but we're not within
    -- the immediate scope of Comp2, so we don't do anything
    -- about it yet.
    A3: R.A(1..10); -- OK
end B7310016_1.Places.P.Q;
