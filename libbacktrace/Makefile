# $NetBSD$

GITHUB_PROJECT=	libbacktrace
GITHUB_TAG=	refs/heads/master
DISTNAME=	master
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ianlancetaylor/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ianlancetaylor/libbacktrace/
COMMENT=	C library  be linked into a C/C++ program for symbolic backtraces
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/libbacktrace-master
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
