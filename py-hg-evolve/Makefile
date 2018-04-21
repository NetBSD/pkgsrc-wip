# $NetBSD: Makefile,v 1.1 2017/04/14 12:10:26 leot Exp $

DISTNAME=	hg-evolve-7.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hg-evolve/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/doc/evolution/
COMMENT=	Mercurial extension for faster and safer mutable history
LICENSE=	gnu-gpl-v2

# The minimal Mercurial version needed is in hgext3rd/evolve/metadata.py
DEPENDS+=	${PYPKGPREFIX}-mercurial>=4.1:../../devel/py-mercurial

USE_LANGUAGES=	# none

# Remove hgext3rd/__init__.py*, already provided by devel/py-mercurial.
post-install:
	cd ${DESTDIR}${PREFIX} && ${RM} ${PYSITELIB}/hgext3rd/__init__.py
	cd ${DESTDIR}${PREFIX} && ${RM} ${PYSITELIB}/hgext3rd/__init__.pyc
	cd ${DESTDIR}${PREFIX} && ${RM} ${PYSITELIB}/hgext3rd/__init__.pyo

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
