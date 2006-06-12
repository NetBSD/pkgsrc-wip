# $NetBSD: Makefile,v 1.11 2006/06/12 16:28:55 thomasklausner Exp $
#

DISTNAME=	DFBPoint-0.7.2
PKGNAME=	${DISTNAME:S/DFBP/dfbp/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.directfb.org/download/DFBPoint/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.directfb.org/
COMMENT=	Simple presentation viewer that uses the DirectFB

ONLY_FOR_PLATFORM=     Linux-*-*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../wip/directfb/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
