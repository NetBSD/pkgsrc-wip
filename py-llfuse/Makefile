# $NetBSD: Makefile,v 1.2 2015/08/22 16:20:34 thomasklausner Exp $

DISTNAME=	llfuse-0.41
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_PYPI:=l/llfuse/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/llfuse/
COMMENT=	Python bindings for low-level FUSE API
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

.include "../../lang/python/egg.mk"
.include "../../filesystems/fuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
