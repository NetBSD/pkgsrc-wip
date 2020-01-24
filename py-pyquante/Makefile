# $NetBSD: Makefile,v 1.4 2012/11/12 16:26:50 othyro Exp $
#

DISTNAME=	PyQuante-1.6.3
PKGNAME=	${PYPKGPREFIX}-pyquante-1.6.3
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyquante/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyquante.sourceforge.net/
COMMENT=	Quantum chemistry in Python
LICENSE=	modified-bsd

USE_LANGUAGES=	c
PYDISTUTILSPKG=	yes

DOCDIR=	${PREFIX}/share/doc/py-pyquante

INSTALLATION_DIRS=	${DOCDIR}

do-test:
	( cd ${WRKSRC}/Tests && ${PYTHONBIN} runalltests.py )

post-install:
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
