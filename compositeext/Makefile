# $NetBSD: Makefile,v 1.3 2004/01/27 20:52:27 jeremy-c-reed Exp $
#

DISTNAME=		compositeext-2.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Headers and specification for X Composite extension

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/compositeext.pc.in

.include "../../wip/fixesext/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
