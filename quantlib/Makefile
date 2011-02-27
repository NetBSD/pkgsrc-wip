# $NetBSD: Makefile,v 1.2 2011/02/27 08:40:19 slitvinov Exp $
#

DISTNAME=	QuantLib-1.0.1
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

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"