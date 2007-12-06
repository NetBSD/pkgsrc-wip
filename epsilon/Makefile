# $NetBSD: Makefile,v 1.1.1.1 2007/12/06 03:29:05 netcap Exp $
#

DISTNAME=	epsilon-0.3.0.011
CATEGORIES=	graphics
MASTER_SITES=   http://www.yazzy.org/pkgsrc/e17/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Small, display independent, and quick thumbnailing library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config
CONFIGURE_ARGS=		--enable-thumbnailer-xine

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epeg/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
