# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 01:20:07 xtraeme Exp $
#

DISTNAME=		fixesext-2.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		header files and documentation for the X RandR extension		

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/fixesext.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
