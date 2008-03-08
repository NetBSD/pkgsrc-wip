# $NetBSD: Makefile,v 1.3 2008/03/08 19:00:00 dhowland Exp $
#

DISTNAME=		kaa-base-0.3.0
PKGNAME=                ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freevo/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://freevo.sourceforge.net/cgi-bin/freevo-2.0/Kaa
COMMENT=		Base module for the Kaa multimedia framework

USE_TOOLS+=		pkg-config

PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	25 24

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
