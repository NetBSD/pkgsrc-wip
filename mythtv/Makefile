# $NetBSD: Makefile,v 1.2 2004/05/11 08:53:48 grantbeattie Exp $
#

DISTNAME=		mythtv-0.11
CATEGORIES=		graphics
MASTER_SITES=		http://www.mythtv.org/mc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.mythtv.org/
COMMENT=		TV/video recorder with many features

USE_BUILDLINK3=		yes

ONLY_FOR_PLATFORM=	Linux-*-*

HAS_CONFIGURE=		YES
USE_GCC_SHLIB=		# defined
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES
USE_X11=		YES

USE_GNU_TOOLS+=		make

QTPREFIX=		${X11PREFIX}/qt3

CONFIGURE_ARGS+=	--prefix=${PREFIX}

# the assembler can't handle the MMX output from gcc3.2.2 on
# Slackware 9, so build without MMX support for now.
CONFIGURE_ARGS+=	--disable-mmx

MAKE_ENV+=		QTPREFIX=${QTPREFIX}
MAKE_ENV+=		QTDIR=${QTPREFIX}

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
.include "../../mk/bsd.pkg.mk"
