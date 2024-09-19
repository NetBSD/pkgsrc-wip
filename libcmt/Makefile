# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:37 asau Exp $
#

DISTNAME=	libcmt-0.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcmt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://sourceforge.net/projects/libcmt/
COMMENT=	Composable Memory Transactions Library for C
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libcmt-sharp.pc.in
PKGCONFIG_OVERRIDE+=	libcmt.pc.in

CONFIGURE_ARGS+=	--disable-csharp-binding \
			--disable-checks \
			--enable-save-signal-mask

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
