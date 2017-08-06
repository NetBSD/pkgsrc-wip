# $NetBSD$

DISTNAME=	libretro-mame2014-20170805
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://wiki.libretro.com/index.php?title=MAME_2014
COMMENT=	Libretro core based on the Multiple Arcade Machine Emulator (v0.159)
LICENSE=	no-commercial-use

GITHUB_PROJECT=	mame2014-libretro
GITHUB_TAG=	0d8726c9df1e7d20d13f84b31e9b361170806d51

EXTRACT_USING=	bsdtar
USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CFLAGS+=	-DSDLMAME_LINUX
.elif ${OPSYS} == "NetBSD"
CFLAGS+=	-DSDLMAME_NETBSD -DSDLMAME_BSD
.elif ${OPSYS} == "Haiku"
CFLAGS+=	-DSDLMAME_HAIKU
.else
CFLAGS+=	-DSDLMAME_BSD
.endif

.if ${OPSYS} != "Linux"
CFLAGS+=	-DNO_AFFINITY_NP
.endif

.if !empty(MACHINE_ARCH:M*arm*)
CFLAGS+=	-DSDLMAME_ARM
.endif

PYTHON_FOR_BUILD_ONLY=	yes

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mame2014_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mame2014_libretro.so

.include "../../audio/flac/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
