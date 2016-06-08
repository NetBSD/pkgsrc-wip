# $NetBSD: Makefile,v 1.1 2014/06/20 19:57:21 jihbed Exp $

DISTNAME=	csb-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/csb/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://csb.codeplex.com
COMMENT=	Computational Structural Biology Toolbox
LICENSE=	mit

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=		${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
