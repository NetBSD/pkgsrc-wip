# $NetBSD: Makefile,v 1.7 2012/04/08 19:09:47 thomasklausner Exp $
#

DISTNAME=		kaa-imlib2-0.2.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://freevo.sourceforge.net/cgi-bin/freevo-2.0/Kaa
COMMENT=		Imlib2 wrapper for the Kaa multimedia framework

PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	25

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/py-kaa-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
