# $NetBSD$

GITHUB_PROJECT=	AusweisApp2
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_RELEASE}
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Governikus/}
GITHUB_RELEASE=	1.22.2

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/Governikus/AusweisApp2/
COMMENT=	Authenticate with your German ID or residence permit
LICENSE=	eupl-v1.2

USE_CMAKE=	yes
CMAKE_CONFIGURE_ARGS+=	-DVENDOR=${PKGBASE}
CMAKE_CONFIGURE_ARGS+=	-DFORCE_SOURCE_BUILD=ON

USE_LANGUAGES=	c++

CFLAGS+=	-I${PREFIX}/include/PCSC

.include "../../security/openssl/buildlink3.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../x11/qt5-qtconnectivity/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
