# $NetBSD: Makefile,v 1.1.1.1 2003/11/04 05:08:26 mpasternak Exp $
#

DISTNAME=		pxview_0.1.4.orig
PKGNAME=		pxview-0.1.4
CATEGORIES=		databases
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/
COMMENT=		Simple utility to view Paradox database files

WRKSRC=			${WRKDIR}/pxview-0.1.4
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../wip/pxlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
