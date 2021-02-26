# $NetBSD: Makefile,v 1.6 2015/02/04 10:10:53 thomasklausner Exp $

DISTNAME=	sabnzbd-${DISTVERSION}
DISTVERSION=	3.2.0
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=sabnzbd/}
GITHUB_PROJECT=	sabnzbd
GITHUB_TAG=	${DISTVERSION}


MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://sabnzbd.org/
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND modified-bsd AND mit

DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah3
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-sabyenc3-[0-9]*:../../wip/py-sabyenc3
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-portend-[0-9]*:../../net/py-portend
DEPENDS+=	${PYPKGPREFIX}-cherrypy>=18.2:../../www/py-cherrypy
DEPENDS+=	par2-[0-9]*:../../archivers/par2
DEPENDS+=	unrar-[0-9]*:../../archivers/unrar
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	p7zip-[0-9]*:../../archivers/p7zip

NO_BUILD=		yes
USE_TOOLS=		pax
USE_LANGUAGES+=		c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

PKG_GROUPS=		sabnzbd
PKG_USERS=		sabnzbd:sabnzbd
PKG_HOME.sabnzbd=	${PREFIX}/sabnzbd

OWN_DIRS_PERMS=	${PREFIX}/sabnzbd sabnzbd sabnzbd 0755

INSTALLATION_DIRS+=	email icons interfaces po sabnzbd scripts tools

PY_PATCHPLIST=		yes
REPLACE_PYTHON=		*.py */*.py */*/*.py

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fix absolute paths.
SUBST_FILES.fix-paths=		SABnzbd.py
SUBST_VARS.fix-paths=		PREFIX

do-install:
	${MKDIR} ${DESTDIR}/${PREFIX}/bin
	cd ${WRKSRC} && pax -rw SABnzbd.py ${DESTDIR}/${PREFIX}/bin/
	${MKDIR} ${DESTDIR}/${PREFIX}/${PYSITELIB}/
	cd ${WRKSRC} && pax -rw -pmp sabnzbd ${DESTDIR}/${PREFIX}/${PYSITELIB}/
.for i in ${INSTALLATION_DIRS}
	${MKDIR} ${DESTDIR}/${PREFIX}/share/sabnzbd
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}/${PREFIX}/share/sabnzbd
.endfor
	cd ${.CURDIR}/files && pax -rw -pmp sabnzbd.xml ${DESTDIR}/${PREFIX}/share/sabnzbd
	${CHMOD} a-x ${DESTDIR}${PREFIX}/share/sabnzbd/interfaces/Plush/templates/static/stylesheets/jqueryui/overcast/images/*.png

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
