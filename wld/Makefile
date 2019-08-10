# $NetBSD: Makefile,v 1.3 2018/08/22 09:43:57 wiz Exp $

GIT_COMMIT=	dfa8f7981b612fb7d827776b1810f504dd6add10
DISTNAME=	${GIT_COMMIT}
PKGNAME=	wld-0.0.20190810
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/wld/archive/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	wld-${GIT_COMMIT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/wld
COMMENT=	drawing library that targets Wayland
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

WRKSRC=		${WRKDIR}/wld-${GIT_COMMIT}

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

PKGCONFIG_OVERRIDE+=	wld.pc.in

.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../wip/wayland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
