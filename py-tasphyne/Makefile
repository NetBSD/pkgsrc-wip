# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	Tashaphyne-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=T/Tashaphyne/}
EXTRACT_SUFX=	.zip#md5=29cde2cc10c9f5e9ed1eafebda3c78e2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://tashaphyne.sourceforge.net/
COMMENT=	Arabic Light Stemmer and Segmentor
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
