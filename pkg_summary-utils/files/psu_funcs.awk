# AWK functions for working on pkgsrc

# return a position where version begins
function pkgver_position (pkgname){
	return match(pkgname, /(-|>|>=|<|<=|=)(\[[^\[\]]*\][*+]|[^><=-])*$/)
}

# strip version from PKGNAME
function pkgname2pkgbase (pkgname){
	return substr(pkgname, 1, pkgver_position(pkgname)-1)
}
