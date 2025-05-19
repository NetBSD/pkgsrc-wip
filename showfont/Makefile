# $NetBSD$

DISTNAME=	showfont-1.0.7
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Displays font data from an X font server
LICENSE=	x11 # XXX and others

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/libFS/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
