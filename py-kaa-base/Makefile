# $NetBSD: Makefile,v 1.2 2008/02/18 02:59:37 dhowland Exp $
#

DISTNAME=		kaa-base-0.3.0
PKGNAME=                ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://freevo.sourceforge.net/cgi-bin/freevo-2.0/Kaa
COMMENT=		Base module for the Kaa multimedia framework

PYDISTUTILSPKG=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
