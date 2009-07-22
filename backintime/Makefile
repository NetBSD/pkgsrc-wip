# $NetBSD: Makefile,v 1.5 2009/07/22 09:53:11 thomasklausner Exp $
#

DISTNAME=	backintime-0.9.2_src
PKGNAME=	${DISTNAME:S/_src//}
CATEGORIES=	sysutils
MASTER_SITES=	http://www.le-web.org/download/backintime/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.le-web.org/back-in-time/
COMMENT=	Simple backup system for the GNOME desktop

DEPENDS+=	${PYPKGPREFIX}-gnome2-[0-9]*:../../x11/py-gnome2
DEPENDS+=	rsync-[0-9]*:../../net/rsync

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

REPLACE_PYTHON=	backintime
USE_LANGUAGES=	# none
USE_TOOLS=	msgfmt

SUBST_CLASSES+=		path
SUBST_FILES.path=	backintime
SUBST_FILES.path+=	backintime-gnome
SUBST_FILES.path+=	config.py
SUBST_FILES.path+=	docbook/C/backintime-C.omf
SUBST_FILES.path+=	install-common.sh
SUBST_FILES.path+=	install-gnome.sh
SUBST_SED.path=		-e "s,/usr,${PREFIX},"
SUBST_SED.path+=	-e "s,--mode=,-m ,"
SUBST_SED.path+=	-e "s,share/man/man1,${PKGMANDIR}/man1,"
SUBST_SED.path+=	-e "s,python ,${PYTHONBIN} ,"
SUBST_STAGE.path=	post-extract
SUBST_MESSAGE.path=	Fixing installation path.

do-build:

do-install:
	cd ${WRKSRC} && ${SH} install-common.sh
	cd ${WRKSRC} && ${SH} install-gnome.sh

.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
