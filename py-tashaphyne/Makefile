# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:10:18 jihbed Exp $
#

DISTNAME=	Tashaphyne-0.1
PKGNAME=	${PYPKGPREFIX}-tashaphyne-0.1
CATEGORIES=	textproc python #arabic
MASTER_SITES=	http://pypi.python.org/packages/source/T/Tashaphyne/
EXTRACT_SUFX=	.zip#md5=29cde2cc10c9f5e9ed1eafebda3c78e2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://tashaphyne.sourceforge.net/
COMMENT=	Arabic Light Stemmer and segmentor
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
