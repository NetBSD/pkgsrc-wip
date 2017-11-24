# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	openastro-1.1.38
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
# The DISTFILE to download is an HTTP-only attachment.
# The getsite.sh script uses cURL download the attached file.

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openastro.org/
COMMENT=	Open source astrology program, openastro.org
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-ORBit via py-gnome2, py-gtk2

WRKSRC=			${WRKDIR}/openastro.org-1.1.38
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none
PY_PATCHPLIST=		yes

REPLACE_PYTHON+=	openastromod/dignities.py openastromod/geoname.py
REPLACE_PYTHON+=	openastromod/importfile.py openastromod/swiss.py
REPLACE_PYTHON+=	openastromod/zonetab.py

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	openastromod/dignities.py openastromod/swiss.py
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|g"
SUBST_STAGE.prefix=	post-extract

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} setup.py install --root=${DESTDIR}

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/applications/openastro.desktop
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/openastro.org/icons/aspects/*.svg
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/openastro.org/icons/openastro.svg
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/openastro.org/openastro-ui.xml
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/swisseph/*

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/py-pyswisseph/buildlink3.mk"
.include "../../wip/swisseph/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
