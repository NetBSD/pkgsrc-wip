# $NetBSD: Makefile,v 1.9 2007/01/13 18:38:51 ishit Exp $

DISTNAME=	bsfilter-1.0.12
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=bsfilter/18693/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ura@jp.netbsd.org
HOMEPAGE=	http://bsfilter.org/index-e.html
COMMENT=	Bayesian spam filter written in Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION}:../../databases/ruby-gdbm

NO_BUILD=	yes
REPLACE_RUBY=	bsfilter/bsfilter

EXAMPLESDIR=	${PREFIX}/share/examples/bsfilter

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsfilter/bsfilter ${PREFIX}/bin/bsfilter
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for f in bsfilter.conf.sample dot-qmail.sample
	${INSTALL_DATA} ${FILESDIR}/${f} ${EXAMPLESDIR}
.endfor
.for d in mda/maildrop mda/procmail mua/mew3 mua/mew4
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}/${d}
	${FIND} ${WRKSRC}/${d} -type f -print |			\
        while read f; do					\
                ${INSTALL_DATA} $$f ${EXAMPLESDIR}/${d};	\
        done
.endfor

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
