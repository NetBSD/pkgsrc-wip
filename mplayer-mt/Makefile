# $NetBSD: Makefile,v 1.3 2012/10/03 15:09:58 asau Exp $

PKGNAME=	mplayer-mt-20090720
PKGREVISION=	1
DISTNAME=	mplayer-svn-mt
EXTRACT_SUFX=	.tar.bz2

COMMENT=	Software-only MPEG-1/2/4 video decoder

WRKSRC=		${WRKDIR}/mplayer

.include "Makefile.common"

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer
CONFIGURE_ARGS+=	--extra-cflags="-I ${BUILDLINK_DIR}/include -I ${BUILDLINK_DIR}/include/faad2 -I ${BUILDLINK_DIR}/include/cdparanoia -I ${BUILDLINK_DIR}/include/freetype2"
CONFIGURE_ARGS+=	--extra-libs="-L${BUILDLINK_DIR}/lib -lxvidcore"
CONFIGURE_ARGS+=	--disable-rpath

# Solaris/x86 has Xv, but the header files live in /usr/X11R6, not
# ${X11_BASE}, so we need to also look for headers in this path.
.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "i386"
CPPFLAGS+=		-I/usr/X11R6/include
BUILDLINK_PASSTHRU_DIRS+=	/usr/X11R6/include
.endif

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${DESTDIR}${PREFIX}/bin/mplayer-mt

.include "../../x11/libXt/buildlink3.mk"

.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.if ${X11_TYPE} == "modular"
.include "../../x11/libXvMC/buildlink3.mk"
.endif
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"

.include "../../graphics/MesaLib/buildlink3.mk"

.include "Makefile.depends"

.include "../../mk/bsd.pkg.mk"
