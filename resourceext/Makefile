# $NetBSD: Makefile,v 1.3 2004/05/02 22:06:22 blef Exp $
#

DISTNAME=		resourceext-1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X Resource usage extension headers

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/resourceext.pc.in

.include "../../mk/bsd.pkg.mk"
