# $NetBSD: Makefile,v 1.5 2006/02/11 16:20:06 obache Exp $
#

DISTNAME=	libupnp-1.2.1a
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=upnp/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://upnp.sourceforge.net/
COMMENT=	Linux SDK for UPnP Devices

USE_PKGINSTALL=	yes
USE_TOOLS+=	gmake

BUILD_DIRS=	upnp
MAKEFILE=	makefile

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin" || ${OPSYS} == "BSDOS"
MAKE_ENV+=	EXTRA_LIBS="-lcompat"      # XXX need this for ftime(3)
.else
MAKE_ENV+=	EXTRA_LIBS=""
.endif

do-install:
.for d in upnp ixml threadutil
	cd ${WRKDIR:Q}/${DISTNAME:Q}/${d} && ${SETENV} ${MAKE_ENV} ${GMAKE} install
.endfor

.include "../../wip/libuuid/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
