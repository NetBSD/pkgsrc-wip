# $NetBSD: Makefile,v 1.1 2013/02/02 05:30:16 noud4 Exp $
#

DISTNAME=		devel
PKGNAME=		ansible-1.1
THIS_EGG_FILE=		${PKGNAME}-py${PYVERSSUFFIX}.egg-info # XXX
CATEGORIES=		sysutils
MASTER_SITES=		https://github.com/ansible/ansible/archive/
EXTRACT_SUFX=		.zip

MAINTAINER=		noud4@home.nl
HOMEPAGE=		http://ansible.cc/
COMMENT=		SSH-based management, deployment, and task execution system
COMMENT=		deploy, manage, and orchestrate computer systems
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=		${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=		${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2

# fetch from https - fails with ftp
FETCH_USING=	curl

DIST_SUBDIR=		ansible
#USE_LANGUAGES=		# none
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/ansible-devel
REPLACE_PYTHON+=	library/*

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	lib/ansible/constants.py
SUBST_SED.prefix=	-e "s,@PREFIX@,${PREFIX},"

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	Makefile
SUBST_SED.python=	-e "s,@PYTHON@,python${PYVERSSUFFIX},"

PLIST_SUBST+=		THIS_EGG_FILE=${THIS_EGG_FILE}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
