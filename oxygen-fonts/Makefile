# $NetBSD: Makefile,v 1.3 2016/02/14 04:13:32 markd Exp $

DISTNAME=	oxygen-fonts-5.4.3
CATEGORIES=	fonts kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/5.4.3/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://projects.kde.org/projects/oxygen-fonts
COMMENT=	The Oxygen font family
LICENSE=	gnu-gpl-v3 AND ofl-v1.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_KDE_build

CMAKE_ARGS+=	-DOXYGEN_FONT_INSTALL_DIR=${PREFIX}/share/fonts/X11/TTF

BUILD_DEPENDS+=	extra-cmake-modules>=1.2.0:../../devel/extra-cmake-modules

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build

.include "../../mk/bsd.pkg.mk"
