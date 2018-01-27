# $NetBSD: Makefile,v 1.2 2012/10/03 18:15:31 asau Exp $
#

DISTNAME=	ncp-1.2.4
CATEGORIES=	net
MASTER_SITES=	http://dl.fefe.de/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fefe.de/ncp/
COMMENT=	Fast file copy tool for LANs
#LICENSE=	asked upstream, will fill in when he replies

CFLAGS+=		-I${BUILDLINK_PREFIX.libowfat}/include/libowfat
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

.include "../../devel/libowfat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
