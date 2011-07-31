# pkg_list_all_pkgs
env  pkg_list_all_pkgs |
awk '
END {
    if (NR > 7000) {
        print "XXXX"
    }else{
        print "failure"
    }
}' |
cmp 'pkg_list_all_pkgs #1' \
'XXXX
'
