# $NetBSD: Makefile,v 1.9 2015/03/11 20:56:06 ahp-nils Exp $

DISTNAME=		pelican-3.5.0
PKGREVISION=		1
CATEGORIES=		www textproc
MASTER_SITES=		-https://github.com/getpelican/pelican/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}
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
DEPENDS+=		${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=		${PYPKGPREFIX}-sphinx>=1.2.3nb1:../../textproc/py-sphinx
USE_TOOLS+=		bash:run make:build

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

DOCDIR=			${PREFIX}/share/doc/pelican
INSTALLATION_DIRS+=	${PKGMANDIR}/man1/ ${DOCDIR}
MANPAGES=		pelican-themes.1 pelican-theming.1 pelican.1

TXTDOCFILES=		changelog.txt content.txt contribute.txt faq.txt \
			importer.txt index.txt install.txt internals.txt \
			pelican-themes.txt plugins.txt publish.txt quickstart.txt \
			report.txt settings.txt themes.txt tips.txt

AUTO_MKDIRS=		yes

post-build:
	cd ${WRKSRC}/docs/ && make SPHINXBUILD=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX} text man

post-install:
.for f in ${MANPAGES}
	${INSTALL_DATA} ${WRKSRC}/docs/_build/man/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
.for i in ${TXTDOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/_build/text/${i} ${DESTDIR}${DOCDIR}/
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
