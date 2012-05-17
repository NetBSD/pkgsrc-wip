# $NetBSD: Makefile,v 1.3 2012/05/17 04:20:52 jeremy-c-reed Exp $

DISTNAME=	lxde-common-0.5.5
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.gz

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

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
