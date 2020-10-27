# $NetBSD$

DISTNAME=	pinentry-dmenu-0.2.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=ritze/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ritze/pinentry-dmenu/
COMMENT=	A pinentry program with the charm of dmenu
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

PKG_VERSION=	\"0.1\"
PKG_BUGREPORT=	\"https:\/\/github.com\/ritze\/pinentry-dmenu\"

C_FLAGS=	`pkg-config --cflags x11 xinerama freetype2` \
		-D_NETBSD_SOURCE -D_DEFAULT_SOURCE -D_POSIX_C_SOURCE=200809L \
		-DVERSION=${PKG_VERSION} \
		-DPACKAGE_VERSION=${PKG_VERSION} \
		-DPACKAGE_BUGREPORT=${PKG_BUGREPORT}
LD_FLAGS=	`pkg-config --libs x11 xinerama freetype2 xft`

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	CFLAGS=${C_FLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LD_FLAGS:Q}

.include "../../security/gpgme/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
