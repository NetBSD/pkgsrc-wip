# $NetBSD: Makefile,v 1.2 2004/06/13 18:56:28 thomasklausner Exp $

DISTNAME=		QUANTA-0.3
PKGNAME=		net-quanta-0.3
WRKSRC=			${WRKDIR}/QUANTA_0.3
CATEGORIES=		net
MASTER_SITES=		http://www.evl.uic.edu/cavern/quanta/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.evl.uic.edu/cavern/quanta/
COMMENT=		Toolkit for extremely high bandwidth networking

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CXXFLAGS="${PTHREAD_CFLAGS} ${EXTRA_LDFLAGS}"
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
EXTRA_LDFLAGS=		"-lcompat"	# XXX need this for ftime(3)
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
