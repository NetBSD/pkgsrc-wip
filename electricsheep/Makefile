# $NetBSD: Makefile,v 1.5 2005/04/11 21:11:48 tvierling Exp $

DISTNAME=		electricsheep-2.5
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
	@${INSTALL_PROGRAM} ${WRKSRC}/electricsheep ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flame/anim-flame ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flame/convert-flame ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flame/hqi-flame ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/flame/pick-flame ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mpeg2dec/src/mpeg2dec_onroot ${PREFIX}/bin
	@${INSTALL} -d -m 0755 ${PREFIX}/share/electricsheep
	@${INSTALL_DATA} ${WRKSRC}/*.tif ${PREFIX}/share/electricsheep

post-patch:
	@${MV} ${WRKSRC}/electricsheep.c ${WRKSRC}/electricsheep.c.orig
	@${SED} < ${WRKSRC}/electricsheep.c.orig > ${WRKSRC}/electricsheep.c \
		-e 's|/usr/local/share|${PREFIX}/share/electricsheep|'

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
