# $NetBSD: Makefile,v 1.1.1.1 2004/03/17 19:35:45 poppnk Exp $
#

DISTNAME=		gzrt-0.2
PKGNAME=		gzrecover-0.2
CATEGORIES=		wip archivers
MASTER_SITES=		http://www.urbanophile.com/arenn/hacking/gzrt/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.urbanophile.com/arenn/hacking/gzrt/
COMMENT=		GZip Recovery Toolkit

ALL_TARGET=		gzrecover
USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gzrecover ${PREFIX}/bin/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
