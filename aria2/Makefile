# $NetBSD: Makefile,v 1.2 2007/07/16 14:46:57 bsadewitz Exp $
#

DISTNAME=	aria2-0.11.1+1
PKGNAME=	${DISTNAME:S/+/./g}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aria2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://aria2.sourceforge.net/
COMMENT=	Multithreaded download accelerator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--disable-xmltest
CONFIGURE_ARGS+=	--enable-bittorrent

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"


.include "../../mk/bsd.pkg.mk"
