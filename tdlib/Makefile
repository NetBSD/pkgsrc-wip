# $NetBSD$

DISTNAME=	tdlib-1.6.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=tdlib/}
GITHUB_PROJECT=	td
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://core.telegram.org/tdlib
COMMENT=	Cross-platform library for building Telegram clients
LICENSE=	boost-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
