# $NetBSD: Makefile,v 1.1.1.1 2006/11/15 04:00:50 dhowland Exp $
#

DISTNAME=	vis-2.1
CATEGORIES=	cad
MASTER_SITES=	ftp://vlsi.colorado.edu/pub/vis/

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://vlsi.colorado.edu/~vis
COMMENT=	Classic logic verification tool

DISTFILES=	vis-2.1.tar.gz glu-2.1.tar.gz

DEPENDS+=	bison>=1.22:../../devel/bison

CONFLICTS=	vis<=0.1

CONFIGURE_DIRS=		../glu-2.1 .

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
