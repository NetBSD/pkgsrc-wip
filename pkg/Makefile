# $NetBSD: Makefile,v 1.3 2015/02/15 21:37:09 khorben Exp $
#

PKGVERSION=	1.4.12
PKGNAME=	pkg-${PKGVERSION}
DISTNAME=	${PKGVERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	https://github.com/freebsd/pkg/archive/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/freebsd/pkg/archive/
COMMENT=	Package management tool for FreeBSD
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${PKGNAME}

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf
USE_TOOLS+=	automake
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/libelf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
