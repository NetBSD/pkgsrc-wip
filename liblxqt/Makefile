# $NetBSD: Makefile,v 1.1 2015/04/11 01:47:19 krytarowski Exp $

DISTNAME=	liblxqt-0.9.0
CATEGORIES=	wip
MASTER_SITES=	http://downloads.lxqt.org/lxqt/0.9.0/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://downloads.lxqt.org/lxqt/0.9.0/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	cmake

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
