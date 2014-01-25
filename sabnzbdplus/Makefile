# $NetBSD: Makefile,v 1.3 2014/01/25 10:38:26 thomasklausner Exp $

DISTNAME=       sabnzbdplus-${DISTVERSION}
DISTVERSION= 0.7.16
DISTFILES=      SABnzbd-${DISTVERSION}-src${EXTRACT_SUFX}
CATEGORIES=	news
MASTER_SITES=    ${MASTER_SITE_SOURCEFORGE:=sabnzbdplus/sabnzbdplus/}${DISTVERSION}/

MAINTAINER=	wongk@apt.homeunix.net
HOMEPAGE=	http://sabnzbdplus.sourceforge.net/
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND modified-bsd AND mit

DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../wip/py-configobj
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-xml-[0-9]*:../../textproc/py-xml

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SABnzbd-${DISTVERSION}
USE_TOOLS=	pax

.include "options.mk"

PKG_GROUPS=		sabnzbd
PKG_USERS=		sabnzbd:sabnzbd
PKG_HOME.sabnzbd=	${PREFIX}/sabnzbd

OWN_DIRS_PERMS= ${PREFIX}/sabnzbd sabnzbd sabnzbd 0755

INSTALLATION_DIRS+=	cherrypy gntp interfaces locale po tools util

PY_PATCHPLIST=          yes
PLIST_SUBST+=           PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=		*.py */*.py */*/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-cheetah

SUBST_CLASSES+=	fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths= Fix absolute paths.
SUBST_FILES.fix-paths=	SABnzbd.py
SUBST_SED.fix-paths=	-e 's,%%PREFIX%%,${PREFIX},g'

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

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
