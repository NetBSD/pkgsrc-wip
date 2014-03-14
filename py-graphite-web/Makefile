# $NetBSD: Makefile,v 1.8 2014/03/14 08:54:56 fhajny Exp $

DISTNAME=	graphite-web-0.9.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	-https://github.com/graphite-project/graphite-web/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

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

EGG_NAME=	${DISTNAME:S/graphite-/graphite_/}

pre-build:
	${MKDIR} ${WRKSRC}/graphite/webapp
	${CP} -LR ${WRKSRC}/webapp/content ${WRKSRC}/graphite/webapp

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
