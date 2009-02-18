# $NetBSD: Makefile,v 1.1.1.1 2009/02/18 19:49:36 marko_schuetz Exp $
#

DISTNAME=	gnocchi-0.35
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnocchi/}

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://www.muftor.com/Wikka/wikka.php?wakka=Gnocchi
COMMENT=	Complexity analyser for C++

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
