# $NetBSD: Makefile,v 1.4 2008/05/24 15:34:10 tnn2 Exp $
#

DISTNAME=	esmart-0.9.0.011
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.yazzy.org/pkgsrc/e17/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Collection of evas smart objects

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

CONFIGURE_ARGS=		--with-edje-cc=${PREFIX}/bin/edje_cc

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epsilon/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
