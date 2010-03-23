# $NetBSD: Makefile,v 1.1.1.1 2010/03/23 13:47:45 uccwen Exp $
#

DISTNAME=	igraph-0.5.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=igraph/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://igraph.sf.net/
COMMENT=	Package For Manipulating Undirected And Directed Graphs
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	igraph.pc.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
