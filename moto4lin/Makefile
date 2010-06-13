# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:11 thomasklausner Exp $
#

DISTNAME=		moto4lin-0.3
PKGREVISION=		2
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=moto4lin/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://moto4lin.sourceforge.net/
COMMENT=		Filemanager and seem editor for Motorola P2k phones

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake

pre-build:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moto_ui/moto4lin ${PREFIX}/bin

.include "../../devel/libusb/buildlink3.mk"
.include "../../wip/p2kmoto/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
PATH:=			${QTDIR}/bin:${PATH}
