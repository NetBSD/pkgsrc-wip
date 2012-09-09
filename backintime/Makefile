# $NetBSD: Makefile,v 1.6 2012/09/09 10:19:11 noud4 Exp $
#

DISTNAME=	backintime-0.9.2_src
PKGNAME=	${DISTNAME:S/_src//}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.le-web.org/download/backintime/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.le-web.org/back-in-time/
COMMENT=	Simple backup system for the GNOME desktop

PKG_DESTDIR_SUPPORT=	user-destdir

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
SUBST_SED.path=		-e "s,/usr,${DESTDIR}${PREFIX},"
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
