# $NetBSD$

DISTNAME=	netdata-1.5.0
CATEGORIES=	sysutils

GIT_REPOSITORIES=	netdata
GIT_REPO.netdata=	https://github.com/firehol/netdata.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://my-netdata.io/
COMMENT=	distributed real-time performance and health monitoring
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
