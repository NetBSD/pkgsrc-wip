# $NetBSD: Makefile,v 1.21 2014/09/05 20:53:06 thomasklausner Exp $

# version number from setup.py
DISTNAME=		khal-0.4.0
EGG_NAME=		${DISTNAME}.dev
CATEGORIES=		time net
MASTER_SITES=		https://github.com/geier/khal

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/geier/khal
COMMENT=		CLI calendar application built around CalDAV
LICENSE=		mit

GIT_REPOSITORIES=	khal
GIT_REPO.khal= 		git://github.com/geier/khal.git

DEPENDS+=		${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=		${PYPKGPREFIX}-docopt-[0-9]*:../../devel/py-docopt
DEPENDS+=		${PYPKGPREFIX}-icalendar>=2.0.1:../../time/py-icalendar
DEPENDS+=		${PYPKGPREFIX}-lxml>=2:../../textproc/py-lxml
DEPENDS+=		${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-requests>=0.10:../../devel/py-requests
DEPENDS+=		${PYPKGPREFIX}-requests-toolbelt-[0-9]*:../../devel/py-requests-toolbelt
DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=		${PYPKGPREFIX}-vdirsyncer-[0-9]*:../../time/py-vdirsyncer
DEPENDS+=		${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg
# SimpleFocusListWalker is in urwid 1.1.0
DEPENDS+=		${PYPKGPREFIX}-urwid>=1.1.0:../../devel/py-urwid
# not needed, but recommended, so let's just depend on them
DEPENDS+=		${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=		${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle

PYTHON_VERSIONED_DEPENDENCIES=	dateutil
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 20140604

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
