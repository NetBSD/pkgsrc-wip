# $NetBSD: Makefile,v 1.6 2012/11/24 02:35:07 jeremy-c-reed Exp $

DISTNAME=	lxde-common-0.5.5
PKGREVISION=	1
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	Default configuration settings and scripts for LXDE
LICENSE=	gnu-gpl-v2

DEPENDS+=	dbus>=1:../../sysutils/dbus
# Clearlooks is default GTK theme for the LXDE lxsession
DEPENDS+=	gtk2-engines>=0:../../x11/gtk2-engines
DEPENDS+=	lxpanel>=0:../../wip/lxpanel
DEPENDS+=	lxsession>=0:../../wip/lxsession
DEPENDS+=	openbox>=0:../../wm/openbox
DEPENDS+=	xprop>=0:../../x11/xprop

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
