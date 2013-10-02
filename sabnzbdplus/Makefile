# $NetBSD: Makefile,v 1.2 2013/10/02 11:47:48 wongk Exp $

DISTNAME=       sabnzbdplus-${DISTVERSION}
DISTVERSION= 0.7.16
DISTFILES=      SABnzbd-${DISTVERSION}-src${EXTRACT_SUFX}

CATEGORIES=	news

.include "options.mk"

MASTER_SITES=    ${MASTER_SITE_SOURCEFORGE:=sabnzbdplus/sabnzbdplus/}${DISTVERSION}/

NO_BUILD= yes
WRKSRC=	${WRKDIR}/${DISTFILES}
WRKSRC=	${WRKDIR}/SABnzbd-${DISTVERSION}/sabnzbd
WRKSRC=	${WRKDIR}/SABnzbd-${DISTVERSION}

MAINTAINER=	wongk@apt.homeunix.net
HOMEPAGE=	http://sabnzbdplus.sourceforge.net/
DEPENDS+= ${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah \
					${PYPKGPREFIX}-configobj-[0-9]*:../../wip/py-configobj \
					${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3 \
					${PYPKGPREFIX}-xml-[0-9]*:../../textproc/py-xml

COMMENT=	Web-interface based binary newsgrabber in python, with nzb support
USE_TOOLS=	pax

PKG_GROUPS= sabnzbd
PKG_USERS= sabnzbd:sabnzbd
PKG_HOME.sabnzbd= ${PREFIX}/sabnzbd

INSTALLATION_DIRS+=	cherrypy gntp interfaces locale po tools util

PY_PATCHPLIST=          yes
PLIST_SUBST+=           PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=   *.py */*.py */*/*.py

SUBST_CLASSES+=	fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths= Fix absolute paths.
SUBST_FILES.fix-paths=	SABnzbd.py
SUBST_SED.fix-paths=	-e 's,%%PREFIX%%,${PREFIX},g'

LICENSE= gnu-gpl-v2 AND gnu-gpl-v3 AND modified-bsd AND mit

do-install:
	${MKDIR} ${DESTDIR}/${PREFIX}/bin
	cd ${WRKSRC} && pax -rw SABnzbd.py ${DESTDIR}/${PREFIX}/bin/

	${MKDIR} ${DESTDIR}/${PREFIX}/${PYSITELIB}/
	cd ${WRKSRC} && pax -rw -pmp sabnzbd ${DESTDIR}/${PREFIX}/${PYSITELIB}/

.for i in ${INSTALLATION_DIRS}
	${MKDIR} ${DESTDIR}/${PREFIX}/share/sabnzbdplus
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}/${PREFIX}/share/sabnzbdplus
.endfor

	cd ${.CURDIR}/files && pax -rw -pmp sabnzbd.xml ${DESTDIR}/${PREFIX}/share/sabnzbdplus

OWN_DIRS_PERMS= ${PREFIX}/sabnzbd sabnzbd sabnzbd 0755


# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
