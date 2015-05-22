# $NetBSD: Makefile,v 1.2 2015/05/22 23:29:11 krytarowski Exp $

DISTNAME=	lximage-qt-0.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.lxqt.org/lximage-qt/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lxqt.org/
COMMENT=	Image viewer and screenshot tool for the LXQt desktop
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../wip/pcmanfm-qt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
