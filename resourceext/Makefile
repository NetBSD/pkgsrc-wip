# $NetBSD: Makefile,v 1.2 2004/02/10 18:45:56 jeremy-c-reed Exp $
#

DISTNAME=		resourceext-1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X Resource usage extension headers

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/resourceext.pc.in

.include "../../mk/bsd.pkg.mk"
