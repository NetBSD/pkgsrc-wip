# $NetBSD: Makefile,v 1.10 2005/08/11 10:08:21 absd Exp $
#

DISTNAME=		damageext-1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/DamageExt
COMMENT=		X Damage extension headers and specification

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	damageext.pc.in

.include "../../x11/fixesext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
