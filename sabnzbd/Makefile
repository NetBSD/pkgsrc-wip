# $NetBSD$

DISTNAME=	sabnzbd-${DISTVERSION}
DISTVERSION=	4.3.2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=sabnzbd/}
GITHUB_PROJECT=	sabnzbd
GITHUB_TAG=	${DISTVERSION}


MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://sabnzbd.org/
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND modified-bsd AND mit

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah3
DEPENDS+=	${PYPKGPREFIX}-cherrypy>=18.2:../../www/py-cherrypy
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-guessit>=3.1.1:../../textproc/py-guessit
DEPENDS+=	${PYPKGPREFIX}-jaraco.classes>=3.3.0:../../devel/py-jaraco.classes
DEPENDS+=	${PYPKGPREFIX}-portend-[0-9]*:../../net/py-portend
DEPENDS+=	${PYPKGPREFIX}-puremagic>=1.11:../../sysutils/py-puremagic
DEPENDS+=	${PYPKGPREFIX}-sabctools>=8.2.0:../../wip/py-sabctools
DEPENDS+=	${PYPKGPREFIX}-apprise>=1.1.0:../../wip/py-apprise
# Optional:
#DEPENDS+=	${PYPKGPREFIX}-dbus>=1.3.2:../../sysutils/py-dbus

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

PY_PATCHPLIST=		yes
REPLACE_PYTHON=		*.py */*.py */*/*.py

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fix absolute paths.
SUBST_FILES.fix-paths=		SABnzbd.py
SUBST_VARS.fix-paths=		PREFIX

do-install:
	${MKDIR} ${DESTDIR}/${PREFIX}/bin
	cd ${WRKSRC} && find . -name '*.orig' -delete
	cd ${WRKSRC} && pax -rw SABnzbd.py ${DESTDIR}/${PREFIX}/bin/
	${MKDIR} ${DESTDIR}/${PREFIX}/${PYSITELIB}/
	cd ${WRKSRC} && pax -rw -pmp sabnzbd ${DESTDIR}/${PREFIX}/${PYSITELIB}/
	${MKDIR} ${DESTDIR}/${PREFIX}/share/sabnzbd
.for i in email icons interfaces po scripts tools
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}/${PREFIX}/share/sabnzbd
.endfor
	cd ${.CURDIR}/files && pax -rw -pmp sabnzbd.xml ${DESTDIR}/${PREFIX}/share/sabnzbd
	${CHMOD} -R go-w ${DESTDIR}${PREFIX}
	${CHMOD} a-x ${DESTDIR}${PREFIX}/share/sabnzbd/interfaces/Glitter/templates/static/javascripts/momentjs_locale/*.js

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
