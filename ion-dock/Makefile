# $NetBSD: Makefile,v 1.1.1.1 2003/04/03 09:29:50 cubidou Exp $
#

DISTNAME=	ion-dock-20030330
CATEGORIES=	x11
MASTER_SITES=	http://kanin.dsv.su.se/ion/dock/

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://kanin.dsv.su.se/ion/dock/
COMMENT=	ion module that enables docking

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GMAKE=		YES
USE_X11=		YES

PKG_SYSCONFSUBDIR=	ion

CONF_FILES=		${PREFIX}/share/examples/ion/dock.conf ${PKG_SYSCONFDIR}/dock.conf

.include "../../local/ion-devel/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
