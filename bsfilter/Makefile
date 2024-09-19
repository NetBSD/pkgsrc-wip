# $NetBSD: Makefile,v 1.16 2015/03/07 18:25:08 ishit Exp $

DISTNAME=	bsfilter-1.0.19
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=bsfilter/59804/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ura@jp.netbsd.org
HOMEPAGE=	http://sourceforge.jp/projects/bsfilter/
COMMENT=	Bayesian spam filter written in Ruby
LICENSE=	gnu-gpl-v2

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	${RUBY_PKGPREFIX}-gdbm>=0:../../databases/ruby-gdbm
DEPENDS+=	${RUBY_PKGPREFIX}-qdbm>=0:../../databases/ruby-qdbm
DEPENDS+=	${RUBY_PKGPREFIX}-mecab>=0:../../textproc/ruby-mecab
DEPENDS+=	${RUBY_PKGPREFIX}-kakasi>=1.0.2:../../wip/ruby-kakasi
#DEPENDS+=	${RUBY_PKGPREFIX}-chasen>=0:../../wip/ruby-chasen

RUBY_VERSION_SUPPORTED=	21	# xxx untested

NO_BUILD=	yes
REPLACE_RUBY=	bsfilter/bsfilter

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

.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
