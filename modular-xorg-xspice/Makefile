# $NetBSD$

DISTNAME=	xf86-video-qxl-0.1.5
PKGNAME=	modular-xorg-xspice-0.1.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Xspice Xorg server
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"

DEPENDS+=		spice-vdagent-[0-9]*:../../wip/spice-vdagent

CPPFLAGS.SunOS+=	-D__EXTENSIONS__
CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4
CONFIGURE_ARGS+=	--enable-xspice=only
REPLACE_PYTHON+=	scripts/Xspice

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/application.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.46
.include "../../x11/libdrm/buildlink3.mk"
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../sysutils/spice-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
