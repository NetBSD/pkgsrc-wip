# $NetBSD: Makefile,v 1.1 2014/07/25 18:15:28 jihbed Exp $

DISTNAME=	okasha_0.2.4.orig
PKGNAME=	${PYPKGPREFIX}-okasha-0.2.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/non-free/o/okasha/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://okasha.ojuba.org/
COMMENT=	Trivial WSGI web framework for Python
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/okasha-0.2.4

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
