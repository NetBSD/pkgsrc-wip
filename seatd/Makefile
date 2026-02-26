# $NetBSD$

DISTNAME=	seatd-0.9.2
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~kennylevinsen/seatd/archive/

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~kennylevinsen/seatd/
COMMENT=	Seat management daemon and library
LICENSE=	mit

TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/libseat.pc

MESON_ARGS+=	-Dlibseat-logind=disabled
MESON_ARGS+=	-Dlibseat-builtin=enabled

SPECIAL_PERMS+=	bin/seatd-launch ${SETUID_ROOT_PERMS}

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../mk/bsd.pkg.mk"
