# $NetBSD: Makefile,v 1.1.1.1 2003/06/30 14:45:34 drue Exp $
#

DISTNAME=	ArgoUML-0.14.a1.app
PKGNAME=	argouml-0.14a1
WRKSRC=		${WRKDIR}/ArgoUML.app
CATEGORIES=	wip
MASTER_SITES=	http://argouml.tigris.org/files/documents/4/0/argouml-0.14.a1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	drue@users.sf.net
HOMEPAGE=	http://argouml.tigris.org/
COMMENT=	UML design tool with cognitive support

DEPENDS+=       xerces-j>=1.2.0:../../textproc/xerces-j
DEPENDS+=       jakarta-log4j>=1.2.8:../../wip/jakarta-log4j

USE_BUILDLINK2=		yes
USE_JAVA=	run
USE_X11=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	for f in antlrall argouml gef i18n nsuml ocl-argo; \
	do \
 	 	${INSTALL_DATA} ${WRKSRC}/Contents/Resources/Java/$${f}.jar ${PREFIX}/lib/java; \
	done
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		${FILESDIR}/argouml > ${WRKSRC}/argouml
	${INSTALL_SCRIPT} ${WRKSRC}/argouml ${PREFIX}/bin/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
