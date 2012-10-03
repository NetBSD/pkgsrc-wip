# $NetBSD: Makefile,v 1.5 2012/10/03 08:27:28 asau Exp $
#

DISTNAME=	libopensync-plugin-moto-0.22
CATEGORIES=	comms
MASTER_SITES=	http://www.opensync.org/attachment/wiki/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensync.org/attachment/wiki/download/
COMMENT=	Moto plugin for opensync (for Motorola phones)

DEPENDS+=	${PYPKGPREFIX}-libopensync-plugin>=0.22:../../wip/py-libopensync-plugin
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.0:../../time/py-dateutil

PYTHON_VERSIONS_ACCEPTED=	25
USE_TOOLS+=			pkg-config:run

INSTALLATION_DIRS=		bin lib/opensync/python-plugins share/opensync/defaults

SUBST_CLASSES+=		python
SUBST_SED.python=	-e 's,/usr/bin/env python,${PYTHONBIN},'
SUBST_FILES.python=	mototool
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Replacing python interpreter.

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mototool ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/motosync.py ${DESTDIR}${PREFIX}/lib/opensync/python-plugins
	${INSTALL_DATA} ${WRKSRC}/moto-sync ${DESTDIR}${PREFIX}/share/opensync/defaults

.include "../../comms/libopensync/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
