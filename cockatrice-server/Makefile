# $NetBSD$

PKGNAME=	cockatrice-server-2.10.2

.include "../../wip/cockatrice/common.mk"

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://cockatrice.github.io/
COMMENT=	Virtual tabletop for multiplayer card games (server only)
LICENSE=	gnu-gpl-v2

CMAKE_CONFIGURE_ARGS+=	-DWITH_CLIENT=0
CMAKE_CONFIGURE_ARGS+=	-DWITH_DBCONVERTER=0
CMAKE_CONFIGURE_ARGS+=	-DWITH_ORACLE=0
CMAKE_CONFIGURE_ARGS+=	-DWITH_SERVER=1

#.include "../../databases/mysql57-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
