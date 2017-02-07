# $NetBSD$

DISTNAME=	ifuse-1.1.3
CATEGORIES=	filesystems
MASTER_SITES=	http://www.libimobiledevice.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	FUSE filesystem to access the contents of iOS devices
HOMEPAGE=	http://www.libimobiledevice.org/
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	aclocal autoconf automake pkg-config

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../wip/libimobiledevice/buildlink3.mk"
.include "../../wip/libusbmuxd/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
