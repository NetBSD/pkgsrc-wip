# $NetBSD: Makefile,v 1.1.1.1 2011/03/30 21:13:24 ryo-on Exp $
#

DISTNAME=	libwebp-0.1.2-rc1
PKGNAME=	${DISTNAME:S/-rc/rc/}
CATEGORIES=	graphics
MASTER_SITES=	http://webp.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/intl/ja/speed/webp/
COMMENT=	WebP image format library and tools
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/libwebp-0.1.2
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
