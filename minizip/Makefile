# $NetBSD$

ZLIB_VERSION=   1.2.11
DISTNAME=       minizip-${ZLIB_VERSION}
CATEGORIES=	    devel
MASTER_SITES=   -https://www.zlib.net/zlib-${ZLIB_VERSION}.tar.gz
WRKSRC=         ${WRKDIR}/zlib-${ZLIB_VERSION}/contrib/minizip/

MAINTAINER=	    pkgsrc-users@pkgsrc.org
HOMEPAGE=       https://www.zlib.net/
COMMENT=        Zip and UnZip additionnal library
LICENSE=        zlib

USE_TOOLS+=     autoreconf automake autoreconf
GNU_CONFIGURE=  yes

LANGUAGES=      c

pre-configure:
	cd ${WRKSRC} && autoreconf -i

# url2pkg-marker (please do not remove this line.)
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
