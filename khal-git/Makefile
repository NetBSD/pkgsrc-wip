# $NetBSD: Makefile,v 1.4 2013/12/26 18:10:13 jeremy-c-reed Exp $

# version number from setup.py
DISTNAME=		khal-0.1.0
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
DEPENDS+=		${PYPKGPREFIX}-dateutil>=1.4.1:../../time/py-dateutil
DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=		${PYPKGPREFIX}-lxml>=2:../../textproc/py-lxml
DEPENDS+=		${PYPKGPREFIX}-requests>=0.10:../../devel/py-requests
# SimpleFocusListWalker is in urwid 1.1.0
DEPENDS+=		${PYPKGPREFIX}-urwid>=1.1.0:../../devel/py-urwid

WRKSRC=			${WRKDIR}/khal
EGG_NAME=		${DISTNAME}.dev
INSTALLATION_DIRS=	share/doc/khal
REPLACE_PYTHON+=	khal/__init__.py
REPLACE_PYTHON+=	khal/aux.py
REPLACE_PYTHON+=	khal/backend.py
REPLACE_PYTHON+=	khal/caldav.py
REPLACE_PYTHON+=	khal/calendar_display.py
REPLACE_PYTHON+=	khal/controllers.py
REPLACE_PYTHON+=	khal/model.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/khal.conf.sample ${DESTDIR}${PREFIX}/share/doc/khal

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
