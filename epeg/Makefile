# $NetBSD: Makefile,v 1.13 2010/12/26 05:01:22 davesainty Exp $
#

DISTNAME=	epeg-0.9.1.042
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-01-25/ \
		http://www.ezunix.org/pkgsrc/e17/snapshots/2008-01-25/ \
		http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	An IMMENSELY FAST JPEG thumbnailer library API.

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

.include "../../wip/ecore/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
