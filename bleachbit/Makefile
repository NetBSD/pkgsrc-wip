# $NetBSD: Makefile,v 1.13 2014/07/24 00:17:49 jihbed Exp $

DISTNAME=	bleachbit-1.2
CATEGORIES=	sysutils python
MASTER_SITES=	http://sourceforge.net/projects/bleachbit/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://bleachbit.sourceforge.net/
COMMENT=	Bleachbit is a privacy and cleaning tool
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-gobject>=2.18.0:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-notify>=0.2.1:../../sysutils/py-notify

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2
REPLACE_PYTHON+=		bleachbit.py

INSTALLATION_DIRS+=	bin share/applications share/pixmaps


post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bleachbit.py  \
			${DESTDIR}${PREFIX}/bin/bleachbit${PYVERSSUFFIX}
	${INSTALL_DATA} ${WRKSRC}/bleachbit.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/bleachbit.png \
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
