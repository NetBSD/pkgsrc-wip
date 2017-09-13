# $NetBSD$

GCC7_DIST_VERSION=	7.2.0

DISTNAME=	gcc-${GCC7_DIST_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC7_DIST_VERSION}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	GNU GCC helper utilities
LICENSE=	gnu-gpl-v3

NO_BUILD=	yes

INSTALL_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/mklog bin/

.include "../../mk/bsd.pkg.mk"
