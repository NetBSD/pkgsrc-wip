# $NetBSD: Makefile,v 1.8 2020/02/19 19:07:18 adam Exp $

DISTNAME=	buildbot_console_view-${BBVERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-console-view/}

COMMENT=	Waterfall Plugin for the buildbot CI system

TOOL_DEPENDS+=	${PYPKGPREFIX}-buildbot-pkg-[0-9]*:../../wip/py-buildbot-pkg

USE_LANGUAGES=	# none

.include "../../wip/py-buildbot/Makefile.common"
.include "../../mk/bsd.pkg.mk"
