# $NetBSD: Makefile,v 1.17 2012/09/29 00:50:41 asau Exp $

DISTNAME=		dwerg-default-${DWERG_VERSION}
DWERG_VERSION=		0.8
PKGNAME=		gtk2-engines-dwerg-${DWERG_VERSION}
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://download.freshmeat.net/themes/dwerg/
EXTRACT_SUFX=		.tar.gz
WRKSRC=	${WRKDIR}/gtk-engines-dwerg-${DWERG_VERSION}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://themes.freshmeat.net/projects/dwerg/
COMMENT=		Theme engine for GTK+ 2.x

PKG_DESTDIR_SUPPORT=	none

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
