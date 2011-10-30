# $NetBSD: Makefile,v 1.14 2011/10/30 15:34:29 ishit Exp $

DISTNAME=	bsfilter-1.0.17
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=bsfilter/49795/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ura@jp.netbsd.org
HOMEPAGE=	http://sourceforge.jp/projects/bsfilter/
COMMENT=	Bayesian spam filter written in Ruby
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION}:../../databases/ruby-gdbm

RUBY_VERSION_SUPPORTED=	18

NO_BUILD=	yes
REPLACE_RUBY=	bsfilter/bsfilter

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin \
			share/examples/bsfilter/mda/maildrop \
			share/examples/bsfilter/mda/procmail \
			share/examples/bsfilter/mua/mew3 \
			share/examples/bsfilter/mua/mew4

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsfilter/bsfilter ${DESTDIR}${PREFIX}/bin
.for f in bsfilter.conf.sample dot-qmail.sample
	${INSTALL_DATA} ${FILESDIR}/${f} ${DESTDIR}${PREFIX}/share/examples/bsfilter
.endfor
.for d in mda/maildrop mda/procmail mua/mew3 mua/mew4
	${FIND} ${WRKSRC}/${d} -type f -print |			\
        while read f; do					\
                ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/examples/bsfilter/${d}; \
        done
.endfor

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
