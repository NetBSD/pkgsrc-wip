# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-octoprint-1.3.11
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=foosel/}
GITHUB_PROJECT=	OctoPrint
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/foosel/OctoPrint/
COMMENT=	Snappy web interface for 3D printers
LICENSE=	gnu-agpl-v3

PYTHON_VERSIONS_ACCEPTED=	27

#TODO register the remaining dependencies (see https://github.com/foosel/OctoPrint/blob/master/setup.py#L19)
DEPENDS+=	${PYPKGPREFIX}-typing>=3.6.6:../../devel/py-typing

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
