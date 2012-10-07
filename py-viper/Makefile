# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	viper-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://launchpad.net/fenics-viper/1.0.x/1.0.0/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/fenics-viper
COMMENT=	Scientific plotter and run-time visualization module

FETCH_USING=	curl

LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
