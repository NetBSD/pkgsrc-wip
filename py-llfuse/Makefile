# $NetBSD: Makefile,v 1.1 2015/08/22 13:50:45 thomasklausner Exp $

DISTNAME=	llfuse-0.41
CATEGORIES=	filesystems
MASTER_SITES=	https://pypi.python.org/packages/source/l/llfuse/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/llfuse/
COMMENT=	Python bindings for low-level FUSE API
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

.include "../../lang/python/egg.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
