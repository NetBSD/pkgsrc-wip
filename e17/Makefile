# $NetBSD: Makefile,v 1.3 2007/09/21 13:06:50 thomasklausner Exp $
#

DISTNAME=	enlightenment-0.16.999.037
PKGNAME=	e17-0.16.999.037
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://enlightenment.freedesktop.org/files/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	grzela@seculture.com
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightenment Window Manager, Development Release 17

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
DEPENDS+=	edje>=0.5.0.037:../../wip/edje
.include	"../../wip/edje/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
