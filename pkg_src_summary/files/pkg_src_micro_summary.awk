#!/usr/bin/awk -f

BEGIN {
	good_pkgname_re = "^[^${}()]+$" #"^[[:alnum:]_-]+-[[:digit:]]+([.][[:digit:]]+)*$"
}

# output format:
#    for success:
#       + <SPACE> pkgname+pkgrevision <SPACE> Makefile
#    for failure:
#       - <SPACE> pkgname <SPACE> distname <SPACE> Makefile
function print_name_and_path (){
	if (check()){
		if (pkgrevision != ""){
			pkgname = pkgname "nb" pkgrevision
		}
		print "+", pkgname, last_fn
	}else{
		print "-", pkgname, distname, last_fn
	}
}

# try to get a real PKGNAME...
function check (){
	# fast checks
	pkgname     = var ["PKGNAME"]
	distname    = var ["DISTNAME"]
	pkgrevision = var ["PKGREVISION"]

	# distname -> pkgname?
	if (distname != "" && pkgname == ""){
		pkgname = distname
	}
	# both - empty?
	if (pkgname == ""){
		return 0
	}
	# is pkgname already good?
	if (pkgname ~ good_pkgname_re){
		return 1
	}

	# trye replacements...
	while (match(pkgname, /[$][{][[:alnum:]_.]+(:S\/.*\/.*\/)?[}]/)){
		left  = substr(pkgname, 1, RSTART-1)
		right = substr(pkgname, RSTART+RLENGTH)

		# ${VARNAME} found?
		if (pkgname !~ /:S\//){
			# yes!
			varname = substr(pkgname, RSTART + 2, RLENGTH - 3)
			if (! (varname in var)){
				return 0
			}
			pkgname = left var[varname] right
			continue
		}

		# ${VARNAME:S/old_substr/new_substr/} found!
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

		# complex old_string?
		if (old_string ~ /[$^\[\]\\]/){
			# yes!
			return 0
		}

		# string to regexp
		gsub(/[?{}|()*+.]/, "[&]", old_string)

		# old_string to new_string
		sub(old_string, new_string, var [varname])

		#
		pkgname = left var[varname] right
	}

	# final check
	if (pkgname ~ good_pkgname_re){
		return 1
	}

	# :-(
	return 0
}

function trim (s){
	sub(/^[ \t]+/, "", s)
	sub(/[ \t]+$/, "", s)

	return s
}

function process_include (fn, inc,              ret, cond_cnt, varname){
	sub(/\/[^\/]+$/, "", fn)
	if (inc !~ /^\//)
		fn = fn "/" inc

#	print "incl:" fn

	cond_cnt = 0
	while ((ret = getline < fn) > 0){
		if ($1 == ".if") {
			++cond_cnt
			continue
		}

		if ($1 == ".endif") {
			--cond_cnt
			continue
		}

		if (cond_cnt > 0){
			# conditional assignments are not remembered
			continue
		}

		if (match ($1, /^[[:alnum:]_.]+[?]?=/)) {
			varname = $1
			sub(/[?]?=.*$/, "", varname)

			sub(/^[^=]+=/, "", $0)
			var [varname] = trim($0)
#			print varname " ---> " var [varname]
			continue
		}

		if ($1 == ".include" &&
			$2 !~ /buildlink3.mk"$/ && $2 !~ /^"[.][.]\/[.][.]\/mk/)
		{
			# recursive .include processing
			process_include(fn, substr($2, 2, length($2)-2))
		}
	}

	close(fn)
}

BEGIN {
	for (i=1; i < ARGC; ++i){
		last_fn = ARGV [i]
		process_include(".", last_fn)
		print_name_and_path()
		delete var
	}

	exit 0
}
