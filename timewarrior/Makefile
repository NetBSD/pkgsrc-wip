# $NetBSD$

DISTNAME=	timew-1.0.0.beta1
PKGNAME=	${DISTNAME:S/timew/timewarrior/}
CATEGORIES=	time
MASTER_SITES=	https://taskwarrior.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://taskwarrior.org/
COMMENT=	Command-line time tracking application
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# C++11 required
GCC_REQD+=	4.8

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CMAKE_ARGS+=	-DTIMEW_MAN1DIR=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
