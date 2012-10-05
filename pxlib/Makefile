# $NetBSD: Makefile,v 1.11 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=		pxlib_0.2.0.orig
PKGNAME=		pxlib-0.2.0
CATEGORIES=		databases devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pxlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pxlib.sourceforge.net/
COMMENT=		C language library for reading Paradox database files

PKG_DESTDIR_SUPPORT=	none

WRKSRC=		${WRKDIR}/pxlib-0.2.0
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	pxlib.pc.in
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/recode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
