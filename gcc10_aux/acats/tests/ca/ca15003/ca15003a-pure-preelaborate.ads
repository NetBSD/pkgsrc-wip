
generic
package CA15003A.Pure.Preelaborate is
    pragma Preelaborate;
    One: Int := 1;
    function F(X: access Int) return Int;
end CA15003A.Pure.Preelaborate;
