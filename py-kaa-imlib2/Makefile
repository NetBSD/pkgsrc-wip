# $NetBSD: Makefile,v 1.2 2008/02/18 03:00:33 dhowland Exp $
#

DISTNAME=		kaa-imlib2-0.2.3
PKGNAME=                ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://freevo.sourceforge.net/cgi-bin/freevo-2.0/Kaa
COMMENT=		Imlib2 wrapper for the Kaa multimedia framework

PYDISTUTILSPKG=		yes

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/py-kaa-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
