# $NetBSD: Makefile,v 1.5 2004/01/31 22:10:04 minskim Exp $
#

DISTNAME=		fixesext-2.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/FixesExt
COMMENT=		X Fixes extension headers and specification

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/fixesext.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
