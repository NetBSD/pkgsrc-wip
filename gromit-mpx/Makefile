# $NetBSD$

DISTNAME=	gromit-mpx-1.7.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=bk138/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bk138/gromit-mpx/
COMMENT=	X11 and Wayland on-screen annotation tool
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

USE_PKGLOCALEDIR=	yes

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
