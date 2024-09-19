# $NetBSD$

DISTNAME=	go-python-0.1.0
GITHUB_PROJECT=	go-python
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=sbinet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sbinet/go-python/
COMMENT=	Naive go bindings towards the C-API of CPython-2
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	gmake

GO_DIST_BASE=	go-python-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/sbinet/go-python

PYTHON_VERSIONS_ACCEPTED= 27

.include "../../lang/go/go-package.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
