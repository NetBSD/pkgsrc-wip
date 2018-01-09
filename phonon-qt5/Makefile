# $NetBSD: Makefile,v 1.15 2017/11/30 16:45:05 adam Exp $

DISTNAME=	phonon-4.9.1
PKGNAME=	${DISTNAME:S/-/-qt5-/}

COMMENT=	Multimedia API for KF5

.include "Makefile.common"

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

BUILD_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

.include "../../wip/qt5-qtbase/buildlink3.mk"
.include "../../wip/qt5-qttools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
