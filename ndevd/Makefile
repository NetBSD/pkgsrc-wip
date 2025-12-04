# $NetBSD$

DISTNAME=	ndevd-25.08.20
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kikadf/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/kikadf/ndevd/
COMMENT=	NetBSD devpubd + event forwarding to clients
LICENSE=	original-bsd

USE_TOOLS+=	sed

NO_CONFIGURE=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX} \
		MANDIR=${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
