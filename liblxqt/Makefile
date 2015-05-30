# $NetBSD: Makefile,v 1.11 2015/05/30 00:58:39 krytarowski Exp $

DISTNAME=	liblxqt-0.9.0
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/lxqt/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	Core utility library for all LXQt components
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	bsdtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../wip/kwindowsystem/buildlink3.mk"
.include "../../wip/libqtxdg/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
