# $NetBSD: Makefile,v 1.1.1.1 2010/08/08 20:20:07 jihbed Exp $
#

DISTNAME=	siginterrupt-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.pasteur.fr/pub/gensoft/projects/mobyle/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	ftp://ftp.pasteur.fr/pub/gensoft/projects/mobyle/
COMMENT=	Python interface to the siginterrupt system function

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
