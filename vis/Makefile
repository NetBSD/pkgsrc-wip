# $NetBSD: Makefile,v 1.3 2012/10/07 17:41:42 asau Exp $

DISTNAME=	vis-2.1
CATEGORIES=	cad
#MASTER_SITES=	ftp://vlsi.colorado.edu/pub/vis/
DISTFILES=	vis-2.1.tar.gz glu-2.1.tar.gz

MAINTAINER=	dhowland@users.sourceforge.net
#HOMEPAGE=	http://vlsi.colorado.edu/~vis/
COMMENT=	Classic logic verification tool

DEPENDS+=	bison>=1.22:../../devel/bison

CONFLICTS=	vis<=0.1

CONFIGURE_DIRS=	../glu-2.1 .

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
