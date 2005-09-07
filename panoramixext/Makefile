# $NetBSD: Makefile,v 1.3 2005/09/07 16:24:57 leonardschmidt Exp $

DISTNAME=	panoramixext-1.1
CATEGORIES=	x11
MASTER_SITES=	http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xlib.freedesktop.org/
COMMENT=	Header files for the X PanoramiX extension

CONFLICTS+=	XFree86-libs-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	panoramixext.pc.in

.include "../../mk/bsd.pkg.mk"
