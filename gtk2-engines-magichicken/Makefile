# $NetBSD: Makefile,v 1.1.1.1 2003/11/26 22:29:12 mpasternak Exp $

DISTNAME=		GTK2-mgicchikn-1.0.2
PKGNAME=		gtk2-engines-magichicken-1.0.2
WRKSRC=			${WRKDIR}/mgicchikn-1.0.2/
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

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
