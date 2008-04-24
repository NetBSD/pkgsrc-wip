# $NetBSD: Makefile,v 1.2 2008/04/24 13:24:44 obache Exp $
#

DISTNAME=		rcairo-1.6.1
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

.include "../../lang/ruby/modules.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
