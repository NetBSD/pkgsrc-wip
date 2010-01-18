# $NetBSD: Makefile,v 1.3 2010/01/18 09:38:19 thomasklausner Exp $
#

DISTNAME=	elementary-0.5.1.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-07-29/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	E17 Widget Library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	elementary

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
