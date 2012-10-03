# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:36 asau Exp $
#

DISTNAME=	137323-libalkimia-4.3.1
PKGNAME=	libalkimia-4.3.1
CATEGORIES=	finance
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://community.kde.org/Alkimia/libalkimia
COMMENT=	Common finance routines for kde4 applications
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
