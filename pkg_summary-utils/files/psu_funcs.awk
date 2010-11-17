# AWK functions for working on pkgsrc

# return a position where version begins
function pkgver_position (pkgname,            idx){
	if (match(pkgname, /<|>|=/))
		return RSTART
	else
		return match(pkgname, /-(\[[^\[\]]*\]|[^-])*$/)
}

# strip version from PKGNAME
function pkgname2pkgbase (pkgname){
	return substr(pkgname, 1, pkgver_position(pkgname)-1)
}

# extract version from PKGNAME, e.g. -1.2.3, -[0-9]*, >=1.0 etc.
function pkgname2version (pkgname,       pos){
	pos = pkgver_position(pkgname)

	if (substr(pkgname, pos, 1) == "-")
		return substr(pkgname, pos+1)
	else
		return substr(pkgname, pos)
}

# remove ../../ prefix, extra spaces and ending /
function normalize_pkgpath (pkgpath){
	sub(/^[.][.]\/[.][.]\//, "", pkgpath)
	sub(/^ +/, "", pkgpath)
	sub(/ +$/, "", pkgpath)
	sub(/\/+$/, "", pkgpath)
	return pkgpath
}

# Source dependency to PKGPATH
# checkperms>=1.1:../../sysutils/checkperms/ to sysutils/checkperms
function src_depend2pkgpath (dep){
	sub(/^[^:]*:/, "", dep)
	return normalize_pkgpath(dep)
}
