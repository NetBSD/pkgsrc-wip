# $NetBSD: Makefile,v 1.7 2012/10/07 12:25:12 asau Exp $
#

DISTNAME=		kaa-base-0.3.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://freevo.sourceforge.net/cgi-bin/freevo-2.0/Kaa
COMMENT=		Base module for the Kaa multimedia framework

PKG_DESTDIR_SUPPORT=	none

USE_TOOLS+=		pkg-config

PYDISTUTILSPKG=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
