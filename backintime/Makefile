# $NetBSD: Makefile,v 1.2 2009/01/04 18:16:45 thomasklausner Exp $
#

DISTNAME=	backintime-0.8.10_src
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
USE_DIRS+=	gnome2-1.6 xdg-1.4
USE_LANGUAGES=	# none
USE_TOOLS=	msgfmt

SUBST_CLASSES+=		path
SUBST_FILES.path=	backintime
SUBST_FILES.path+=	config.py
SUBST_FILES.path+=	docbook/C/backintime-C.omf
SUBST_FILES.path+=	install.sh
SUBST_SED.path=		-e "s,/usr,${PREFIX},"
SUBST_SED.path+=	-e "s,--mode=,-m ,"
SUBST_SED.path+=	-e "s,share/man/man1,${PKGMANDIR}/man1,"
SUBST_STAGE.path=	post-extract
SUBST_MESSAGE.path=	Fixing installation path.

do-build:

do-install:
	cd ${WRKSRC} && ${SH} install.sh

.include "../../lang/python/application.mk"
.include "../../textproc/rarian/omf.mk"
.include "../../mk/bsd.pkg.mk"
