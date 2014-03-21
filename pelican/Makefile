# $NetBSD: Makefile,v 1.5 2014/03/21 07:23:53 thomasklausner Exp $

DISTNAME=		${VERSION}
PKGNAME=		pelican-${DISTNAME}
CATEGORIES=		www textproc
MASTER_SITES=		https://github.com/getpelican/pelican/archive/
EXTRACT_SUFX=		.zip

MAINTAINER=		ahp-nils@users.sourceforge.net
HOMEPAGE=		http://blog.getpelican.com/
COMMENT=		Static site generator that supports Markdown and reST syntax
LICENSE=		gnu-agpl-v3

DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=		${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=		${PYPKGPREFIX}-jinja2>=2.6:../../textproc/py-jinja2
DEPENDS+=		${PYPKGPREFIX}-pygments>=1.4:../../textproc/py-pygments
DEPENDS+=		${PYPKGPREFIX}-feedgenerator>=1.5:../../wip/py-feedgenerator
DEPENDS+=		${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=		${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

VERSION=		3.2.2
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
FETCH_USING=		curl

PYTHON_VERSIONS_INCOMPATIBLE=26 33 # py-docutils

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
