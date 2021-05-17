
package body CA15003A.Pure.Preelaborate is
    function F(X: access Int) return Int is
    begin
        X.all := X.all + One;
        return X.all;
    end F;
end CA15003A.Pure.Preelaborate;
