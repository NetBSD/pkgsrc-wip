# $NetBSD: Makefile,v 1.6 2004/06/09 02:57:49 minskim Exp $
#

DISTNAME=		damageext-1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/DamageExt
COMMENT=		X Damage extension headers and specification

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	damageext.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../wip/fixesext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
