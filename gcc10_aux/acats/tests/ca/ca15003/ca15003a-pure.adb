
package body CA15003A.Pure is
    function F(X: access Int) return Int is
    begin
        X.all := X.all + 1;
        return X.all;
    end F;
end CA15003A.Pure;
