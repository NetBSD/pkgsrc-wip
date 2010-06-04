# $NetBSD: Makefile,v 1.2 2010/06/04 12:08:20 jihbed Exp $
#

DISTNAME=	bodr-8
CATEGORIES=	biology
MASTER_SITES=	http://garr.dl.sourceforge.net/project/bodr/bodr/8/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://blueobelisk.sourceforge.net/wiki/Main_Page
COMMENT=	Blue Obelisk Data Repository
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake perl
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	bodr.pc.in

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
