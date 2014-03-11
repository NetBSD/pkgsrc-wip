# $NetBSD: Makefile,v 1.5 2014/03/11 04:03:36 othyro Exp $
#

DISTNAME=	blink-0.7.0
CATEGORIES=	net
MASTER_SITES=	http://download.ag-projects.com/BlinkQt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ag-projects.com/blink-products-283
COMMENT=	Qt version of Blink, a state of the art, easy to use SIP client
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-gnutls-[0-9]*:../../wip/py-python-gnutls
DEPENDS+=	eventlib-[0-9]*:../../wip/eventlib
DEPENDS+=	${PYPKGPREFIX}-python-application-[0-9]*:../../wip/py-python-application
DEPENDS+=	${PYPKGPREFIX}-qt4-[0-9]*:../../x11/py-qt4

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	resources/chat/styles/Smooth\ Operator/test/view.py
REPLACE_PYTHON+=	resources/chat/styles/Stockholm/test/view.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/blink/chat/styles/Smooth\ Operator \
		${DESTDIR}${PREFIX}/share/blink/chat/styles/Smooth_Operator; \
	for i in ${DESTDIR}${PREFIX}/share/blink/chat/styles/Stockholm/*.style; do \
		${MV} "$$i" `${ECHO} "$$i" | ${SED} -e 's/ //g'`; \
	done

.include "../../wip/py-cjson/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
