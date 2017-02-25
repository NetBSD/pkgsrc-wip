# $NetBSD$

DISTNAME=	netdata-1.5.0
CATEGORIES=	sysutils

GIT_REPOSITORIES=	netdata
GIT_REPO.netdata=	git://github.com/firehol/netdata.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://my-netdata.io/
COMMENT=	distributed real-time performance and health monitoring
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config

.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
