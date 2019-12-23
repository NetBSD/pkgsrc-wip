# $NetBSD: Makefile,v 1.2 2019/02/25 14:53:05 taca Exp $

DISTNAME=		mustache-0.99.8
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME:S/mustache/mustache0/}
CATEGORIES=		devel

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://mustache.github.io/
COMMENT=		Logic-less Ruby templates
LICENSE=		mit

RUBYGEM_OPTIONS+=	--format-executable
COMMANDS=		mustache

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for f in ${COMMANDS}; do \
		${TEST} -f $${f}0${RUBY_SUFFIX} || \
			${MV} $${f}${RUBY_SUFFIX} $${f}0${RUBY_SUFFIX}; \
	done
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/mustache.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${RUBY_PKGPREFIX}-mustache0.1
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/mustache.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/${RUBY_PKGPREFIX}-mustache0.5

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
