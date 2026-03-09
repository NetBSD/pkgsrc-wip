# $NetBSD$

DISTNAME=		kanshi-1.9.0
CATEGORIES=		x11
MASTER_SITE_GITLAB=	https://gitlab.freedesktop.org/
MASTER_SITES=		${MASTER_SITE_GITLAB:=emersion/}
GITLAB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		kikadf.01@gmail.com
HOMEPAGE=		https://gitlab.freedesktop.org/emersion/kanshi
COMMENT=		Dynamic display configuration for Wayland
LICENSE=		mit

USE_TOOLS+=		pkg-config
WRKSRC=			${WRKDIR}/kanshi-${GITLAB_TAG}

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../wip/libscfg/buildlink3.mk"
.include "../../wip/vali/buildlink3.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../mk/bsd.pkg.mk"
