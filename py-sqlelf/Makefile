# $NetBSD$

DISTNAME=		sqlelf-0.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=fzakaria/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/fzakaria/sqlelf/
COMMENT=		Explore ELF objects through the power of SQL
LICENSE=		mit

PYTHON_VERSIONS_ACCEPTED= 311 310
USE_LANGUAGES=		c c++

# TOOL_DEPENDS:
# setuptools
# setuptools-scm[toml]
# setuptools.build_meta

DEPENDS+=		${PYPKGPREFIX}-apsw>=3.43.1.0:../../databases/py-apsw
DEPENDS+=		${PYPKGPREFIX}-capstone>=5.0.1:../../devel/py-capstone
DEPENDS+=		${PYPKGPREFIX}-lief>=0.14.0:../../wip/lief
DEPENDS+=		${PYPKGPREFIX}-sh>=2.0.6:../../sysutils/py-sh

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
