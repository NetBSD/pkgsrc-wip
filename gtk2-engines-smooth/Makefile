# $NetBSD: Makefile,v 1.6 2004/03/01 15:55:05 mpasternak Exp $

DISTNAME=		GTK2-Smooth-Engine
PKGNAME=		gtk2-engines-smooth-0.5.6
WRKSRC=			${WRKDIR}/gtk-smooth-engine-0.5.6
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Smooth theme engine for GTK+ 2.x

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

post-install:
	cd ${WRKSRC}/themes/Delightfully-Smooth/gtk2/ && \
		${SETENV} ${MAKE_ENV} ${MAKE} install

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
