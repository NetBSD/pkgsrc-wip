# $NetBSD: Makefile,v 1.1 2015/04/25 21:58:17 ahp-nils Exp $

DISTNAME=	mustache-1.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://mustache.github.io/
COMMENT=	Logic-less Ruby templates
LICENSE=	mit

RUBY_VERSION_SUPPORTED=		21

INSTALLATION_DIRS+=		${PKGMANDIR}/man1/ ${PKGMANDIR}/man5/

post-install:
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/mustache.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mustache.1
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/mustache.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/mustache.5

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
