# $NetBSD: Makefile,v 1.3 2004/02/19 00:35:57 minskim Exp $
#

DISTNAME=		TTFQuery-0.2.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ttfquery/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://ttfquery.sourceforge.net/
COMMENT=		Query TTF font files for metadata and font outlines

USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-fonttools>=2.0b1:../../fonts/py-fonttools

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
