# $NetBSD: Makefile,v 1.3 2003/12/05 18:36:02 mpasternak Exp $

DISTNAME=		GTK2-Smooth-Engine
PKGNAME=		gtk2-engines-smooth-0
WRKSRC=			${WRKDIR}/smooth-engine
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Smooth theme engine for GTK+ 2.x

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
