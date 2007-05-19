# $NetBSD: Makefile,v 1.2 2007/05/19 10:27:15 ekamperi Exp $
#

DISTNAME=	murrine-0.53.1
CATEGORIES=	x11
MASTER_SITES=	http://cimi.netsons.org/media/download_gallery/murrine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ekamperi@auth.gr
HOMEPAGE=	http://cimi.netsons.org/media/download_gallery/murrine/
COMMENT=	Cairo-based, very fast, gtk engine

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	murrine.pc.in

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
