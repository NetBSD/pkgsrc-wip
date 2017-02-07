# $NetBSD$

DISTNAME=	libimobiledevice-1.2.0
MASTER_SITES=	http://www.libimobiledevice.org/downloads/
CATEGORIES=	misc
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://www.libimobiledevice.org/
COMMENT=	Libraries and tools to communicate with iOS devices
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	gtar
USE_TOOLS+=	aclocal autoconf automake bash pkg-config
USE_LANGUAGES+=	c c++

pre-configure:
	cd ${WRKSRC} && autoreconf

GNU_CONFIGURE=	yes
CONFIG_SHELL=	bash

.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../wip/libusbmuxd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
