# $NetBSD: Makefile,v 1.8 2006/03/14 01:28:01 jlamwww Exp $
#

DISTNAME=	libupnp-1.2.1a
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=upnp/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://upnp.sourceforge.net/
COMMENT=	Linux SDK for UPnP Devices

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
	cd ${WRKDIR:Q}/${DISTNAME:Q}/${d:Q} && ${SETENV} ${MAKE_ENV} ${GMAKE} install
.endfor

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
