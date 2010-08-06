# $NetBSD: Makefile,v 1.2 2010/08/06 20:57:11 jihbed Exp $
#

DISTNAME=	PyQuante-1.6.3
PKGNAME=	${PYPKGPREFIX}-pyquante-1.6.3
CATEGORIES=	biology python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pyquante/PyQuante-1.6/PyQuante-1.6.3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyquante.sourceforge.net/
COMMENT=	Quantum chemistry in Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES= c
PYDISTUTILSPKG= yes

DOCDIR=	${PREFIX}/share/doc/py-pyquante

INSTALLATION_DIRS=	${DOCDIR}

do-test:
	( cd ${WRKSRC}/Tests && ${PYTHONBIN} runalltests.py )

post-install:
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
