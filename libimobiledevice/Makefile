# $NetBSD$

DISTNAME=	libimobiledevice-1.4.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libimobiledevice/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.libimobiledevice.org/
COMMENT=	Libraries and tools to communicate with iOS devices
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
CONFIG_SHELL=	bash
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake bash pkg-config
USE_LANGUAGES+=	c c++
PY_PATCHPLIST=	yes

pre-configure:
	${ECHO} ${PKGVERSION_NOREV} > ${WRKSRC}/.tarball-version
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/py-cython/tool.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../wip/libtatsu/buildlink3.mk"
.include "../../wip/libusbmuxd/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
