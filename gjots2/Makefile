# $NetBSD: Makefile,v 1.7 2012/11/14 00:16:07 othyro Exp $
#

DISTNAME=		gjots2-2.3.4
PKGREVISION=		4
CATEGORIES=		x11
MASTER_SITES=		http://bhepple.freeshell.org/gjots/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://bhepple.freeshell.org/gjots/
COMMENT=		Jotter application for your Gnome desktop

PYDISTUTILSPKG= yes
USE_TOOLS+=		pkg-config


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
