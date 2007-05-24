# $NetBSD: Makefile,v 1.1 2007/05/24 01:43:37 bsadewitz Exp $
#

DISTNAME=	aria2-0.10.2+1
PKGNAME=	${DISTNAME:S/+/_/g}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aria2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	ftp://superb-west.dl.sourceforge.net/sourceforge/aria2/
COMMENT=	Multithreaded download accelerator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--disable-xmltest

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"


.include "../../mk/bsd.pkg.mk"
