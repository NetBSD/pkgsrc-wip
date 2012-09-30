# $NetBSD: Makefile,v 1.3 2012/09/30 05:44:15 asau Exp $
#

DISTNAME=	igraph-0.5.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=igraph/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://igraph.sf.net/
COMMENT=	Package For Manipulating Undirected And Directed Graphs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

REPLACE_SH+=	configure depcomp install-sh missing ylwrap \
		tests/testsuite

PKGCONFIG_OVERRIDE+=	igraph.pc.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
