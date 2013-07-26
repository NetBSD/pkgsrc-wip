# $NetBSD: Makefile,v 1.1 2013/07/26 20:30:45 jihbed Exp $

DISTNAME=	pymdptoolbox-4.0a2
PKGNAME=	${PYPKGPREFIX}-mdptoolbox-4.0a2
CATEGORIES=	math
MASTER_SITES=	http://pymdptoolbox.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pymdptoolbox/
COMMENT=	Implementation of Markov Decision Problem algorithms for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy

PYDISTUTILSPKG=		YES

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
