# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 02:51:58 mpasternak Exp $

DISTNAME=		GTK2-Industrial
PKGNAME=		gtk2-engines-industrial-0
WRKSRC=			${WRKDIR}/GTK2-Industrial-Engine
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Theme engine for GTK+ 2.x

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${PREFIX}

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
