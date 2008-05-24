# $NetBSD: Makefile,v 1.7 2008/05/24 15:34:08 tnn2 Exp $
#

DISTNAME=	aria2-0.11.3
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aria2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://aria2.sourceforge.net/
COMMENT=	Multithreaded download accelerator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-bittorrent
CONFIGURE_ARGS+=	--with-included-gettext=no

TEST_TARGET=		check

.include "options.mk"

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
BUILDLINK_DEPMETHOD.cppunit?=	build
.  include "../../devel/cppunit/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xmltest
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
