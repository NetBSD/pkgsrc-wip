# $NetBSD: Makefile,v 1.6 2025/02/22 19:37:36 rillig Exp $

# Form upstream: nightlies are the recommended builds, and the only
# ones we provide support for. Anybody using an outdated version of
# FBNeo is strongly advised to update to the latest nightly.
VERSION=	1.0.0.03 # Reported by the software
DISTNAME=	fbneo-latest-${VERSION}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=finalburnneo/}
GITHUB_PROJECT=	FBNeo
GITHUB_TAG=	8127c5e30a6d559ecc096e0ca510bf9cbe5dc92d

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/finalburnneo/FBNeo
COMMENT=	FinalBurn Neo - the arcade game emulator (SDL2 version)
LICENSE=	fbalpha-license

USE_TOOLS+=	gmake perl
MAKE_FILE=	makefile

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

FORCE_CXX_STD+=	gnu++98

BUILD_TARGET=	sdl2

MAKE_FLAGS+=	RELEASEBUILD=1
MAKE_FLAGS+=	INCLUDE_7Z_SUPPORT=1
MAKE_FLAGS+=	PERL=1

REPLACE_PERL+=	src/dep/scripts/*.pl

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "little"
MAKE_FLAGS+=	LSB_FIRST=1
.endif

LDFLAGS+=	-lz

MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fbneo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/fbneo.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/projectfiles/xcode/Emulator/Assets.xcassets/AppIcon.appiconset/icon_128.png \
		${DESTDIR}${PREFIX}/share/pixmaps/fbneo.png

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
