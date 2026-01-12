# $NetBSD$

DISTNAME=	seatd-0.9.2
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~kennylevinsen/seatd/archive/
DISTFILES=	${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~kennylevinsen/seatd/
COMMENT=	Seat management daemon and library
LICENSE=	mit

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/libseat.pc

MESON_ARGS+=	-Dlibseat-logind=disabled
MESON_ARGS+=	-Dlibseat-builtin=enabled

SPECIAL_PERMS+=	bin/seatd-launch ${SETUID_ROOT_PERMS}

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../mk/bsd.pkg.mk"
