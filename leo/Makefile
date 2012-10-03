# $NetBSD: Makefile,v 1.14 2012/10/03 09:10:36 asau Exp $
#

DISTNAME=		leo-4-4-2-1-final
PKGNAME=		leo-4.4.2.1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=leo/}
EXTRACT_SUFX=		.zip

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://leo.sourceforge.net/
COMMENT=		Programmer's editor and a flexible browser

DEPENDS+=		${PYPKGPREFIX}-docutils>=0.3.9:../../textproc/py-docutils

PKG_DESTDIR_SUPPORT=	none

NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	src/leo.py scripts/LinixInstall.py

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

post-extract:
	${RM} -rf ${WRKSRC:Q}/scripts/CVS
	${RM} -rf ${WRKSRC:Q}/extensions/Pmw/Pmw_1_2/tests/CVS
	${RM} -rf ${WRKSRC:Q}/extensions/Pmw/Pmw_1_2/lib/CVS
	${RM} -rf ${WRKSRC:Q}/extensions/Pmw/Pmw_1_2/doc/CVS
	${RM} -rf ${WRKSRC:Q}/extensions/Pmw/Pmw_1_2/demos/CVS
	${RM} -rf ${WRKSRC:Q}/extensions/Pmw/Pmw_1_2/contrib/CVS
	${RM} -rf ${WRKSRC:Q}/extensions/Pmw/Pmw_1_2/bin/CVS
	${RM} -rf ${WRKSRC:Q}/doc/html/tigris/CVS
	${RM} -rf ${WRKSRC:Q}/doc/html/CVS
	${RM} -rf ${WRKSRC:Q}/Icons/CVS

pre-install:
	${RM} -rf ${WRKSRC:Q}/install.orig

do-install:
	cd ${WRKSRC} && ${CHMOD} 755 ./install && \
		${SETENV} PREFIX=${PREFIX:Q} PYTHONBIN=${PYTHONBIN:Q} \
		./install

post-install:
	${PYTHONBIN} ${PYCOMPILEALL} ${PREFIX}/lib/leo/src ${PREFIX}/lib/leo/plugins ${PREFIX}/lib/leo/extensions ${PREFIX}/lib/leo/scripts ${PREFIX}/lib/leo/test

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
