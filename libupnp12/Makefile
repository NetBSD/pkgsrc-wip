# $NetBSD: Makefile,v 1.1.1.1 2005/09/24 14:46:02 obache Exp $
#

DISTNAME=	libupnp-1.2.1a
CATEGORIES=	devel net
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=upnp/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://upnp.sourceforge.net/
COMMENT=	Linux SDK for UPnP Devices

USE_PKGINSTALL=	yes
USE_TOOLS+= gmake gcc

BUILD_DIRS=	${WRKDIR}/${DISTNAME}/upnp
MAKEFILE=       makefile

do-install:
.for d in upnp ixml threadutil
	cd ${WRKDIR}/${DISTNAME}/${d} && ${SETENV} ${MAKE_ENV} ${GMAKE} install
.endfor

.include "../../wip/libuuid/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
