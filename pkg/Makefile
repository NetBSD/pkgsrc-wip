# $NetBSD: Makefile,v 1.2 2015/02/15 19:43:19 khorben Exp $
#

DISTNAME=	pkg-1.4.12
CATEGORIES=	pkgtools
MASTER_SITES=	https://github.com/freebsd/pkg/archive/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/freebsd/pkg/archive/
COMMENT=	Package management tool for FreeBSD
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf
USE_TOOLS+=	automake
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/libelf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
