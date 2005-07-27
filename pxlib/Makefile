# $NetBSD: Makefile,v 1.8 2005/07/27 16:26:59 thomasklausner Exp $
#

DISTNAME=		pxlib_0.2.0.orig
PKGNAME=		pxlib-0.2.0
CATEGORIES=		databases devel
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/
COMMENT=		C language library for reading Paradox database files

WRKSRC=		${WRKDIR}/pxlib-0.2.0
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	pxlib.pc.in
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/recode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
