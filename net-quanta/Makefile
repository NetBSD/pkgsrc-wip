# $NetBSD: Makefile,v 1.7 2012/10/03 18:15:31 asau Exp $

DISTNAME=		QUANTA-0.3
PKGNAME=		net-quanta-0.3
WRKSRC=			${WRKDIR}/QUANTA_0.3
CATEGORIES=		net
MASTER_SITES=		http://www.evl.uic.edu/cavern/quanta/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.evl.uic.edu/cavern/quanta/
COMMENT=		Toolkit for extremely high bandwidth networking

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CXXFLAGS="${PTHREAD_CFLAGS} ${EXTRA_LDFLAGS}"
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
EXTRA_LDFLAGS=		"-lcompat"	# XXX need this for ftime(3)
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
