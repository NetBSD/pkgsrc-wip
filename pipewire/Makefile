# $NetBSD$

DISTNAME=	pipewire-1.0.7
CATEGORIES=	audio
MASTER_SITES=	https://gitlab.freedesktop.org/pipewire/pipewire/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pipewire.org/
COMMENT=	Low-latency, graph-based audio processing engine
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
