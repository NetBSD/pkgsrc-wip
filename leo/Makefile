# $NetBSD: Makefile,v 1.9 2006/08/26 19:54:35 dhowland Exp $
#

DISTNAME=		leo-4-4-final
PKGNAME=		leo-4.4
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=leo/}
EXTRACT_SUFX=		.zip

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://leo.sourceforge.net/
COMMENT=		Programmer's editor and a flexible browser

DEPENDS+=		${PYPKGPREFIX}-docutils>=0.3.9:../../textproc/py-docutils

NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	src/leo.py scripts/LinixInstall.py

EXTRACT_OPTS_ZIP=	-aqo

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
	cd ${WRKSRC} && ${CHMOD} 755 ./install && ${SETENV} PREFIX=${PREFIX:Q} ./install && ${CHMOD} 755 ${PREFIX}/lib/leo/src/leo.py

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
