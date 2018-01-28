# $NetBSD$

VERSION=	1.5
MINOR=		.0
DISTNAME=	openh264-${VERSION}${MINOR}
CATEGORIES=	www multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=cisco/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cisco/openh264/
COMMENT=	H.264 encoder/decoder library from Cisco
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++


BUILD_TARGET=		all plugin
PKGCONFIG_OVERRIDE+=	openh264.pc.in

PLIST_SUBST+=	VERSION=${VERSION:Q}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	ARCH=${MACHINE_ARCH}
MAKE_FLAGS+=	HAVE_GMP_API=Yes
CFLAGS+=	-I${BUILDLINK_PREFIX.gmp-api}/include/gmp-api

PLUGIN_DIR=		lib/firefox/gmp-gmpopenh264/${VERSION}
INSTALLATION_DIRS=	${PLUGIN_DIR}

SUBST_CLASSES+=		jsvars
SUBST_STAGE.jsvars=	pre-configure
SUBST_MESSAGE.jsvars=	Fixing mozilla configuration settings
SUBST_FILES.jsvars=	gmpopenh264.js
SUBST_VARS.jsvars=	VERSION
SUBST_VARS.jsvars+=	LASTUPDATE_TIMESTAMP

LASTUPDATE_TIMESTAMP!=	date +%s

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		nasm>=2.07:../../devel/nasm
.endif

post-extract:
	cp ${FILESDIR}/gmpopenh264.js ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/gmpopenh264.info ${DESTDIR}${PREFIX}/${PLUGIN_DIR}
	${INSTALL_DATA} ${WRKSRC}/libgmpopenh264.so.1 ${DESTDIR}${PREFIX}/${PLUGIN_DIR}/libgmpopenh264.so
	${INSTALL_DATA} ${WRKSRC}/gmpopenh264.js ${DESTDIR}${PREFIX}/${PLUGIN_DIR}/gmpopenh264.js

.include "../../multimedia/gmp-api/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
