# $NetBSD$

DISTNAME=	mcomix3-0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	games
GIT_REPO=	git://github.com/multiSnow/mcomix3.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/multiSnow/mcomix3
COMMENT=	Comic viewer
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.24:../../devel/py-gobject3

USE_LANGUAGES=			# empty
PYTHON_VERSIONS_INCOMPATIBLE=	27
INSTALLATION_DIRS+=		bin
REPLACE_PYTHON+=		mcomix/comicthumb.py
REPLACE_PYTHON+=		mcomix/mcomixstarter.py

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/mcomix3
	${ECHO} "${PYTHONBIN} ${PREFIX}/libexec/mcomix/mcomixstarter.py "'"$$@"' >> ${WRKSRC}/mcomix3

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} installer.py --srcdir=mcomix --target=${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/mcomix3 ${DESTDIR}${PREFIX}/bin

#.include "../../databases/shared-mime-info/mimedb.mk"
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
