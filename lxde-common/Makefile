# $NetBSD: Makefile,v 1.5 2012/11/23 22:44:43 othyro Exp $

DISTNAME=	lxde-common-0.5.5
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	Default configuration settings and scripts for LXDE
LICENSE=	gnu-gpl-v2

DEPENDS+=	dbus>=1:../../sysutils/dbus
DEPENDS+=	lxpanel>=0:../../wip/lxpanel
DEPENDS+=	lxsession>=0:../../wip/lxsession
DEPENDS+=	openbox>=0:../../wm/openbox
DEPENDS+=	xprop>=0:../../x11/xprop

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
