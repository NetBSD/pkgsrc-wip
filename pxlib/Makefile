# $NetBSD: Makefile,v 1.5 2004/08/17 18:31:49 tvierling Exp $
#

DISTNAME=		pxlib_0.2.0.orig
PKGNAME=		pxlib-0.2.0
CATEGORIES=		databases devel
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/
COMMENT=		C language library for reading Paradox database files

WRKSRC=		${WRKDIR}/pxlib-0.2.0
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libpx.la
PKGCONFIG_OVERRIDE+=	pxlib.pc.in
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/recode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
