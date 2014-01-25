# $NetBSD: Makefile,v 1.7 2014/01/25 10:38:19 thomasklausner Exp $

DISTNAME=	graphite-web-0.9.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://launchpadlibrarian.net/106575888/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/graphite
COMMENT=	Enterprise scalable realtime graphing platform
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-carbon>=${PKGREVISION_NOREV}:../../wip/py-carbon
DEPENDS+=	${PYPKGPREFIX}-django>=1.3.1:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-tagging>=0.3.1:../../www/py-django-tagging

USE_LANGUAGES=	# none
PYTHON_VERSIONED_DEPENDENCIES=	cairo

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-django-tagging

INSTALLATION_DIRS+=	share/examples/graphite

PLIST_SUBST+=	THIS_EGG_FILE=${EGG_NAME:S|graphite-|graphite_|}-py${PYVERSSUFFIX}.egg-info

pre-build:
	${MKDIR} ${WRKSRC}/graphite/webapp
	${CP} -LR ${WRKSRC}/webapp/content ${WRKSRC}/graphite/webapp

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
