# $NetBSD: Makefile,v 1.12 2005/08/11 10:08:22 absd Exp $
#

DISTNAME=		libSM-6.0.3
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		SM Extension

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	sm.pc.in

# XXX does not have an option to disable xthread;
# XXX it is based on how libX11 was built.
#PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"

.include "../../wip/libICE/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
