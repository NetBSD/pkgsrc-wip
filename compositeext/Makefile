# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 01:25:05 xtraeme Exp $
#

DISTNAME=		compositeext-2.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Header and documentation files for Composite extension		

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/compositeext.pc.in

.include "../../wip/fixesext/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
