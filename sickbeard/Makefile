# $NetBSD: Makefile,v 1.1 2013/10/01 20:29:04 wongk Exp $

DISTNAME=	sickbeard-${DISTVERSION}
COMMIT_SHA=	91c428a43765a1476ec268f73cd62051a64bf4e0
DISTVERSION= ${COMMIT_SHA:C/([a-f0-9]{7}).*/\1/}
CATEGORIES=	news

FETCH_USING= curl

MASTER_SITES=	-https://github.com/midgetspy/Sick-Beard/tarball/${COMMIT_SHA}
# DISTFILE is the the filename to save the download as
DISTFILE= ${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tgz

TEMP_DIR= midgetspy-Sick-Beard-${DISTVERSION}
WRKSRC= ${WRKDIR}/${TEMP_DIR}
NO_BUILD= yes
USE_TOOLS= pax

PKG_GROUPS= other
PKG_USERS= sickbeard:other
PKG_HOME.sickbeard= ${PREFIX}/sickbeard

INSTALL_DIRS+= autoProcessTV cherrypy data lib sickbeard
INSTALL_FILES+= SickBeard.py init.solaris11
AUTO_MKDIRS=yes

PY_PATCHPLIST=          yes
PLIST_SUBST+=           PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=   *.py */*.py */*/*.py

SUBST_CLASSES+= fix-paths
SUBST_STAGE.fix-paths=  pre-configure
SUBST_MESSAGE.fix-paths= Fix absolute paths.
SUBST_FILES.fix-paths=  init.solaris11
SUBST_SED.fix-paths=  -e 's,/opt/sickbeard,${PREFIX}/sickbeard,g'

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/sickbeard
.for i in ${INSTALL_FILES} ${INSTALL_DIRS}
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}${PREFIX}/sickbeard/
.endfor
	${RM} -rf ${DESTDIR}${PREFIX}/sickbeard/lib/tvdb_api/tests
	@${ECHO} ${COMMIT_SHA} > ${DESTDIR}${PREFIX}/sickbeard/version.txt

MAINTAINER=	wongk@apt.homeunix.net

.include "../../lang/python/application.mk"

DEPENDS+= ${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah \
          ${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree\
          ${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

HOMEPAGE=	http://sickbeard.com/
COMMENT=	Search for TV series nzb-files via web interface

# sickbeard, cherrypy, simplejson, jquery, gntp, tvdb_api
LICENSE=	gnu-gpl-v3 AND modified-bsd AND mit AND unlicense

# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
