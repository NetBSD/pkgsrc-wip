# $NetBSD$

DISTNAME=	twilio-4.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twilio/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/t/twilio/
COMMENT=	Twilio API client and TwiML generator
LICENSE=	mit

#EGG_NAME=	${PKGVERSION}

DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
