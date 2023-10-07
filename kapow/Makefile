# $NetBSD$

DISTNAME=	kapow-0.7.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=BBVA/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kapow.readthedocs.io/
COMMENT=	Kapow! If you can script it, you can HTTP it
LICENSE=	apache-2.0

.include "go-modules.mk"

# Do not install test programs
post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/jaillover
	${RM} ${DESTDIR}${PREFIX}/bin/test

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
