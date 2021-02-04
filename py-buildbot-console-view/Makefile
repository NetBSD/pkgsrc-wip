# $NetBSD: Makefile,v 1.8 2020/02/19 19:07:18 adam Exp $

DISTNAME=	buildbot-console-view-${BBVERSION}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-console-view/}

COMMENT=	Waterfall Plugin for the buildbot CI system

DEPENDS+=	${PYPKGPREFIX}-buildbot-[0-9]*:../../wip/py-buildbot
BUILD_DEPENDS+=	${PYPKGPREFIX}-buildbot-pkg-[0-9]*:../../wip/py-buildbot-pkg

USE_LANGUAGES=	# none

.include "../../wip/py-buildbot/Makefile.common"
