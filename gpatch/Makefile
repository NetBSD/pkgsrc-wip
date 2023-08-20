# $NetBSD$

DISTNAME=	patch-2.7.6
PKGNAME=	g${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://ftp.gnu.org/gnu/patch/

MAINTAINER=	nishi@nishi.boats
HOMEPAGE=	https://savannah.gnu.org/projects/patch/
COMMENT=	GNU Patch
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

DEPENDS+=	autoconf>=0:../../devel/autoconf

do-configure:
	cd ${WRKSRC} && ./configure --program-prefix=g --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
