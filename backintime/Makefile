# $NetBSD: Makefile,v 1.11 2014/05/09 07:38:42 thomasklausner Exp $

DISTNAME=	backintime-1.0.8_src
PKGNAME=	${DISTNAME:S/_src//}
CATEGORIES=	sysutils
MASTER_SITES=	http://www.le-web.org/download/backintime/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://backintime.le-web.org/
COMMENT=	Simple backup system for the GNOME desktop

DEPENDS+=	${PYPKGPREFIX}-gnome2-[0-9]*:../../x11/py-gnome2
DEPENDS+=	${PYPKGPREFIX}-notify-[0-9]*:../../sysutils/py-notify
DEPENDS+=	rsync-[0-9]*:../../net/rsync

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-notify

REPLACE_PYTHON=	backintime
USE_LANGUAGES=	# none
USE_TOOLS=	msgfmt

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing installation path.
SUBST_FILES.path+=	common/backintime
SUBST_FILES.path+=	common/configure
SUBST_FILES.path+=	common/Makefile.template
SUBST_FILES.path+=	gnome/Makefile.template
SUBST_FILES.path+=	gnome/app.py
SUBST_FILES.path+=	gnome/backintime-gnome
SUBST_FILES.path+=	gnome/docbook/C/backintime-C.omf
SUBST_VARS.path+=	PREFIX PKGMANDIR
SUBST_SED.path+=	-e "s,--mode=,-m ,"
SUBST_SED.path+=	-e "s,python,${PYTHONBIN},"

CONFIGURE_DIRS=	common gnome
HAS_CONFIGURE=	yes

BUILD_DIRS=	common gnome

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
