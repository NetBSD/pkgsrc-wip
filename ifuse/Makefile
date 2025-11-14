# $NetBSD$

DISTNAME=	ifuse-1.2.0
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=libimobiledevice/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.libimobiledevice.org/
COMMENT=	FUSE filesystem to access the contents of iOS devices
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

.include "../../textproc/libplist/buildlink3.mk"
.include "../../wip/libimobiledevice/buildlink3.mk"
.include "../../wip/libusbmuxd/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
