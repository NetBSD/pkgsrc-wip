# $NetBSD: Makefile,v 1.1 2013/09/20 10:12:02 jihbed Exp $

DISTNAME=	PyNN-0.7.5
PKGNAME=	${PYPKGPREFIX}-pynn-0.7.5
CATEGORIES=	biology
MASTER_SITES=	https://pypi.python.org/packages/source/P/PyNN/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://neuralensemble.org/trac/PyNN/wiki
COMMENT=	Python package for neuronal network models

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=     share/doc/py-pynn

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/py-pynn

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
