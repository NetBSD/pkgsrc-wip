# $NetBSD$

DISTNAME=	hashcat-6.1.1
CATEGORIES=	security
MASTER_SITES=	https://hashcat.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hashcat.net/
COMMENT=	World's fastest and most advanced password recovery utility
LICENSE=	mit

USE_TOOLS+=	gmake gsed
BUILD_TARGET=	hashcat
MAKE_ENV+=	SHARED=1
MAKE_ENV+=	USE_SYSTEM_ZLIB=1
MAKE_ENV+=	USE_SYSTEM_XXHASH=1

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/include/hashcat/ext_lzma.h.orig

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
