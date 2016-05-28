# $NetBSD: Makefile,v 1.8 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=		pxview_0.1.4.orig
PKGNAME=		pxview-0.1.4
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pxlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pxlib.sourceforge.net/
COMMENT=		Simple utility to view Paradox database files


WRKSRC=			${WRKDIR}/pxview-0.1.4
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../wip/pxlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
