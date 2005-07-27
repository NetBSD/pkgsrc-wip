# $NetBSD: Makefile,v 1.5 2005/07/27 16:27:02 thomasklausner Exp $
#

DISTNAME=		pxview_0.1.4.orig
PKGNAME=		pxview-0.1.4
CATEGORIES=		databases
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/
COMMENT=		Simple utility to view Paradox database files

WRKSRC=			${WRKDIR}/pxview-0.1.4
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../wip/pxlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
