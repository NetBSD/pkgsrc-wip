# $NetBSD: Makefile,v 1.3 2004/05/09 21:27:16 blef Exp $

DISTNAME=	rox-2.0.1
WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Filer/src
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	froz@icix.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	RISC OS-like filer for X

DEPENDS+=	shared-mime-info>=0.12:../../databases/shared-mime-info

USE_BUILDLINK3=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-rox
CONFIGURE_ARGS+=--with-platform="src"

TYPE_FILE= ${WRKSRC}/type.c
post-patch:
	${MV} ${TYPE_FILE} ${TYPE_FILE}.pre
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" ${TYPE_FILE}.pre > ${TYPE_FILE}
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" ${FILESDIR}/rox > \
		${WRKDIR}/${DISTNAME}/rox

post-build:
	${MV} ${WRKSRC} ${WRKDIR}/${DISTNAME}/src

pre-install:
	${RM} -f ${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun.orig
	${RM} -rf ${WRKSRC}

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/rox
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/src/ROX-Filer  \
    		${PREFIX}/libexec/rox
	${INSTALL_DATA_DIR} ${PREFIX}/share/rox/ROX-Filer
	${INSTALL_DATA_DIR} ${PREFIX}/share/rox/Choices/MIME-icons
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Choices/MIME-icons/* ${PREFIX}/share/rox/Choices/MIME-icons
	${INSTALL_DATA_DIR} ${PREFIX}/share/rox/Choices/MIME-types
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/Choices/MIME-types/* ${PREFIX}/share/rox/Choices/MIME-types
	cd ${WRKDIR}/${DISTNAME}/ROX-Filer && ${PAX} -rw . ${PREFIX}/share/rox/ROX-Filer
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" <				\
		${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun > 		\
		${PREFIX}/share/rox/ROX-Filer/AppRun
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/rox ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/rox.1 ${PREFIX}/man/man1

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
