# $NetBSD: Makefile,v 1.1 2015/05/22 11:21:39 krytarowski Exp $

DISTNAME=	lximage-qt-0.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.lxqt.org/${PKGNAME}/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lxqt.org/
COMMENT=	Image viewer and screenshot tool for the LXQt desktop
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../wip/libfm/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
