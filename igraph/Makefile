# $NetBSD: Makefile,v 1.2 2010/03/23 14:53:43 christtrekker Exp $
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

REPLACE_SH+=	configure depcomp install-sh missing ylwrap \
		tests/testsuite

PKGCONFIG_OVERRIDE+=	igraph.pc.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
