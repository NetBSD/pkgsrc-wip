# $NetBSD: Makefile,v 1.4 2004/07/18 15:50:18 ppostma Exp $
#

DISTNAME=	ArgoUML-0.14.a1.app
PKGNAME=	argouml-0.14a1
WRKSRC=		${WRKDIR}/ArgoUML.app
CATEGORIES=	devel
MASTER_SITES=	http://argouml.tigris.org/files/documents/4/0/argouml-0.14.a1/
EXTRACT_SUFX=	.tgz
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} argo_elmuth.jar xalan-java1.jar

MAINTAINER=	drue@users.sf.net
HOMEPAGE=	http://argouml.tigris.org/
COMMENT=	UML design tool with cognitive support

DEPENDS+=	xerces-j>=1.2.0:../../textproc/xerces-j
DEPENDS+=	jakarta-log4j>=1.2.8:../../wip/jakarta-log4j

SITES_argo_elmuth.jar= http://elmuth.tigris.org/files/documents/312/573/
SITES_xalan-java1.jar= http://elmuth.tigris.org/files/documents/312/574/

USE_BUILDLINK3=	yes
USE_JAVA=	run
USE_X11=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/${PKGBASE}/ext
	for f in antlrall argouml gef i18n nsuml ocl-argo; \
	do \
 	 	${INSTALL_DATA} ${WRKSRC}/Contents/Resources/Java/$${f}.jar ${PREFIX}/lib/java/${PKGBASE}; \
	done
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/argouml > ${WRKSRC}/argouml
	${INSTALL_SCRIPT} ${WRKSRC}/argouml ${PREFIX}/bin/
	${INSTALL_DATA} ${DISTDIR}/argo_elmuth.jar ${PREFIX}/lib/java/${PKGBASE}/ext
	${INSTALL_DATA} ${DISTDIR}/xalan-java1.jar ${PREFIX}/lib/java/${PKGBASE}/ext

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
