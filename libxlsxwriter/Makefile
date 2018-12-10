# $NetBSD$

DISTNAME=	libxlsxwriter-0.8.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmcnamara/}
GITHUB_TAG=	RELEASE_${PKGVERSION}

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	https://libxlsxwriter.github.io/
COMMENT=	C library for creating Microsoft Excel files
LICENSE=	2-clause-bsd AND original-bsd AND zlib AND mpl-2.0

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

MAKE_FLAGS+=	V=1
MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
