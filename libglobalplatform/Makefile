# $NetBSD: Makefile,v 1.1 2014/02/27 00:00:25 r-hansen Exp $

DISTNAME=	globalplatform-6.0.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:@.SITE.@${.SITE.}globalplatform/GlobalPlatform%20Library/GlobalPlatform%20Library%20${PKGVERSION_NOREV}/@}

MAINTAINER=	rhansen@bbn.com
HOMEPAGE=	http://globalplatform.sourceforge.net/
COMMENT=	C library for managing GlobalPlatform smart card contents
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
