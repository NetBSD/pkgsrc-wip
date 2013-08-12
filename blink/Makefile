# $NetBSD: Makefile,v 1.3 2013/08/12 04:08:40 othyro Exp $
#

DISTNAME=	blink-0.5.0
CATEGORIES=	net
MASTER_SITES=	http://download.ag-projects.com/BlinkQt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ag-projects.com/blink-products-283
COMMENT=	Qt version of Blink, a state of the art, easy to use SIP client
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-python-gnutls-[0-9]*:../../wip/py-python-gnutls
DEPENDS+=	eventlib-[0-9]*:../../wip/eventlib
DEPENDS+=	${PYPKGPREFIX}-python-application-[0-9]*:../../wip/py-python-application
DEPENDS+=	${PYPKGPREFIX}-qt4-[0-9]*:../../x11/py-qt4
.include "../../wip/py-cjson/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
