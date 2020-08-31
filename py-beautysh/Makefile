# $NetBSD$

GITHUB_PROJECT=	beautysh
DISTNAME=	beautysh-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bemeurer/}
EXTRACT_USING=	bsdtar

MAINTAINER=	robn@gmx.com
HOMEPAGE=	https://github.com/bemeurer/beautysh/
COMMENT=	Bash beautifier for the masses
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

REPLACE_PYTHON+=	beautysh/beautysh.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
