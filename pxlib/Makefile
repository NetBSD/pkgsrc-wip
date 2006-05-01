# $NetBSD: Makefile,v 1.9 2006/05/01 14:20:08 shattered Exp $
#

DISTNAME=		pxlib_0.2.0.orig
PKGNAME=		pxlib-0.2.0
CATEGORIES=		databases devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pxlib/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pxlib.sourceforge.net/
COMMENT=		C language library for reading Paradox database files

WRKSRC=		${WRKDIR}/pxlib-0.2.0
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	pxlib.pc.in
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/recode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
