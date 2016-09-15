# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-hidapi-0
CATEGORIES=	wip

GIT_REPOSITORIES=	cython-hidapi
GIT_REPO.cython-hidapi=	https://github.com/trezor/cython-hidapi.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trezor/cython-hidapi/
COMMENT=	Python wrapper for the hidapi
LICENSE=	gnu-gpl-v3 OR modified-bsd

WRKSRC=		${WRKDIR}/cython-hidapi

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/distutils.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
