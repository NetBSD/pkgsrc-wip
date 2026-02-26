# $NetBSD$

DISTNAME=	wayvnc-0.9.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=any1/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
# 0.9.1 is so old, it needs aml0, not aml1
GITHUB_TAG=	7ee86054c680b3429137069712e38fcba61ebae7

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/any1/wayvnc/
COMMENT=	VNC server for wlroots based Wayland compositors
LICENSE=	isc

WRKSRC=		${WRKDIR}/wayvnc-7ee86054c680b3429137069712e38fcba61ebae7

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../wip/aml/buildlink3.mk"
.include "../../wip/input-headers/buildlink3.mk"
.include "../../wip/neatvnc/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
