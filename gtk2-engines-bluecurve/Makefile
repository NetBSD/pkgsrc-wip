# $NetBSD: Makefile,v 1.3 2004/01/25 02:23:04 grantbeattie Exp $

DISTNAME=		GTK2-Wonderland-Engine-1.0
PKGNAME=		gtk2-engines-bluecurve-1.0
WRKSRC=			${WRKDIR}/Bluecurve
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Port of famous Bluecurve theme, introduced by RedHat

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
