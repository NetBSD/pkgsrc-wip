# $NetBSD: Makefile,v 1.5 2004/05/09 02:39:47 minskim Exp $
#

DISTNAME=		resourceext-1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X Resource usage extension headers

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	resourceext.pc.in

.include "../../mk/bsd.pkg.mk"
