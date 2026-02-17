# $NetBSD: Makefile,v 1.12 2020/03/23 09:44:44 tnn Exp $

DISTNAME=	buildbot_www-${BBVERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-www/}

COMMENT=	Web frontend for the buildbot CI system

TOOL_DEPENDS+=	${PYPKGPREFIX}-buildbot-pkg-[0-9]*:../../wip/py-buildbot-pkg
DEPENDS+=	${PYPKGPREFIX}-buildbot-[0-9]*:../../wip/py-buildbot

USE_LANGUAGES=	# none

.include "../../wip/py-buildbot/Makefile.common"
.include "../../mk/bsd.pkg.mk"
