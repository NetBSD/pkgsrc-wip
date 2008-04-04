# $NetBSD: Makefile,v 1.6 2008/04/04 14:03:48 hoka_adam Exp $

DISTNAME=	openttd-0.6.0-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openttd/}

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.openttd.com/
COMMENT=	Open source clone of Transport Tycoon Deluxe
EXTRACT_SUFX=	.tar.bz2

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix-dir=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--binary-dir=bin
CONFIGURE_ARGS+=	--data-dir=share/openttd

USE_DIRS+=		xdg-1.1

DATA_DIR=	${DESTDIR}${PREFIX}/share/openttd

# disable custom assert for Mac OS X -- Check if its still required. -Adam
# CFLAGS+=	-DNDEBUG=1

WRKSRC=		${WRKDIR}/${DISTNAME:S:-source::}

.include "options.mk"

post-install:
.if !empty(PKG_OPTIONS:Mttd-data)
	${RUN} for f in ${DATAFILES}; do \
	  ${INSTALL_DATA} ${WRKDIR}/$$f ${DATA_DIR}/data; done
	${RUN} for f in ${GMFILES}; do \
	  ${INSTALL_DATA} ${WRKDIR}/$$f ${DATA_DIR}/gm; done
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
