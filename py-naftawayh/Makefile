# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:12:12 jihbed Exp $
#

DISTNAME=	Naftawayh-0.1
PKGNAME=	${PYPKGPREFIX}-naftawayh-0.1
CATEGORIES=	textproc python #arabic
MASTER_SITES=	http://pypi.python.org/packages/source/N/Naftawayh/
EXTRACT_SUFX=	.zip#md5=30663df3626a2464e234131f674e7627

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://naftawayh.sourceforge.net/
COMMENT=	Naftawayh: Arabic word tagger
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
