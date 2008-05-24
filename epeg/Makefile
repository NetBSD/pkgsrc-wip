# $NetBSD: Makefile,v 1.7 2008/05/24 15:34:09 tnn2 Exp $
#

DISTNAME=	epeg-0.9.0.011
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.yazzy.org/pkgsrc/e17/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	An IMMENSELY FAST JPEG thumbnailer library API.

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

.include "../../wip/ecore/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
