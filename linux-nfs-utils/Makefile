# $NetBSD: Makefile,v 1.4 2004/05/11 03:29:09 jeremy-c-reed Exp $

DISTNAME= 	nfs-utils-1.0.6
PKGNAME=	linux-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nfs/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://sourceforge.net/projects/nfs/
COMMENT=	Linux NFS client and server utilities

USE_BUILDLINK3=	# defined
USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

# uses linux/version.h and only tested under Linux
ONLY_FOR_PLATFORM=	Linux-*-*

RCD_SCRIPTS=		mountd nfsd nfslocking

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
