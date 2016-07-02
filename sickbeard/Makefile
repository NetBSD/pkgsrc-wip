# $NetBSD$

DISTNAME=	sickbeard-507
CATEGORIES=	multimedia
MASTER_SITES=	-https://github.com/midgetspy/Sick-Beard/archive/build-${PKGVERSION}.tar.gz

MAINTAINER=	js@heap.zone
HOMEPAGE=	http://sickbeard.com/
COMMENT=	PVR application to search and manage TV shows
# sickbeard, cherrypy, simplejson, jquery, gntp, tvdb_api
LICENSE=	gnu-gpl-v3 AND modified-bsd AND mit AND unlicense

DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

WRKSRC=		${WRKDIR}/Sick-Beard-build-${PKGVERSION}
NO_BUILD=	yes
USE_TOOLS=	pax

PKG_GROUPS=		sickbeard
PKG_USERS=		sickbeard:sickbeard
PKG_HOME.sickbeard=	${PREFIX}/lib/sickbeard

INSTALL_DIRS+=	autoProcessTV cherrypy data lib sickbeard
INSTALL_FILES+=	SickBeard.py CHANGELOG.txt CONTRIBUTING.md COPYING.txt
AUTO_MKDIRS=	yes

PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=			*.py */*.py */*/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-cheetah

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	sickbeard.sh
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/sickbeard.sh ${WRKSRC}/sickbeard.sh

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/lib/sickbeard
.for i in ${INSTALL_FILES} ${INSTALL_DIRS}
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}${PREFIX}/lib/sickbeard/
.endfor
	${RM} -rf ${DESTDIR}${PREFIX}/lib/sickbeard/lib/tvdb_api/tests
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL} -m 755 ${WRKSRC}/sickbeard.sh ${DESTDIR}${PREFIX}/bin/sickbeard
	${MKDIR} ${PKG_SYSCONFDIR}/sickbeard

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
