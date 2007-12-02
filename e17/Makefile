# $NetBSD: Makefile,v 1.4 2007/12/02 14:50:13 hoka_adam Exp $
#

DISTNAME=	enlightenment-0.16.999.041
PKGNAME=	e17-0.16.999.041
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightenment Window Manager, Development Release

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config
DEPENDS+=	edje>=0.5.0.041:../../wip/edje
DEPENDS+=	efreet>=0.0.3.006:../../wip/efreet
.include	"../../wip/edje/buildlink3.mk"
.include	"../../wip/efreet/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
