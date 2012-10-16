# $NetBSD: Makefile,v 1.1 2012/10/16 22:09:40 khorben Exp $

DISTNAME=	libgtkstylus-0.3
CATEGORIES=	x11
MASTER_SITES=	http://gpe.linuxtogo.org/download/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://gpe.linuxtogo.org/
COMMENT=	Gtk+ 2 third-button emulation library

LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes

USE_LIBTOOL=	yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
