# $NetBSD: Makefile,v 1.1 2009/09/06 21:57:47 khorben Exp $
#

DISTNAME=	Browser-0.1.2
PKGNAME=	deforaos-browser-0.1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.defora.org/os/download/download/3266/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop file browser

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=$(PREFIX)
MAKE_FLAGS+=	DESTDIR=$(DESTDIR)

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
