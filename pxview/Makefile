# $NetBSD: Makefile,v 1.3 2004/04/12 01:37:24 blef Exp $
#

DISTNAME=		pxview_0.1.4.orig
PKGNAME=		pxview-0.1.4
CATEGORIES=		databases
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/
COMMENT=		Simple utility to view Paradox database files

WRKSRC=			${WRKDIR}/pxview-0.1.4
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../wip/pxlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
