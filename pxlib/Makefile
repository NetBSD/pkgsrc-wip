# $NetBSD: Makefile,v 1.2 2004/02/17 02:56:31 blef Exp $
#

DISTNAME=		pxlib_0.2.0.orig
PKGNAME=		pxlib-0.2.0
CATEGORIES=		databases devel
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/
COMMENT=		C language library for reading Paradox database files

WRKSRC=		${WRKDIR}/pxlib-0.2.0
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pxlib.pc.in
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink2.mk"
.include "../../converters/recode/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
