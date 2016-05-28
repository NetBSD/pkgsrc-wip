# $NetBSD: Makefile,v 1.13 2012/10/03 15:10:03 asau Exp $
#

DISTNAME=		mythtv-0.11
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		http://www.mythtv.org/mc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mythtv.org/
COMMENT=		TV/video recorder with many features


ONLY_FOR_PLATFORM=	Linux-*-*


HAS_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

USE_TOOLS+=		gmake

QTPREFIX=		${X11PREFIX}/qt3

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

# the assembler can't handle the MMX output from gcc3.2.2 on
# Slackware 9, so build without MMX support for now.
CONFIGURE_ARGS+=	--disable-mmx

MAKE_ENV+=		QTPREFIX=${QTPREFIX:Q}
MAKE_ENV+=		QTDIR=${QTPREFIX:Q}

# needed to find qmake
PATH:=			${PATH}:${QTPREFIX}/bin

post-patch:
	@${MV} ${WRKSRC}/settings.pro ${WRKSRC}/settings.pro.pre-subst
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/settings.pro.pre-subst > \
		${WRKSRC}/settings.pro

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/mythtv

.include "../../audio/lame/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
