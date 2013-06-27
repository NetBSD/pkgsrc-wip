# $NetBSD: Makefile,v 1.1 2013/06/27 07:01:38 ahp-nils Exp $
#

DISTNAME=		pelican-3.2.2
CATEGORIES=		www textproc
MASTER_SITES=	http://pypi.python.org/packages/source/p/pelican/

MAINTAINER=		ahp-nils@users.sourceforge.net
HOMEPAGE=		http://blog.getpelican.com/
COMMENT=		Static site generator that supports Markdown and reST syntax
LICENSE=		gnu-agpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=26 31 32

DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=		${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=		${PYPKGPREFIX}-jinja2>=2.6:../../textproc/py-jinja2
DEPENDS+=		${PYPKGPREFIX}-pygments>=1.4:../../textproc/py-pygments
DEPENDS+=		${PYPKGPREFIX}-feedgenerator>=1.5:../../wip/py-feedgenerator
DEPENDS+=		${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=		${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../wip/py-six

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
