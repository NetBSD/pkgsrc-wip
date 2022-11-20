# $NetBSD$

GITHUB_PROJECT=	ConvertAll
DISTNAME=	convertall-0.8.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=doug-101/}
GITHUB_RELEASE=	v0.8.0
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://convertall.bellz.org/
COMMENT=	Another unit converter
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/ConvertAll

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_TOOLS+=		gettext msgfmt
NO_BUILD=		yes
USE_PKGLOCALEDIR=	yes

REPLACE_PYTHON+=	install.py uninstall.py source/convertall.py

MAKE_FLAGS+=		PREFIX=${PREFIX} DESTDIR=${DESTDIR}

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} install.py -p ${DESTDIR}${PREFIX}


.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
