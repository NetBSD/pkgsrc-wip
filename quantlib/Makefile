# $NetBSD: Makefile,v 1.3 2012/02/28 18:57:25 slitvinov Exp $
#

DISTNAME=	QuantLib-1.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quantlib/}

COMMENT=	Framework for quantitative finance
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://quantlib.sourceforge.net/

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CHECK_PORTABILITY_SKIP=	configure

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
