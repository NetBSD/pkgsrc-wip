# $NetBSD: Makefile,v 1.4 2012/09/29 00:50:36 asau Exp $
#

DISTNAME=	gnocchi-0.35
PKGREVISION=	1
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
