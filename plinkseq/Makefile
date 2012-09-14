# $NetBSD: Makefile,v 1.2 2012/09/14 17:08:00 asau Exp $
#

DISTNAME=	plinkseq-0.08
CATEGORIES=	biology
MASTER_SITES=	http://atgu.mgh.harvard.edu/plinkseq/dist/version-0.08/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://atgu.mgh.harvard.edu/plinkseq/
COMMENT=	C/C++ library for working with human genetic variation data
LICENSE=	gnu-gpl-v2	# Assuming same as plink.  No info on web.

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	bash:run

.include "../../mk/bsd.prefs.mk"

.if $(OPSYS) != "Linux"
BUILDLINK_TRANSFORM=	rm:-ldl
.endif

REPLACE_BASH=	browser/pbrowse.in index/index.in

.include "../../wip/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
