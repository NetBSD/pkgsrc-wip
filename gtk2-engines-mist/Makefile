# $NetBSD: Makefile,v 1.7 2004/08/17 18:27:38 tvierling Exp $

DISTNAME=		gtk-mist-engine-0.10
PKGNAME=		gtk2-engines-mist-0.10
CATEGORIES=		x11
MASTER_SITES=		http://primates.ximian.com/~dave/mist/

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://primates.ximian.com/~dave/mist/
COMMENT=		Flat engine for GTK+ 2.x

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES

USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/engines/libmist.la
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
