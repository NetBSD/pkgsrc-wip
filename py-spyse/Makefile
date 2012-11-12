# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:51 othyro Exp $
#

DISTNAME=	spyse-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spyse/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pastiche/
COMMENT=	Spyse is a framework and platform for building multi-agent systems
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/spyse
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
