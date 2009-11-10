# $NetBSD: Makefile,v 1.4 2009/11/10 12:15:43 jihbed Exp $
#

DISTNAME=	pylast-0.4.18.tar
PKGNAME=	${PYPKGPREFIX}-last-0.4.18
CATEGORIES=	audio
EXTRACT_SUFX=	.gz#md5=e590200aa491edbc6e84c1108cd80185

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/pylast/
COMMENT=	Python interface to Last.fm
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pylast-0.4.18
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
