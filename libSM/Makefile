# $NetBSD: Makefile,v 1.4 2004/05/07 01:58:00 xtraeme Exp $
#

DISTNAME=		libSM-6.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		SM Extension

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/sm.pc.in

# XXX does not have an option to disable xthread;
# XXX it is based on how libX11 was built.
#PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink2.mk"

.include "../../wip/libICE/buildlink2.mk"
.include "../../wip/libX11/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
