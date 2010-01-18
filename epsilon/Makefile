# $NetBSD: Makefile,v 1.9 2010/01/18 09:38:20 thomasklausner Exp $
#

DISTNAME=	epsilon-0.3.0.012
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-01-25/ \
		http://www.ezunix.org/pkgsrc/e17/snapshots/2008-01-25/ \
		http://jfranz.users.bsdprojects.net/pkgsrc/e17/

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
