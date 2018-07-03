# $NetBSD: Makefile,v 1.18 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=		leo-4-4-2-1-final
PKGNAME=		leo-4.4.2.1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=leo/}
EXTRACT_SUFX=		.zip

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://leo.sourceforge.net/
COMMENT=		Programmer's editor and a flexible browser

DEPENDS+=		${PYPKGPREFIX}-docutils>=0.3.9:../../textproc/py-docutils
DEPENDS+=		${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk


NO_BUILD=	yes
REPLACE_PYTHON=	src/leo.py scripts/LinixInstall.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-docutils

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

post-extract:
	${RM} -rf ${WRKSRC}/scripts/CVS
	${RM} -rf ${WRKSRC}/extensions/Pmw/Pmw_1_2/tests/CVS
	${RM} -rf ${WRKSRC}/extensions/Pmw/Pmw_1_2/lib/CVS
	${RM} -rf ${WRKSRC}/extensions/Pmw/Pmw_1_2/doc/CVS
	${RM} -rf ${WRKSRC}/extensions/Pmw/Pmw_1_2/demos/CVS
	${RM} -rf ${WRKSRC}/extensions/Pmw/Pmw_1_2/contrib/CVS
	${RM} -rf ${WRKSRC}/extensions/Pmw/Pmw_1_2/bin/CVS
	${RM} -rf ${WRKSRC}/doc/html/tigris/CVS
	${RM} -rf ${WRKSRC}/doc/html/CVS
	${RM} -rf ${WRKSRC}/Icons/CVS

pre-install:
	${RM} -rf ${WRKSRC}/install.orig

do-install:
	cd ${WRKSRC} && ${CHMOD} 755 ./install && \
		${SETENV} PREFIX=${PREFIX} PYTHONBIN=${PYTHONBIN:Q} \
		./install

post-install:
	${PYTHONBIN} ${PYCOMPILEALL} ${PREFIX}/lib/leo/src ${PREFIX}/lib/leo/plugins ${PREFIX}/lib/leo/extensions ${PREFIX}/lib/leo/scripts ${PREFIX}/lib/leo/test

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
