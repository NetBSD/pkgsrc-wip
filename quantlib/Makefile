# $NetBSD: Makefile,v 1.1.1.1 2011/02/26 08:49:49 slitvinov Exp $
#

DISTNAME=	QuantLib-1.0.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quantlib/}

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://quantlib.sourceforge.net/
COMMENT=	Framework for quantitative finance
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
