# $NetBSD: Makefile,v 1.5 2012/11/11 23:17:53 outpaddling Exp $
#

DISTNAME=	viper-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://launchpad.net/fenics-viper/1.0.x/1.0.0/+download/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/fenics-viper
COMMENT=	Scientific plotter and run-time visualization module

FETCH_USING=	curl

LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
