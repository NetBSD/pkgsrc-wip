# $NetBSD: Makefile,v 1.7 2012/11/23 22:33:39 othyro Exp $
#

DISTNAME=	guitone-0.8.99.0
PKGREVISION=	2
CATEGORIES=	devel
#MASTER_SITES=	http://guitone.thomaskeller.biz/releases/0.8/
# snapshot
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/bjs/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://guitone.thomaskeller.biz/
COMMENT=	Graphical Monotone VCS Tool

###
### XXX A Darwin build needs special handling; feel free to add
###	Darwin support should the mood strike you.
###
NOT_FOR_PLATFORM=	Darwin-*-*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} 		\
		${QTDIR}/bin/lrelease guitone.pro && 	\
		${QTDIR}/bin/qmake -config release 	\
			-unix PREFIX=${PREFIX} guitone.pro

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_PROGRAM} ${WRKSRC}/bin/guitone \
		${DESTDIR}${PREFIX}/bin/guitone
	${INSTALL_DATA} ${WRKSRC}/res/icons/guitone.png \
		${DESTDIR}${PREFIX}/share/pixmaps/guitone.png

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
