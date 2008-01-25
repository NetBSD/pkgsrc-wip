# $NetBSD: Makefile,v 1.1.1.1 2008/01/25 21:16:15 guigui2 Exp $
#

DISTNAME=	QLandkarte.2007.12.22
PKGNAME=	QLandkarte-0.6.0

CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkarte/}

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://qlandkarte.sourceforge.net/
COMMENT=	QLandkarte is a Garmin GPS data visualization and managing tool

WRKSRC=		${WRKDIR}/QLandkarte
USE_LANGUAGES=	c++
USE_LIBTOOL=	yes

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_MESSAGE.fix=	Fixing hardcoded paths
SUBST_FILES.fix=	common
SUBST_SED.fix=		-e "s,\\/usr\\/lib\\/qlandkarte,${PREFIX}\\/lib\\/QLandkarte,g"

SUBST_CLASSES+=		fix2
SUBST_STAGE.fix2=	post-patch
SUBST_MESSAGE.fix2=	Fixing hardcoded paths
SUBST_FILES.fix2=	src/src.pro
SUBST_SED.fix2=		-e "s,\\/usr,${PREFIX},g"

SUBST_CLASSES+=         fix3
SUBST_STAGE.fix3=       post-patch
SUBST_MESSAGE.fix3=     Fixing hardcoded paths
SUBST_FILES.fix3=       src/src.pro
SUBST_SED.fix3=         -e "s,\\../bin,\\../src,g"

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake -unix PREFIX=${PREFIX} QLandkarte.pro

#do-install:
#	${INSTALL_SCRIPT} ${WRKSRC}/bin/QLandkarte ${PREFIX}/bin


.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
