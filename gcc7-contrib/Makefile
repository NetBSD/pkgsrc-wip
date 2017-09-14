# $NetBSD$

GCC7_DIST_VERSION=	7.2.0

DISTNAME=	gcc-${GCC7_DIST_VERSION}
PKGNAME=	gcc7-contrib-${GCC7_DIST_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC7_DIST_VERSION}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	GNU GCC helper utilities
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	perl

REPLACE_PERL+=	contrib/mklog

GCC_PKGNAME=		gcc${GCC7_DIST_VERSION:R:R}
GCC_SUBPREFIX=		${GCC_PKGNAME}-contrib
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}

NO_BUILD=	yes

INSTALLATION_DIRS+=	${GCC_PREFIX:Q}/bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/mklog ${DESTDIR}${GCC_PREFIX:Q}/bin

.include "../../mk/bsd.pkg.mk"
