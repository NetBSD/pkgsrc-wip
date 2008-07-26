# $NetBSD: Makefile,v 1.1 2008/07/26 22:06:25 mwdavies Exp $

DISTNAME=	automoc4-0.9.83
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KDE:=../unstable/4.0.83/support/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.kde.org
COMMENT=	???

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
