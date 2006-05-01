# $NetBSD: Makefile,v 1.6 2006/05/01 14:20:08 shattered Exp $
#

DISTNAME=		pxview_0.1.4.orig
PKGNAME=		pxview-0.1.4
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pxlib/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pxlib.sourceforge.net/
COMMENT=		Simple utility to view Paradox database files

WRKSRC=			${WRKDIR}/pxview-0.1.4
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../wip/pxlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
