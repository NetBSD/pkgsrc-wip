# pkg_src_summary
pkgs="`sed -n 's/^PKGPATH=//p' src_summary.txt`"
pkg_src_summary -f PKGNAME,PKGPATH $pkgs 2>"$tmpfn4" |
tee "$objdir"/summary_full.txt |
normalize_version |
cmp 'pkg_src_summary #1' \
'PKGNAME=dictem-X
PKGPATH=textproc/dictem

PKGNAME=checkperms-X
PKGPATH=sysutils/checkperms

PKGNAME=dict-client-X
PKGPATH=textproc/dict-client

PKGNAME=libmaa-X
PKGPATH=devel/libmaa

PKGNAME=gmake-X
PKGPATH=devel/gmake

PKGNAME=libtool-base-X
PKGPATH=devel/libtool-base

PKGNAME=emacs-X
PKGPATH=editors/emacs

PKGNAME=pkg_summary-utils-X
PKGPATH=wip/pkg_summary-utils

PKGNAME=libungif-X
PKGPATH=graphics/libungif

PKGNAME=tiff-X
PKGPATH=graphics/tiff

PKGNAME=x11-links-X
PKGPATH=pkgtools/x11-links

PKGNAME=perl-X
PKGPATH=lang/perl5

PKGNAME=libltdl-X
PKGPATH=devel/libltdl

PKGNAME=pipestatus-X
PKGPATH=devel/pipestatus

PKGNAME=png-X
PKGPATH=graphics/png

PKGNAME=netcat-X
PKGPATH=net/netcat

PKGNAME=pkg-config-X
PKGPATH=devel/pkg-config

PKGNAME=jpeg-X
PKGPATH=graphics/jpeg

PKGNAME=ap22-vhost-ldap-X
PKGPATH=www/ap22-vhost-ldap

'

grep_pss_stderr (){
    grep -E 'Bad package| ----------' "$@"
}

grep_pss_stderr "$tmpfn4" |
cmp 'pkg_src_summary #1 stderr' \
" ------------------
Bad package wip/distbb, skipped
 ------------------
Bad package wip/pkg_online, skipped
 ------------------
Bad package wip/dict-server, skipped
 ------------------
Bad package wip/pkg_online-server, skipped
 ------------------
Bad package wip/pkg_online-client, skipped
 ------------------
Bad package wip/paexec, skipped
 ------------------
Bad package wip/runawk, skipped
 ------------------
Bad package wip/dict-client, skipped
 ------------------
Bad package wip/awk-pkgsrc-dewey, skipped
 ------------------
Bad package www/ap2-vhost-ldap:PKG_APACHE=apache2, skipped
"

pkg_src_summary -m -fPKGNAME,PKGPATH www/ap2-python |
grep -v DEPENDS |
cmp 'pkg_src_summary #2' \
'ASSIGNMENTS=PKG_APACHE=apache2
PKGNAME=ap2-py27-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PKG_APACHE=apache2,PYTHON_VERSION_REQD=26
PKGNAME=ap2-py26-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PKG_APACHE=apache2,PYTHON_VERSION_REQD=25
PKGNAME=ap2-py25-python-3.3.1
PKGPATH=www/ap2-python

PKGNAME=ap22-py27-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PYTHON_VERSION_REQD=26
PKGNAME=ap22-py26-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=ap22-py25-python-3.3.1
PKGPATH=www/ap2-python

'

pkg_src_summary -m --fields PKGNAME,PKGPATH www/ap2-python:PKG_APACHE=apache2 |
grep -v DEPENDS |
cmp 'pkg_src_summary #3' \
'ASSIGNMENTS=PKG_APACHE=apache2
PKGNAME=ap2-py27-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PKG_APACHE=apache2,PYTHON_VERSION_REQD=26
PKGNAME=ap2-py26-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PKG_APACHE=apache2,PYTHON_VERSION_REQD=25
PKGNAME=ap2-py25-python-3.3.1
PKGPATH=www/ap2-python

'

pkg_src_summary -m --fields PKGNAME,PKGPATH www/ap2-python:PKG_APACHE=apache22 |
grep -v DEPENDS |
cmp 'pkg_src_summary #3.1' \
'PKGNAME=ap22-py27-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PYTHON_VERSION_REQD=26
PKGNAME=ap22-py26-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=ap22-py25-python-3.3.1
PKGPATH=www/ap2-python

'

pkg_src_summary -m --fields='PKGNAME PKGPATH' www/ap2-python:PYTHON_VERSION_REQD=25 |
grep -v DEPENDS |
cmp 'pkg_src_summary #4' \
'ASSIGNMENTS=PYTHON_VERSION_REQD=25,PKG_APACHE=apache2
PKGNAME=ap2-py25-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=ap22-py25-python-3.3.1
PKGPATH=www/ap2-python

'

pkg_src_summary -m --fields='PKGNAME PKGPATH' www/ap2-python:PYTHON_VERSION_REQD=26 |
grep -v DEPENDS |
cmp 'pkg_src_summary #4.1' \
'ASSIGNMENTS=PYTHON_VERSION_REQD=26,PKG_APACHE=apache2
PKGNAME=ap2-py26-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PYTHON_VERSION_REQD=26
PKGNAME=ap22-py26-python-3.3.1
PKGPATH=www/ap2-python

'

pkg_src_summary -m -f'PKGNAME PKGPATH' \
   www/ap2-python:PYTHON_VERSION_REQD=25,PKG_APACHE=apache22 |
grep -v DEPENDS |
cmp 'pkg_src_summary #5' \
'ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=ap22-py25-python-3.3.1
PKGPATH=www/ap2-python

'


normalize_python_deps (){
    awk '
sub(/^DEPENDS=/, "FAKED_PKGPATH= ") {
   for (i=2; i <= NF; ++i){
      if ($i ~ /py/){
         sub(/^[^:]*:([.][.]\/[.][.]\/)?/, "", $i)
         if (i && $i == $(i-1))
            $i = ""
      }else{
         $i = ""
      }
   }
   gsub(/  +/, " ")
}
/^BUILD_DEPENDS=/ {
   next
}
{
   print
}
' "$@"
}

if false; then
pkg_src_summary -Af PKGNAME,PKGPATH \
   graphics/py-cairo:PYTHON_VERSION_REQD=25 |
normalize_python_deps |
pkg_grep_summary -m PKGPATH 'py-Numeric|py-cairo|python|cairo' |
normalize_version |
cmp 'pkg_src_summary #6' \
'ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=py25-cairo-X
PKGPATH=graphics/py-cairo
FAKED_PKGPATH= lang/python25 math/py-Numeric:PYTHON_VERSION_REQD=25 lang/python25 math/py-Numeric:PYTHON_VERSION_REQD=25 

PKGNAME=cairo-X
PKGPATH=graphics/cairo
FAKED_PKGPATH= 

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=py25-Numeric-X
PKGPATH=math/py-Numeric
FAKED_PKGPATH= lang/python25 lang/python25

PKGNAME=python25-X
PKGPATH=lang/python25
FAKED_PKGPATH= 

'
fi

if false; then
pkg_src_summary -A -fPKGNAME,PKGPATH \
   graphics/py-cairo:PYTHON_VERSION_REQD=26 |
normalize_python_deps |
pkg_grep_summary -m PKGPATH 'py-Numeric|py-cairo|python|cairo' |
normalize_version |
cmp 'pkg_src_summary #7' \
'PKGNAME=py26-cairo-X
PKGPATH=graphics/py-cairo
FAKED_PKGPATH= lang/python26 math/py-Numeric math/py-Numeric 

PKGNAME=py26-Numeric-X
PKGPATH=math/py-Numeric
FAKED_PKGPATH= lang/python26

PKGNAME=cairo-X
PKGPATH=graphics/cairo
FAKED_PKGPATH= 

PKGNAME=python26-X
PKGPATH=lang/python26
FAKED_PKGPATH= 

'
fi

if false; then
pkg_src_summary -mA -f PKGNAME,PKGPATH graphics/py-cairo |
normalize_python_deps |
pkg_grep_summary -m PKGPATH 'py-Numeric|py-cairo|python|cairo' |
normalize_version |
cmp 'pkg_src_summary #8' \
'PKGNAME=py26-cairo-X
PKGPATH=graphics/py-cairo
FAKED_PKGPATH= lang/python26 math/py-Numeric math/py-Numeric 

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=py25-cairo-X
PKGPATH=graphics/py-cairo
FAKED_PKGPATH= lang/python25 math/py-Numeric:PYTHON_VERSION_REQD=25 lang/python25 math/py-Numeric:PYTHON_VERSION_REQD=25 

PKGNAME=cairo-X
PKGPATH=graphics/cairo
FAKED_PKGPATH= 

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=py25-Numeric-X
PKGPATH=math/py-Numeric
FAKED_PKGPATH= lang/python25 lang/python25

PKGNAME=py26-Numeric-X
PKGPATH=math/py-Numeric
FAKED_PKGPATH= lang/python26

PKGNAME=python25-X
PKGPATH=lang/python25
FAKED_PKGPATH= 

PKGNAME=python26-X
PKGPATH=lang/python26
FAKED_PKGPATH= 

'
fi

pkg_src_summary -f PKGNAME --add-fields 'PKGPATH MAINTAINER' x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #9' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=cheusov@NetBSD.org

'

pkg_src_summary --fields=PKGNAME -a 'PKGPATH MAINTAINER' x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #10' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=cheusov@NetBSD.org

'

pkg_src_summary -fPKGNAME -aPKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #11' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=cheusov@NetBSD.org

'

pkg_src_summary -fPKGNAME --add-fields=PKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #12' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=cheusov@NetBSD.org

'



# pkg_src_summary
pkg_src_summary -f PKGNAME,PKGPATH,COMMENT --rem-fields 'PKGPATH MAINTAINER' x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #13' \
'PKGNAME=xxkb-X
COMMENT=XXKB - switches and indicates a current keyboard layout

'

pkg_src_summary -f PKGNAME,PKGPATH,COMMENT -r 'PKGPATH MAINTAINER' x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #14' \
'PKGNAME=xxkb-X
COMMENT=XXKB - switches and indicates a current keyboard layout

'

pkg_src_summary -f PKGNAME,PKGPATH,COMMENT -rPKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #15' \
'PKGNAME=xxkb-X
COMMENT=XXKB - switches and indicates a current keyboard layout

'

pkg_src_summary -f PKGNAME,PKGPATH,COMMENT --rem-fields=PKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #16' \
'PKGNAME=xxkb-X
COMMENT=XXKB - switches and indicates a current keyboard layout

'

hide_distfile_size (){
    sed 's/:[0-9]*/:NNN/g' "$@"
}

pkg_src_summary -f PKGNAME,PKGPATH,ALLDISTFILES x11/xxkb |
hide_distfile_size | normalize_version |
cmp 'pkg_src_summary #17' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
ALLDISTFILES=xxkb-1.11-src.tar.gz:NNN 

'

pkg_src_summary -f PKGNAME,PKGPATH,BUILD_DEPENDS -b x11/xxkb |
awk '/^BUILD_DEPENDS=.*digest/ {print "ok"}
     /^BOOTSTRAP_DEPENDS=/ {print "bad"} ' |
cmp 'pkg_src_summary #18' \
'ok
'

pkg_src_summary -f PKGNAME,PKGPATH,ALLDISTFILES devel/bmake |
hide_distfile_size | normalize_version |
cmp 'pkg_src_summary #19' \
'PKGNAME=bmake-X
PKGPATH=devel/bmake

'

