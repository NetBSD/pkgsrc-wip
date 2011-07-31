# pkg_assignments2pkgpath
pkg_assignments2pkgpath -h 2>&1 |
grep pkg_assignments2pkgpath |
cmp 'pkg_assignments2pkgpath #1' \
'pkg_assignments2pkgpath - makes an ASSIGNMENTS section a part of PKGPATH
usage: pkg_assignments2pkgpath -h\n\
       pkg_assignments2pkgpath [OPTIONS] [files...]
'
