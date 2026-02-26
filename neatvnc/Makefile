# $NetBSD$

DISTNAME=	neatvnc-0.9.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=any1/}
# too old, needs aml0, not aml1
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	8c646d0ecc3edadb5677c639b40ed2f9eb7e1033

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/any1/neatvnc/
COMMENT=	Liberally licensed VNC server library with a clean interface
LICENSE=	isc

WRKSRC=	${WRKDIR}/neatvnc-8c646d0ecc3edadb5677c639b40ed2f9eb7e1033

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/neatvnc.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/meson/build.mk"
.include "../../wip/aml/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
