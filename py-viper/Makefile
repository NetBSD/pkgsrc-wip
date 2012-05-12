# $NetBSD: Makefile,v 1.3 2012/05/12 02:04:12 outpaddling Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
