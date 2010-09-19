# $NetBSD: Makefile,v 1.4 2010/09/19 08:13:18 jihbed Exp $
#

DISTNAME=	bleachbit-0.7.2
CATEGORIES=	sysutils python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/bleachbit/bleachbit/0.7.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://bleachbit.sourceforge.net/
COMMENT=	Bleachbit is a privacy and cleaning tool
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-gobject>=2.18.0:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.14.1:../../x11/py-gtk2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25
PYDISTUTILSPKG= yes

ONLY_FOR_PLATFORM= NetBSD-*-* Linux-*-*

REPLACE_PYTHON+=	bleachbit.py

INSTALLATION_DIRS+=  bin share/applications share/pixmaps share/examples/bleachbit \
				share/doc/bleachbit share/bleachbit/cleaners

post-extract:
	${RM} ${WRKSRC}/cleaners/Makefile

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bleachbit.py \
		${DESTDIR}${PREFIX}/bin/bleachbit
	cd ${WRKSRC}/cleaners && pax -rw -pp . \
		${DESTDIR}${PREFIX}/share/bleachbit/cleaners
	${INSTALL_DATA} ${WRKSRC}/doc/* \
		${DESTDIR}${PREFIX}/share/examples/bleachbit
	${INSTALL_DATA} ${WRKSRC}/bleachbit.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/bleachbit.png \
		${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/bleachbit


.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
