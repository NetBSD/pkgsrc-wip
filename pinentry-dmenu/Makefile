# $NetBSD$

DISTNAME=	pinentry-dmenu-0.2.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=ritze/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ritze/pinentry-dmenu/
COMMENT=	A pinentry program with the charm of dmenu
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

# Rewrite the config.mk rules.
PKG_VERSION=	${TOOLS_PATH.make} -f ${WRKSRC}/config.mk -V VERSION
PKG_BUGREPORT=	${TOOLS_PATH.make} -f ${WRKSRC}/config.mk -V BUGREPORT
PKG_DEPS=	x11 xinerama freetype2 xft gpgme libconfig libassuan

C_FLAGS=	`${TOOLS_PATH.pkg-config} --cflags ${PKG_DEPS}` \
		-DHAVE_MLOCK -DHAVE_MMAP -DHAVE_GETPAGESIZE \
		-D_NETBSD_SOURCE -D_DEFAULT_SOURCE -D_POSIX_C_SOURCE=200809L \
		-DVERSION=\"${PKG_VERSION:sh}\" \
		-DPACKAGE_VERSION=\"${PKG_VERSION:sh}\" \
		-DPACKAGE_BUGREPORT=\"${PKG_BUGREPORT:sh}\"
LD_FLAGS=	${LDFLAGS} `${TOOLS_PATH.pkg-config} --libs ${PKG_DEPS}`

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	CFLAGS=${C_FLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LD_FLAGS:Q}

.include "../../security/gpgme/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
