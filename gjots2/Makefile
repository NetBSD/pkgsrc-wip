# $NetBSD: Makefile,v 1.2 2007/09/21 13:06:52 thomasklausner Exp $
#

DISTNAME=		gjots2-2.3.4
PKGREVISION=		1
CATEGORIES=		wip x11
MASTER_SITES=		http://bhepple.freeshell.org/gjots/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://bhepple.freeshell.org/gjots/
COMMENT=		A jotter application for your Gnome desktop

PYDISTUTILSPKG= yes
USE_TOOLS+=		pkg-config

.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
