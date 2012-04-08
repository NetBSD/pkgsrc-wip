# $NetBSD: Makefile,v 1.5 2012/04/08 19:09:47 thomasklausner Exp $
#

DISTNAME=		kaa-metadata-0.7.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://freevo.sourceforge.net/cgi-bin/freevo-2.0/Kaa
COMMENT=		Media metadata parser for the Kaa multimedia framework

PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	25

.include "../../lang/python/extension.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../wip/py-kaa-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
