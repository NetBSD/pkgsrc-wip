# $NetBSD: Makefile,v 1.4 2012/10/07 14:53:42 asau Exp $
#

DISTNAME=	QuantLib-1.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quantlib/}

COMMENT=	Framework for quantitative finance
LICENSE=	modified-bsd

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://quantlib.sourceforge.net/

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CHECK_PORTABILITY_SKIP=	configure

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
