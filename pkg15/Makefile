# $NetBSD: Makefile,v 1.3 2015/02/20 13:55:49 khorben Exp $
#

GHCOMMIT=	d7d7a7f532ce90d41f7c146b209b5c34808f8b09
DISTNAME=	${GHCOMMIT}
PKGNAME=	pkg15-1.4.99.11.20150220
PKGREVISION=	2
CATEGORIES=	pkgtools
MASTER_SITES=	https://github.com/freebsd/pkg/archive/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/freebsd/pkg/archive/
COMMENT=	Package management tool for FreeBSD
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/pkg-${GHCOMMIT}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf
USE_TOOLS+=	automake
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

AUTO_MKDIRS=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/pkg.conf.sample ${DESTDIR}${PREFIX}/share/doc/pkg/pkg.conf.sample

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
