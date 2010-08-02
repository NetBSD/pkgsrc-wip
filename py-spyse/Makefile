# $NetBSD: Makefile,v 1.1.1.1 2010/08/02 21:38:35 jihbed Exp $
#

DISTNAME=	spyse-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://garr.dl.sourceforge.net/project/spyse/spyse/0.2%20-%20latest%20version/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pastiche/
COMMENT=	Spyse is a framework and platform for building multi-agent systems
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/spyse
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
