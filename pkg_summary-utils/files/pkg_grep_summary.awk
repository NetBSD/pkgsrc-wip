
#use "psu_funcs.awk"

BEGIN {
	grep_summary__skip = -1 # -1 - unknown, 0 - false, 1 - true
	count              = 0
}

function update_skip (){
	grep_summary__skip = grep_summary__condition()
	if (grep_summary__skip == 0 || grep_summary__skip == 1){
		grep_summary__skip = !grep_summary__skip
	}

	if (grep_summary__skip == 0){
		for (i=0; i < count; ++i){
			print accu [i]
		}

		delete accu
		count = 0
	}
}

grep_summary__skip == 1 && NF > 0 {
	next
}

{
	pos = index($0, "=")
	if (pos > 0){
		fname  = substr($0, 1, pos-1)
		fvalue = substr($0, pos+1)
	}else{
		fname  = ""
		fvalue = ""
	}
}

(grep_summary__field == "PKGBASE") && (fname == "PKGNAME") {
	if (grep_summary__skip == -1){
		fname = "PKGBASE"
		fvalue = pkgname2pkgbase(fvalue)
		update_skip()
	}
}

function check_PKGPATHe (){
	if (assigns != "" && pkgpath != ""){
		fvalue = pkgpath ":" assigns
		fname  = "PKGPATHe"
		update_skip()
	}else if (index(pkgpath, ":") > 0){
		fvalue = pkgpath
		fname  = "PKGPATHe"
		update_skip()
	}
}

(grep_summary__field == "PKGPATHe") {
	if (grep_summary__skip == -1){
		if (fname == "ASSIGNMENTS") {
			assigns = fvalue
			check_PKGPATHe()
		}else if (fname == "PKGPATH") {
			pkgpath = fvalue
			check_PKGPATHe()
		}
	}
}

(grep_summary__field == "PKGPATH" && idx = index(fvalue, ":")) {
	fvalue = substr(fvalue, 1, idx-1)
}

(fname == grep_summary__field) || ("" == grep_summary__field) {
	if (grep_summary__skip == -1){
		update_skip()
	}
}

grep_summary__skip == 0 && NF > 0 {
	print $0
	next
}

{
	grep_summary__fields [fname] = fvalue
}

grep_summary__skip == -1 && NF > 0 {
	accu [count++] = $0
}

NF == 0 {
	if (grep_summary__skip == -1){
		update_skip()
	}
	if (grep_summary__skip == 0){
		print ""
	}

	delete accu
	delete grep_summary__fields
	count = 0
	grep_summary__skip = -1

	assigns = pkgpath = ""
}
