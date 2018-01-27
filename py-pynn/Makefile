# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:44 thomasklausner Exp $

DISTNAME=	PyNN-0.7.5
PKGNAME=	${PYPKGPREFIX}-pynn-0.7.5
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyNN/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://neuralensemble.org/trac/PyNN/wiki
COMMENT=	Python package for neuronal network models

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/doc/py-pynn

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/py-pynn

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
