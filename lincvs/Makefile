# $NetBSD: Makefile,v 1.9 2005/10/06 09:16:47 ghen Exp $
#

DISTNAME=		lincvs-1.4.3-0-generic-src
PKGNAME=		${DISTNAME:S/-0-generic-src//}
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		devel x11
MASTER_SITES=	        http://lincvs.com/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		geert.hendrickx@ua.ac.be
HOMEPAGE=		http://lincvs.org/
COMMENT=		Nice GUI front-end to CVS (using Qt)

SUBST_CLASSES+=		qmake
SUBST_STAGE.qmake=	post-patch
SUBST_FILES.qmake=	lincvs.pro
SUBST_SED.qmake=	-e 's,%%QTDIR%%,${PREFIX}${QTDIR},'

do-configure:
	 ${QTDIR}/bin/qmake -o ${WRKSRC}/Makefile ${WRKSRC}/lincvs.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lincvs.bin ${PREFIX}/bin/lincvs

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	build
.include "../../mk/bsd.pkg.mk"
