# $NetBSD: Makefile,v 1.6 2005/05/24 10:30:45 rillig Exp $

DISTNAME= 	nfs-utils-1.0.6
PKGNAME=	linux-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nfs/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://sourceforge.net/projects/nfs/
COMMENT=	Linux NFS client and server utilities

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

# uses linux/version.h and only tested under Linux
ONLY_FOR_PLATFORM=	Linux-*-*

RCD_SCRIPTS=		mountd nfsd nfslocking

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
