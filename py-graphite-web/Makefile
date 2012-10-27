# $NetBSD: Makefile,v 1.5 2012/10/27 16:52:10 noud4 Exp $
#

DISTNAME=	graphite-web-0.9.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://launchpadlibrarian.net/106575888/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/graphite
COMMENT=	Enterprise scalable realtime graphing platform
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cairo>=1.8.10:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-carbon>=${PKGREVISION_NOREV}:../../wip/py-carbon
DEPENDS+=	${PYPKGPREFIX}-django>=1.3.1:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-tagging>=0.3.1:../../wip/py-django-tagging

USE_LANGUAGES=	# none

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE GRAPHITE_DIR

GRAPHITE_DIR?=		${VARBASE}/graphite
GRAPHITE_EGDIR?=	share/examples/graphite

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	pre-configure
SUBST_MESSAGE.dirs=	Patching default storage directory
SUBST_FILES.dirs=	setup.py
SUBST_VARS.dirs=	GRAPHITE_DIR GRAPHITE_EGDIR PREFIX

PKG_SYSCONFSUBDIR=	graphite

GRAPHITE_CONF_FILES=	dashboard.conf graphite.wsgi graphTemplates.conf

.for file in ${GRAPHITE_CONF_FILES}
CONF_FILES+=		${GRAPHITE_EGDIR}/${file}.example	\
			${PKG_SYSCONFDIR}/${file}
.endfor

PYSETUPINSTALLARGS=	--prefix=${PREFIX}			\
			--install-lib=${PREFIX}/${PYSITELIB}

INSTALLATION_DIRS+=	share/examples/graphite

PLIST_SUBST+=	THIS_EGG_FILE=${EGG_NAME:S|graphite-|graphite_|}-py${PYVERSSUFFIX}.egg-info

pre-build:
	${MKDIR} ${WRKSRC}/graphite/webapp
	${CP} -LR ${WRKSRC}/webapp/content ${WRKSRC}/graphite/webapp

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
