# $NetBSD: Makefile,v 1.2 2003/11/29 20:34:30 jeremy-c-reed Exp $
#

DISTNAME=		fixesext-2.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		X Fixes extension headers and specification

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/fixesext.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
