# $NetBSD: Makefile,v 1.2 2011/05/04 12:29:11 ryo-on Exp $
#

DISTNAME=	libwebp-0.1.2
CATEGORIES=	graphics
MASTER_SITES=	http://webp.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/intl/ja/speed/webp/
COMMENT=	WebP image format library and tools
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake

PKGCONFIG_OVERRIDE+=	src/libwebp.pc.in

pre-configure:
	touch ${WRKSRC}/ltmain.sh
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
