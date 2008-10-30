# $NetBSD: Makefile,v 1.8 2008/10/30 21:19:22 yazzy Exp $
#

DISTNAME=	esmart-0.9.0.042
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.ezunix.org/pkgsrc/e17/snapshots/2008-09-25/

EXTRACT_SUFX=	.tar.bz2
MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Collection of evas smart objects

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config automake autoconf autoheader aclocal

CONFIGURE_ARGS=		--with-edje-cc=${PREFIX}/bin/edje_cc

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh	

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/eina/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epsilon/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
