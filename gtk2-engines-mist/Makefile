# $NetBSD: Makefile,v 1.2 2003/06/23 17:52:38 blef Exp $

DISTNAME=		gtk-mist-engine-0.10
PKGNAME=		gtk2-engines-mist-0.10
CATEGORIES=		x11
MASTER_SITES=		http://primates.ximian.com/~dave/mist/

MAINTAINER=		soren@blef.org
HOMEPAGE=		http://primates.ximian.com/~dave/mist/
COMMENT=		flat engine for GTK+ 2.x

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
