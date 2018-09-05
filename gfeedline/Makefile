# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	gfeedline-2.4.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/gfeedline/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://code.google.com/p/gfeedline/
COMMENT=	Social network client for GNOME
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gobject-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
#gir1.2-webkit-3.0
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
#python-openssl
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup-[0-9]*:../../www/py-beautifulsoup
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-distutils-extra-[0-9]*:../../wip/py-distutils-extra

PYTHON_VERSIONS_ACCEPTED=	27 # py-beautifulsoup, py-gobject

USE_LANGUAGES=		# none
NO_BUILD=		YES
USE_TOOLS+=		intltool
PY_PATCHPLIST=		yes
PLIST_SUBST+=		EGG_INFODIR=${DISTNAME}-py${PYVERSSUFFIX}.egg-info
INSTALLATION_DIRS=	share/applications \
			${PKGMANDIR}/man1 \
			etc \
			bin
MAKE_DIRS+=		${PREFIX}/share/gfeedline/html
MAKE_DIRS_PERMS+=	${PREFIX}/share/gfeedline/html ${ROOT_USER} ${ROOT_GROUP} 0755
FIX_PERMS=		*.html \
			*.css \
			*.js \
			*.woff \
			theme/Default/*.html \
			theme/Default/*.css
DATAMODE=		0644

REPLACE_PYTHON=		lib/plugins/post.py lib/plugins/twitter/dd.py

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	lib/utils/iconimage.py lib/utils/iconimage.py lib/constants.py
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_MESSAGE.prefix=	Replacing pkg path.

.include "options.mk"

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py install --root=${DESTDIR}

post-install:
	for file in ${FIX_PERMS}; do \
		${CHMOD} ${DATAMODE} ${DESTDIR}${PREFIX}/share/gfeedline/html/$$file; \
	done

.include "../../devel/dconf/buildlink3.mk"	# XXX Using the 'memory' GSettings backend(?)
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
