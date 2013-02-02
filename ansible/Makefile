# $NetBSD: Makefile,v 1.2 2013/02/02 20:42:22 noud4 Exp $
#

DISTNAME=		ansible-1.0
CATEGORIES=		sysutils
THIS_EGG_FILE=		${PKGNAME}-py${PYVERSSUFFIX}.egg-info # XXX
CATEGORIES=		sysutils
MASTER_SITES=		http://ansible.cc/releases/

MAINTAINER=		noud4@home.nl
HOMEPAGE=		http://ansible.cc/
COMMENT=		Deploy, manage, and orchestrate computer systems
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=		${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=		${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2

DIST_SUBDIR=		ansible
#USE_LANGUAGES=		# none
USE_TOOLS+=		gmake

REPLACE_PYTHON+=	library/*

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	lib/ansible/constants.py \
			library/pkgin
SUBST_SED.prefix=	-e "s,@PREFIX@,${PREFIX},"

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	Makefile
SUBST_SED.python=	-e "s,@PYTHON@,python${PYVERSSUFFIX},"

PLIST_SUBST+=		THIS_EGG_FILE=${THIS_EGG_FILE}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
