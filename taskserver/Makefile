# $NetBSD$

DISTNAME=	taskd-1.1.0
CATEGORIES=	net
MASTER_SITES=	http://taskwarrior.org/download/

MAINTAINER=	esg@sdf.org
HOMEPAGE=	http://taskwarrior.org/download/
COMMENT=	Lightweight, secure server providing access to task data
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DTASKD_MAN1DIR=${PREFIX}/${PKGMANDIR}/man1
CMAKE_ARGS+=	-DTASKD_MAN5DIR=${PREFIX}/${PKGMANDIR}/man5

LDFLAGS.SunOS+=	-lsocket -lnsl

REPLACE_SH=	src/taskdctl

.include "../../devel/libuuid/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
