# $NetBSD$

VERS=			1.47.2
PKGNAME=		doomlegacy-${VERS}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=doomlegacy/}
DISTNAME=		${PKGNAME:S/-/_/}_source
DISTFILES=		${DEFAULT_DISTFILES} doomlegacy_${VERS}_common.zip
EXTRACT_SUFX=		.tar.bz2


MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		http://doomlegacy.sourceforge.net/
COMMENT=		The legacy of Doom
LICENSE=		gnu-gpl-v2

# Tested on GNU/Linux and NetBSD
# Source has support for the other listed OS too (may need additional work)
ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-* \
			NetBSD-*-* OpenBSD-*-* SunOS-*-*

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
MAKE_FLAGS+=		OS=FREEBSD
.elif ${OPSYS} == "NetBSD"
MAKE_FLAGS+=		OS=NETBSD
.elif ${OPSYS} == "Darwin"
MAKE_FLAGS+=		OS=MAC
.else
# All other Unix variants (should work for GNU/Linux, OpenBSD and SunOS)
MAKE_FLAGS+=		OS=LINUX
.endif
MAKE_FLAGS+=		HAVE_MIXER=1 DEBUG=1

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=		-D__BIG_ENDIAN__=1
.endif

INSTALLATION_DIRS=	bin share/doc/doomlegacy share/doomlegacy

do-install:
	cd ${WRKSRC} &&							\
		${INSTALL_PROGRAM} bin/doomlegacy			\
			${DESTDIR}${PREFIX}/bin;			\
		${INSTALL_DATA} docs/legacy.css docs/whatsnew.html	\
			${DESTDIR}${PREFIX}/share/doc/doomlegacy;	\
	cd ${WRKDIR}/doomlegacy_${VERS} &&				\
		${INSTALL_DATA} legacy.wad				\
			${DESTDIR}${PREFIX}/share/doomlegacy/legacy.wad

BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.7
.include "../../audio/SDL_mixer/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL+=		SDL>=1.2.10
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
