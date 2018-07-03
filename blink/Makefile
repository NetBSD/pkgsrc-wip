# $NetBSD: Makefile,v 1.8 2015/03/18 01:52:34 othyro Exp $

DISTNAME=	blink-1.1.0
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
DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-cjson-[0-9]*:../../textproc/py-cjson

USE_LANGUAGES=	c

REPLACE_PYTHON+=		resources/chat/styles/Smooth\ Operator/test/view.py
REPLACE_PYTHON+=		resources/chat/styles/Stockholm/test/view.py
PY_PATCHPLIST=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-python-application, py-python-gnutls

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/blink \
		${DESTDIR}${PREFIX}/bin/blink${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/share/blink/chat/styles/Smooth\ Operator \
		${DESTDIR}${PREFIX}/share/blink/chat/styles/Smooth_Operator
	for i in ${DESTDIR}${PREFIX}/share/blink/chat/styles/Stockholm/*.style; do \
		${MV} "$$i" `${ECHO} "$$i" | ${SED} -e 's/ //g'`; \
	done

.include "../../net/libvncserver/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
