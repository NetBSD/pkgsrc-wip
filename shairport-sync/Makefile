# $NetBSD$

DISTNAME=	shairport-sync-3.3.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mikebrady/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/mikebrady/shairport-sync
COMMENT=	AirPlay audio player with multi-room audio synchronisation capability
LICENSE=	mit # possibly others?

USE_TOOLS+=	autoconf autoreconf automake
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-ao
CONFIGURE_ARGS+=	--with-libdaemon
CONFIGURE_ARGS+=	--with-metadata
CONFIGURE_ARGS+=	--with-pipe
CONFIGURE_ARGS+=	--with-soxr
CONFIGURE_ARGS+=	--with-stdout

CONFIGURE_ARGS+=	--without-configfiles

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || \
    exists(/usr/include/sys/audioio.h)
CONFIGURE_ARGS+=	--with-sun
.endif

.if ${OPSYS} != "Darwin"
CPPFLAGS+=	-DCOMPILE_FOR_LINUX_AND_FREEBSD_AND_CYGWIN_AND_OPENBSD=1
.endif

INSTALLATION_DIRS+=	share/examples/${PKGBASE}

CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/${PKGBASE}.conf \
		${PKG_SYSCONFDIR}/${PKGBASE}.conf

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

post-install:
	${INSTALL_DATA} ${WRKSRC}/scripts/shairport-sync.conf \
	    ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/${PKGBASE}.conf

.include "options.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libsoxr/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/libdaemon/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
