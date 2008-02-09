# $NetBSD: Makefile,v 1.4 2008/02/09 11:07:08 ekamperi Exp $
#

DISTNAME=	murrine-0.53.1
CATEGORIES=	x11
MASTER_SITES=	http://cimi.netsons.org/media/download_gallery/murrine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ekamperi@gmail.com
HOMEPAGE=	http://cimi.netsons.org/media/download_gallery/murrine/
COMMENT=	Cairo-based, very fast, gtk engine

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	murrine.pc.in

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
