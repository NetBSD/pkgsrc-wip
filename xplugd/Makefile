# $NetBSD$

DISTNAME=	xplugd-1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=troglobit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/troglobit/xplugd/
COMMENT=	Monitor, keyboard, and mouse plug/unplug helper for X
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake pkg-config

USE_LANGUAGES=	c99

# FIXME: should be properly fixed via configure/Makefile
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# for alloca and daemon

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
