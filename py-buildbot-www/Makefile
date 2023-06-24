# $NetBSD: Makefile,v 1.12 2020/03/23 09:44:44 tnn Exp $

DISTNAME=	buildbot-www-${BBVERSION}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-www/}

COMMENT=	Web frontend for the buildbot CI system

DEPENDS+=	${PYPKGPREFIX}-buildbot-[0-9]*:../../wip/py-buildbot
TOOL_DEPENDS+=	${PYPKGPREFIX}-buildbot-pkg-[0-9]*:../../wip/py-buildbot-pkg
TOOL_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	pip:build

.include "../../lang/python/versioned_dependencies.mk"
.include "../../wip/py-buildbot/Makefile.common"
