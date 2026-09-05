# $NetBSD$

PKGNAME=	cockatrice-3.0.2

.include "../../wip/cockatrice/common.mk"

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://cockatrice.github.io/
COMMENT=	Virtual tabletop for multiplayer card games
LICENSE=	gnu-gpl-v2

CMAKE_CONFIGURE_ARGS+=	-DWITH_CLIENT=1
CMAKE_CONFIGURE_ARGS+=	-DWITH_DBCONVERTER=1
CMAKE_CONFIGURE_ARGS+=	-DWITH_ORACLE=1
CMAKE_CONFIGURE_ARGS+=	-DWITH_SERVER=0

.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
