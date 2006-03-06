# $NetBSD: Makefile,v 1.1.1.1 2006/03/06 15:12:54 poppnk Exp $
#

DISTNAME=		gjots2-2.3.4
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
