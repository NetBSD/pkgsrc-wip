############################################################
# dewey function
BEGIN {
	__dewey_maxf = 9 # 8(YYYYMMDD) + 1
	for (i=0; i <= 26; ++i){
		# I don't know anything about EBCDIC :-P :-)
		__dewey_char2dotver [sprintf("%c", 97 + i)] = "." i+1
		__dewey_char2dotver [sprintf("%c", 65 + i)] = "." i+1
	}
}

function __dewey_chars (n, c,            s){
	s = ""

	while (n-- > 0){
		s = s c
	}

	return s
}

function __dewey2str (ver,        left,right,sym,num,last){
	ver = "." ver

	gsub(/alpha/, "\072", ver) # A
	gsub(/beta/, "\073", ver)  # B
	gsub(/rc/, "\074", ver)    # C
	gsub(/pre/, "\074", ver)   # C
	gsub(/nb/, "\076", ver)    # Z
	gsub(/pl/, ".", ver)       # .

	if (match(ver, /[qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM]($|\076)/)){
		last = substr(ver, RSTART, 1)
		ver = substr(ver, 1, RSTART-1) \
		      __dewey_char2dotver [last] \
		      substr(ver, RSTART+1)
	}

	gsub(/[.]/, "\075" __dewey_chars(__dewey_maxf, " ") ".", ver) # Y

	while (match(ver, /[\072\073\074\076.][0-9]+/)){
		left  = substr(ver, 1, RSTART-1)
		sym   = substr(ver, RSTART, 1)
		num   = substr(ver, RSTART+1, RLENGTH-1)
		right = substr(ver, RSTART+RLENGTH)

		num = sprintf("%" __dewey_maxf "s", num)

		if (sym == ".")
			ver = left "\075" num right # Y
		else
			ver = left sym num right
	}

	return substr(ver, __dewey_maxf + 2) "\075" # Y
}

function dewey_cmp (ver1, ver2,             s1,s2){
	if (ver1 == ver2){
		return "="
	}

	s1 = __dewey2str(ver1)
	s2 = __dewey2str(ver2)

	if (s1 < s2)
		return "<"
	else if (s1 > s2)
		return ">"
	else
		return "="
}

function dewey_test (ver1, ver2, op,                 tmp){
	tmp = dewey_cmp(ver1, ver2)

	if (tmp ~ /^==?$/ && op ~ /^(==|=|<=|>=)$/){
		return 1
	}else if (tmp == "<" && op ~ /^(<=?|!=)$/){
		return 1
	}else if (tmp == ">" && op ~ /^(>=?|!=)$/){
		return 1
	}

	return 0
}
