# $NetBSD: Makefile,v 1.9 2005/07/21 16:33:57 thomasklausner Exp $
#

DISTNAME=		damageext-1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/DamageExt
COMMENT=		X Damage extension headers and specification

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	damageext.pc.in

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
