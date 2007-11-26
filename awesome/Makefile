# $NetBSD: Makefile,v 1.7 2007/11/26 22:59:46 hoka_adam Exp $
#

VERSION=		2.0-rc1
DISTNAME=		awesome-${VERSION}
PKGNAME=		${DISTNAME:S/0-/0/}
PKGREVISION=	1
CATEGORIES=		wm
MASTER_SITES=	http://awesome.naquadah.org/download/

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://awesome.naquadah.org/
COMMENT=		Tiling window manager based on dwm

USE_LANGUAGES=	c99
USE_TOOLS+=		pkg-config

EGDIR=			${PREFIX}/share/examples/awesome
MESSAGE_SUBST+=	EGDIR=${EGDIR}/awesomerc

SUBST_CLASSES+=		man
SUBST_FILES.man=	awesome.1
SUBST_SED.man=		-e 's,VERSION,${VERSION},'
SUBST_STAGE.man=	pre-install

pre-install:
	strip ${WRKDIR}/awesome
	strip ${WRKDIR}/awesome-client

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/awesome ${PREFIX}/bin/awesome
	${INSTALL_PROGRAM} ${WRKSRC}/awesome-client ${PREFIX}/bin/awesome-client
	${INSTALL_MAN} ${WRKSRC}/awesome.1 ${PREFIX}/${PKGMANDIR}/man1/awesome.1

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/awesomerc ${EGDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../wip/confuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
