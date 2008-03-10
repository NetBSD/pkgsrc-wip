# $NetBSD: Makefile,v 1.11 2008/03/10 20:54:45 asau Exp $

DISTNAME=	bsfilter-1.0.15
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=bsfilter/21887/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ura@jp.netbsd.org
HOMEPAGE=	http://bsfilter.org/index-e.html
COMMENT=	Bayesian spam filter written in Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION}:../../databases/ruby-gdbm

NO_BUILD=	yes
REPLACE_RUBY=	bsfilter/bsfilter

PKG_DESTDIR_SUPPORT=	user-destdir

EXAMPLESDIR=	${PREFIX}/share/examples/bsfilter

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsfilter/bsfilter ${DESDIR}${PREFIX}/bin/bsfilter
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLESDIR}
.for f in bsfilter.conf.sample dot-qmail.sample
	${INSTALL_DATA} ${FILESDIR}/${f} ${DESTDIR}${EXAMPLESDIR}
.endfor
.for d in mda/maildrop mda/procmail mua/mew3 mua/mew4
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLESDIR}/${d}
	${FIND} ${WRKSRC}/${d} -type f -print |			\
        while read f; do					\
                ${INSTALL_DATA} $$f ${DESTDIR}${EXAMPLESDIR}/${d};	\
        done
.endfor

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
