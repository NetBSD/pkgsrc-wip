# $NetBSD: Makefile,v 1.3 2008/07/29 11:02:51 mwdavies Exp $

DISTNAME=	akonadi-1.0.0
CATEGORIES=	mail
MASTER_SITES=	http://download.akonadi-project.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://pim.kde.org/akonadi/
COMMENT=	The KDE PIM Storage Service

#BUILD_MAKE_FLAGS+= VERBOSE=1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../wip/automoc4

USE_DIRS+=	kde4-1.0
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
