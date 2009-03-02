# $NetBSD: Makefile,v 1.2 2009/03/02 22:19:38 hoka_adam Exp $
#

DISTNAME=		pyxdg-0.15
PKGNAME=		${PYPKGPREFIX}-xdg-0.15
CATEGORIES=		sysutils python
MASTER_SITES=		http://www.freedesktop.org/~lanius/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://pyxdg.freedesktop.org/
COMMENT=		XDG handling library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
