# $NetBSD$

GITHUB_PROJECT=	dlt-daemon
DISTNAME=	v2.16.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=GENIVI/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/GENIVI/dlt-daemon/
COMMENT=	GENIVI Diagnostic Log and Trace
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/dlt-daemon-2.16.0
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	automotive-dlt-c++.pc.in
PKGCONFIG_OVERRIDE+=	automotive-dlt.pc.in

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
