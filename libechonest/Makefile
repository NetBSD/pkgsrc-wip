# $NetBSD$

DISTNAME=	libechonest-2.3.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=lfranchi/}


MAINTAINER=	weabot@protonmail.com
HOMEPAGE=	https://github.com/lfranchi/libechonest
COMMENT=	Libechonest is a collection of C++/Qt classes for The Echo Nest APIs
LICENSE=	gnu-gpl-v2

CMAKE_FLAGS+=	DBUILD_WITH_QT4=ON

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake \
		pkgconf>=0.9.10:../../devel/pkgconf

.include "../../devel/qjson/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
