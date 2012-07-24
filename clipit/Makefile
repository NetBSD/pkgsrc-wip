# $NetBSD: Makefile,v 1.2 2012/07/24 23:53:31 khorben Exp $
#

DISTNAME=	clipit-1.4.1
CATEGORIES=	x11
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clipit/}
MASTER_SITES=	http://sourceforge.net/projects/gtkclipit/files/Version%201/
PKGREVISION=	1

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://clipit.rspwn.com/
COMMENT=	Lightweight, fully featured GTK+ clipboard manager

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR}

USE_TOOLS+=	gmake
USE_TOOLS+=	intltool

BUILD_DEFS+=	PKG_SYSCONFBASE

EGDIR=		${PREFIX}/share/examples/clipit
CONF_FILES=	${EGDIR}/xdg/autostart/clipit-startup.desktop \
		${PKG_SYSCONFBASE}/xdg/autostart/clipit-startup.desktop
MAKE_DIRS=	${PKG_SYSCONFBASE}/xdg/autostart

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}


.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
