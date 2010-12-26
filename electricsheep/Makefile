# $NetBSD: Makefile,v 1.11 2010/12/26 05:01:21 davesainty Exp $

DISTNAME=		electricsheep-2.6.8
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		http://electricsheep.org/

MAINTAINER=		dyeske@yahoo.com
HOMEPAGE=		http://electricsheep.org/
COMMENT=		Distributed fractal flame screensaver

DEPENDS+=		xli-[0-9]*:../../graphics/xli
DEPENDS+=		curl>=7.12.1:../../www/curl

USE_X11BASE=		YES
GNU_CONFIGURE=		YES

do-install:
	${INSTALL_MAN} ${WRKSRC}/electricsheep.man ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/electricsheep.1
	${INSTALL_PROGRAM} ${WRKSRC}/electricsheep ${DESTDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/electricsheep-voter ${DESTDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flam3/flam3-animate ${DESTDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flam3/flam3-convert ${DESTDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flam3/flam3-genome ${DESTDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flam3/flam3-render ${DESTDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg2dec/src/mpeg2dec_onroot ${DESTDIR}/${PREFIX}/bin
	${INSTALL} -d -m 0755 ${DESTDIR}/${PREFIX}/share/electricsheep
	${INSTALL_DATA} ${WRKSRC}/electricsheep-*.png ${DESTDIR}/${PREFIX}/share/electricsheep
	${INSTALL} -d -m 0755 ${DESTDIR}/${PREFIX}/libexec/xscreensaver/config
	${INSTALL_DATA} ${WRKSRC}/electricsheep.xml ${DESTDIR}/${PREFIX}/libexec/xscreensaver/config

post-patch:
	${MV} ${WRKSRC}/electricsheep.c ${WRKSRC}/electricsheep.c.orig
	${SED} < ${WRKSRC}/electricsheep.c.orig > ${WRKSRC}/electricsheep.c \
		-e 's|/usr/local/share|${DESTDIR}/${PREFIX}/share/electricsheep|'

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
