# $NetBSD$

DISTNAME=	neatvnc-1.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=any1/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/any1/neatvnc/
COMMENT=	Liberally licensed VNC server library with a clean interface
LICENSE=	isc

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/neatvnc.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/meson/build.mk"
.include "../../devel/aml/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
