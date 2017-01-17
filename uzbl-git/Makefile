# $NetBSD$

DISTNAME=	uzbl-0.9.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=uzbl/}

GIT_REPOSITORIES=	uzbl
GIT_REPO.uzbl=		https://github.com/uzbl/uzbl.git
GIT_BRANCH.uzbl=	next
WRKSRC=			${WRKDIR}/uzbl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.uzbl.org/
COMMENT=	Web interface tools which adhere to the UNIX philosophy
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27
PY_PATCHPLIST=		yes
.include "../../lang/python/extension.mk"
MAKE_ENV+=	PYTHON=${PYTHONBIN}
MAKE_ENV+=	MANDIR=${DESTDIR}/${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=			fix-share
SUBST_STAGE.fix-share=		pre-configure
SUBST_MESSAGE.fix-share=	Fixing absolute paths to /usr/share
SUBST_FILES.fix-share=		bin/uzbl-tabbed uzbl/plugins/__init__.py
SUBST_SED.fix-share=		-e 's,/usr/share,${PREFIX}/share,g'

SUBST_CLASSES+=			fix-local-share
SUBST_STAGE.fix-local-share=	pre-configure
SUBST_MESSAGE.fix-local-share=	Fixing absolute paths to /usr/local/share
SUBST_FILES.fix-local-share=	bin/uzbl-browser.in src/uzbl-core.c
SUBST_SED.fix-local-share=	-e 's,/usr/local/share,${PREFIX}/share,g'

REPLACE_PYTHON+=	bin/uzbl-tabbed
REPLACE_PYTHON+=	examples/data/scripts/auth.py
REPLACE_PYTHON+=	examples/data/scripts/uzblcat
REPLACE_PYTHON+=	examples/data/scripts/per-site-settings.py
REPLACE_PYTHON+=	examples/data/scripts/scheme.py
.include "../../lang/python/application.mk"

# adapted from ../../lang/python/distutils.mk
# Set the egg file basename.
EGG_NAME?=	uzbl-201100808

# Egg files have the version encoded, so generalize in PLIST.
PLIST_SUBST+=	EGG_FILE=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PRINT_PLIST_AWK+=	{ gsub("${EGG_NAME}-py${PYVERSSUFFIX}.egg-info", \
				"$${EGG_FILE}") }

# for uzbl-browser
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
# for uzbl-tabbed with GTK+ 2
#DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
