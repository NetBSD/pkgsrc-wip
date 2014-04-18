# $NetBSD: Makefile,v 1.11 2014/04/18 19:37:22 thomasklausner Exp $

# version number from setup.py
DISTNAME=		khal-0.2.0
EGG_NAME=		${DISTNAME}.dev
CATEGORIES=		time net
MASTER_SITES=		https://github.com/geier/khal

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/geier/khal
COMMENT=		CLI calendar application built around CalDAV
LICENSE=		mit

GIT_REPOSITORIES=	khal
GIT_REPO.khal= 		git://github.com/geier/khal.git

DEPENDS+=		${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg
DEPENDS+=		${PYPKGPREFIX}-icalendar>=2.0.1:../../time/py-icalendar
DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=		${PYPKGPREFIX}-lxml>=2:../../textproc/py-lxml
DEPENDS+=		${PYPKGPREFIX}-requests>=0.10:../../devel/py-requests
# SimpleFocusListWalker is in urwid 1.1.0
DEPENDS+=		${PYPKGPREFIX}-urwid>=1.1.0:../../devel/py-urwid
# not needed, but recommended, so let's just depend on them
DEPENDS+=		${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=		${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle

PYTHON_VERSIONED_DEPENDENCIES=	dateutil

WRKSRC=			${WRKDIR}/khal
INSTALLATION_DIRS=	share/doc/khal
REPLACE_PYTHON+=	khal/*/*.py
REPLACE_PYTHON+=	khal/*.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/khal.conf.sample ${DESTDIR}${PREFIX}/share/doc/khal

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
