# $NetBSD$

DISTNAME=	cli_helpers-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cli_helpers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dbcli/cli_helpers
COMMENT=	Helpers for building command-line apps
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
