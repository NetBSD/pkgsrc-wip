# $NetBSD: Makefile,v 1.8 2020/02/19 19:07:19 adam Exp $

DISTNAME=	buildbot-pkg-${BBVERSION}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-pkg/}

COMMENT=	Packaging tools for the buildbot CI system

DEPENDS+=	${PYPKGPREFIX}-setuptools>=21.2.1:../../devel/py-setuptools

USE_LANGUAGES=	# none

# override default versioning based on time stamp
MAKE_ENV+=	BUILDBOT_VERSION=${PKGVERSION_NOREV}

.include "../../wip/py-buildbot/Makefile.common"
