# $NetBSD: Makefile,v 1.24 2023/08/14 05:25:31 wiz Exp $

DISTNAME=	urlgrabber-4.0.0
CATEGORIES=	www devel
MASTER_SITES=	http://urlgrabber.baseurl.org/download/
LICENSE=	gnu-lgpl-v2.1

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	http://urlgrabber.baseurl.org/
COMMENT=	Python package that drastically simplifies the fetching of files

REPLACE_PYTHON+=	scripts/urlgrabber-ext-down

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
