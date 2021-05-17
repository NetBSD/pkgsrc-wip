
generic
    type Int is new Big_Int;
package CA15003A.Pure is
    pragma Pure;
    function F(X: access Int) return Int;
end CA15003A.Pure;
