# $NetBSD: Makefile,v 1.1.1.1 2005/03/13 12:41:20 obache Exp $
#

DISTNAME=	upnpsdk-1.0.4
PKGNAME=        libupnp-1.0.4
CATEGORIES=	devel net
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=upnp/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://upnp.sourceforge.net/
COMMENT=	Linux SDK for UPnP Devices

USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes
USE_GNU_TOOLS+= make

MAKEFILE=       makefile

PTHREAD_OPTS+=	require

.include "../../wip/libuuid/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} != "native"
PTHREAD_CFLAGS+=-D_POSIX_THREAD_SYSCALL_SOFT=1
.endif
.include "../../mk/bsd.pkg.mk"
