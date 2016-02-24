# $NetBSD$

DISTNAME=	Catch-1.3.4
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=philsquared/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=philsquared/Catch/}
COMMENT=	C++-native, framework for unit-tests, TDD and BDD
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/${DISTNAME}

NO_BUILD=	yes

AUTO_MKDIRS=	yes

do-install:
	${RUN} ${INSTALL_DATA} ${WRKSRC}/single_include/catch.hpp \
		${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
