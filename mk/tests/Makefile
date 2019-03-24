# $NetBSD$

TESTS=	   cvs-show-all    cvs-single    cvs-checkout_date    cvs-multi
TESTS+=	fossil-show-all fossil-single fossil-checkout_date fossil-multi
TESTS+=	   git-show-all    git-single    git-checkout_date    git-multi
TESTS+=	    hg-show-all     hg-single     hg-checkout_date     hg-multi
TESTS+=	   svn-show-all    svn-single    svn-checkout_date    svn-multi
TESTS+=	zzz-copy-paste

test: .PHONY
.for test in ${TESTS}
	${SH:U/bin/sh} ./${test}
.endfor
