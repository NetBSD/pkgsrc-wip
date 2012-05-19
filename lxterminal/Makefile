# $NetBSD: Makefile,v 1.4 2012/05/19 05:29:49 jeremy-c-reed Exp $

DISTNAME=	lxterminal-0.1.11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.org/
COMMENT=	Desktop-independent VTE-based terminal emulator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
