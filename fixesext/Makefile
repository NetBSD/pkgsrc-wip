# $NetBSD: Makefile,v 1.9 2004/05/09 04:16:05 minskim Exp $
#

DISTNAME=		fixesext-2.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/FixesExt
COMMENT=		X Fixes extension headers and specification

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	fixesext.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
