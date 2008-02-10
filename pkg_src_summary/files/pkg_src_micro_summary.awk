#!/usr/bin/awk -f

BEGIN {
	pkgname_re = "^[^${}()]+$" #"^[[:alnum:]_-]+-[[:digit:]]+([.][[:digit:]]+)*$"
}

function init_vars (){
	delete var
	doubtful_inc  = 0
}

function print_name_and_path (){
	if (check()){
		print "+", pkgname, last_fn
	}else{
		print "-", pkgname, distname, last_fn
	}
}

function check (){
	# fast checks
#	if (doubtful_inc){
		# paranoia!
#		print "-", pkgname, distname, last_fn
#		return
#	}
	pkgname     = var ["PKGNAME"]
	distname    = var ["DISTNAME"]
	pkgrevision = var ["PKGREVISION"]

	if (distname != "" && pkgname == ""){
		pkgname = distname
	}
	if (pkgname == ""){
		return 0
	}
	if (pkgname ~ pkgname_re){
		return 1
	}

#	print "pkgname=" pkgname
#	print "distname=" distname
	fflush()
	while (match(pkgname, /[$][{][[:upper:]_]+(:S\/.*\/.*\/)?[}]/)){
		left  = substr(pkgname, 1, RSTART-1)
		right = substr(pkgname, RSTART+RLENGTH)

		if (pkgname !~ /:S\//){
			varname = substr(pkgname, RSTART + 2, RLENGTH - 3)
			if (! (varname in var)){
				return 0
			}
			pkgname = left var [varname] right
			continue
		}

		repl  = substr(pkgname, RSTART + 2, RLENGTH - 4)
		varname = repl
		sub(/:.*$/, "", varname)
		sub(/^[^:]+:S\//, "", repl)

		if (! (varname in var)){
			return 0
		}
#		print "left=" left
#		print "right=" right
#		print "varname=" varname
#		print "repl=" repl
#		print "----"

		match(repl, "/")
		old_string = substr(repl, 1, RSTART-1)
		new_string = substr(repl, RSTART+1)
		if (old_string ~ /[$^\[\]\\]/)
			return 0

		gsub(/[?{}|()*+.]/, "[&]", old_string)
		sub(old_string, new_string, var [varname])
		pkgname = left var [varname] right
	}

	# final check
	if (pkgname ~ pkgname_re){
		return 1
	}

	# :-(
	return 0
}

last_fn != FILENAME {
	if (last_fn != ""){
		print_name_and_path()
		init_vars()
	}

	last_fn = FILENAME
}

$1 == ".include" && $2 !~ /^"[.][.]\/[.][.]\/mk/ && $2 !~ /buildlink3.mk"$/ {
	doubtful_inc=1
}

function trim (s){
	sub(/^[ \t]+/, "", s)
	sub(/[ \t]+$/, "", s)

	return s
}

match ($0, /^[[:upper:]_]+=/) {
	var [substr($1, 1, RLENGTH - 1)] = trim(substr($0, RLENGTH + 1))
	next
}

END {
	if (last_fn != ""){
		print_name_and_path()
	}
}
