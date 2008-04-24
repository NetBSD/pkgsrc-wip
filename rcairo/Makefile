# $NetBSD: Makefile,v 1.1.1.1 2008/04/24 13:05:13 obache Exp $
#

DISTNAME=		rcairo-1.6.0
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/releases/

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://cairographics.org/rcairo/
COMMENT=		Ruby bindings for cairo

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

USE_TOOLS+=		pkg-config

RUBY_HAS_ARCHLIB=	YES
USE_RUBY_EXTCONF=	YES

#CONFIGURE_ENV+=		PKG_CONFIG_PATH=${_PKG_CONFIG_LIBDIR:Q}
#CONFIGURE_ENV+=		PKG_CONFIG_PATH=${BUILDLINK_DIR:Q}/lib/pkg-config
#CONFIGURE_ENV+=        PKG_CONFIG=${BUILDLINK_DIR:Q}/bin/pkg-config

.include "../../lang/ruby/modules.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
