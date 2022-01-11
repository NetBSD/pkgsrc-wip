# $NetBSD$

DISTNAME=	rst2html5-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rst2html5/}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://foss.heptapod.net/doc-utils/rst2html5
COMMENT=	ReStructuredText to HTML5 converter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils>0.13.1:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-genshi>=0.7:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

post-install:
	${INSTALL_DATA} ${WRKSRC}/rst2html5_.py ${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
