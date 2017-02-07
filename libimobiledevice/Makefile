# $NetBSD$

DISTNAME=	libimobiledevice-1.2.0
MASTER_SITES=	https://cgit.libimobiledevice.org/libimobiledevice.git/snapshot/
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	misc

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://www.libimobiledevice.org/
COMMENT=	Libraries and tools to communicate with iOS devices
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	gtar
USE_TOOLS+=	aclocal autoheader automake autoconf libtoolize bash pkg-config
USE_LANGUAGES+=	c c++

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ./autogen.sh

GNU_CONFIGURE=	yes
CONFIG_SHELL=	bash

.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../wip/libusbmuxd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
