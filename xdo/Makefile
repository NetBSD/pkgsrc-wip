# $NetBSD$

DISTNAME=	xdo-0.5.7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=baskerville/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/baskerville/xdo/
COMMENT=	Small X utility to perform elementary actions on windows
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake

WRKSRC=	${WRKDIR}/xdo-0.5.7

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
