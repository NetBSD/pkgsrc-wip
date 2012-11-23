# $NetBSD: Makefile,v 1.18 2012/11/23 22:44:43 othyro Exp $

DISTNAME=	dwerg-default-${DWERG_VERSION}
DWERG_VERSION=	0.8
PKGNAME=	gtk2-engines-dwerg-${DWERG_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.freshmeat.net/themes/dwerg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://themes.freshmeat.net/projects/dwerg/
COMMENT=	Theme engine for GTK+ 2.x

PKG_DESTDIR_SUPPORT=	none

WRKSRC=		${WRKDIR}/gtk-engines-dwerg-${DWERG_VERSION}/
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
