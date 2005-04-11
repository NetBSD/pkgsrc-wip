# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:42 tvierling Exp $

DISTNAME=	panoramixext-1.1
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xlib.freedesktop.org/
COMMENT=	Header files for the X PanoramiX extension

CONFLICTS+=	XFree86-libs-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	panoramixext.pc.in

.include "../../mk/bsd.pkg.mk"
