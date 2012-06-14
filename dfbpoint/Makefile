# $NetBSD: Makefile,v 1.14 2012/06/14 20:33:12 othyro Exp $
#

DISTNAME=	DFBPoint-0.7.2
PKGNAME=	${DISTNAME:S/DFBP/dfbp/}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.directfb.org/download/DFBPoint/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.directfb.org/
COMMENT=	Simple presentation viewer that uses the DirectFB
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir
ONLY_FOR_PLATFORM=	Linux-*-*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../wip/directfb/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
