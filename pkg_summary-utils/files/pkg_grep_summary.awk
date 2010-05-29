#use "has_prefix.awk"
#use "has_suffix.awk"
#use "psu_funcs.awk"

#env "LC_ALL=C"

BEGIN {
	matched = -1 # -1 - unknown, 0 - false, 1 - true
	count              = 0

	multiline ["PLIST"]       = 1
	multiline ["DESCRIPTION"] = 1
	multiline ["DEPENDS"]     = 1
	multiline ["REQUIRES"]    = 1
	multiline ["PROVIDES"]    = 1
	multiline ["CONFLICTS"]   = 1
}

function match_first_word (s, word){
	if (s == word)
		return 1
	else if (!has_prefix(s, word))
		return 0
	else{
		return substr(s, length(word)+1, 1) ~ /^[^A-Za-z0-9]$/
	}
}

function match_last_word (s, word){
	if (s == word)
		return 1
	else if (!has_suffix(s, word))
		return 0
	else
		return substr(s, length(s)-length(word), 1) ~ /^[^A-Za-z0-9]$/
}

function match_word (s, word,                  idx){
	if (s == word)
		return 1

	idx=index(s, word)
	if (!idx)
		return 0

	if (idx > 1 && substr(s, idx-1, 1) ~ /[A-Za-z0-9]$/)
		return 0

	idx += length(word)
	if (idx <= length(s) && substr(s, idx, 1) ~ /[A-Za-z0-9]$/)
		return 0

	return 1
}

function update_skip (){
	if (ic)
		fvalue = tolower(fvalue)

	matched = grep_summary__condition()

	if (matched == 1){
		for (i=0; i < count; ++i){
			print accu [i]
		}

		delete accu
		count = 0
	}else if (matched == 0 && (fname in multiline)){
		matched = -1
	}
}

matched == 0 && NF > 0 {
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

matched == -1 {
	if (grep_summary__field == "PKGBASE"){
		if (fname == "PKGNAME"){
			fname = "PKGBASE"
			fvalue = pkgname2pkgbase(fvalue)
			update_skip()
		}
	}else if (grep_summary__field == "PKGPATHe"){
		if (fname == "ASSIGNMENTS") {
			assigns = fvalue
			check_PKGPATHe()
		}else if (fname == "PKGPATH") {
			pkgpath = fvalue
			check_PKGPATHe()
		}
	}else if (grep_summary__field == "PKGPATH"){
		idx = index(fvalue, ":")
		if (idx > 0)
			fvalue = substr(fvalue, 1, idx-1)
	}

	if (fname == grep_summary__field || "" == grep_summary__field) {
		update_skip()
	}
}

matched == 1 && NF > 0 {
	print $0
	next
}

{
	grep_summary__fields [fname] = fvalue
}

matched == -1 && NF > 0 {
	accu [count++] = $0
}

NF == 0 {
	if (matched == -1 && grep_summary__field == "PKGPATHe"){
		fvalue = pkgpath
		update_skip()
		fvalue = ""
	}
	if (matched == -1){
		update_skip()
	}
	if (matched == 1){
		print ""
	}

	delete accu
	delete grep_summary__fields
	count = 0
	matched = -1

	assigns = pkgpath = ""
}
