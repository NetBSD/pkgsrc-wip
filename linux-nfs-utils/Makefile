# $NetBSD: Makefile,v 1.3 2004/01/25 02:23:56 grantbeattie Exp $

DISTNAME= 	nfs-utils-1.0.1
PKGREVISION=	1
PKGNAME=	linux-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nfs/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://sourceforge.net/projects/nfs/
COMMENT=	Linux NFS client and server utilities

USE_BUILDLINK2=	# defined
USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

# uses linux/version.h and only tested under Linux
ONLY_FOR_PLATFORM=	Linux-*-*

RCD_SCRIPTS=		mountd nfsd nfslocking

.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
