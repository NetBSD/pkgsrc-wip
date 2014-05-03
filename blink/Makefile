# $NetBSD: Makefile,v 1.6 2014/05/03 19:02:32 othyro Exp $
#

DISTNAME=	blink-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://download.ag-projects.com/BlinkQt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ag-projects.com/blink-products-283
COMMENT=	Qt version of Blink, a state of the art, easy to use SIP client
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-gnutls-[0-9]*:../../wip/py-python-gnutls
DEPENDS+=	${PYPKGPREFIX}-eventlib-[0-9]*:../../net/py-eventlib
DEPENDS+=	${PYPKGPREFIX}-python-application-[0-9]*:../../wip/py-python-application
DEPENDS+=	${PYPKGPREFIX}-qt4-[0-9]*:../../x11/py-qt4

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	resources/chat/styles/Smooth\ Operator/test/view.py
REPLACE_PYTHON+=	resources/chat/styles/Stockholm/test/view.py
PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/blink \
		${DESTDIR}${PREFIX}/bin/blink${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/share/blink/chat/styles/Smooth\ Operator \
		${DESTDIR}${PREFIX}/share/blink/chat/styles/Smooth_Operator; \
	for i in ${DESTDIR}${PREFIX}/share/blink/chat/styles/Stockholm/*.style; do \
		${MV} "$$i" `${ECHO} "$$i" | ${SED} -e 's/ //g'`; \
	done

.include "../../textproc/py-cjson/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
