# $NetBSD: Makefile,v 1.6 2014/04/24 11:02:01 ahp-nils Exp $

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
USE_TOOLS+=		bash:run
VERSION=		3.3.0
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
FETCH_USING=		curl

PYTHON_VERSIONS_INCOMPATIBLE=26 32 # py-docutils

SUBST_CLASSES+=				fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing dynamic python
SUBST_FILES.fix-python+=	pelican/tools/pelican_import.py
SUBST_FILES.fix-python+=	pelican/tools/pelican_quickstart.py
SUBST_FILES.fix-python+=	pelican/tools/pelican_themes.py
SUBST_FILES.fix-python+=	pelican/tools/templates/pelicanconf.py.in
SUBST_FILES.fix-python+=	pelican/tools/templates/publishconf.py.in
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

REPLACE_INTERPRETER+=		bash
REPLACE.bash.old=			/usr/bin/env bash
REPLACE.bash.new=			${TOOLS_PATH.bash}
REPLACE_FILES.bash=			pelican/tools/templates/develop_server.sh.in

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
