# $NetBSD: Makefile,v 1.9 2012/10/03 09:10:42 asau Exp $

DISTNAME=	nfs-utils-1.0.6
PKGNAME=	linux-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nfs/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://sourceforge.net/projects/nfs/
COMMENT=	Linux NFS client and server utilities


GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

# uses linux/version.h and only tested under Linux
ONLY_FOR_PLATFORM=	Linux-*-*

RCD_SCRIPTS=		mountd nfsd nfslocking

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
