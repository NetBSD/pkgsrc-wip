# $NetBSD: Makefile,v 1.8 2025/10/23 20:38:50 wiz Exp $

DISTNAME=	libslirp-4.9.1
CATEGORIES=	net
MASTER_SITES=	https://gitlab.freedesktop.org/-/project/2767/uploads/ed8eaeada090f91a640c8e8e01d704bc/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/slirp/libslirp
COMMENT=	User-mode networking library
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/slirp.pc

LDFLAGS.SunOS+=		-lsocket

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
