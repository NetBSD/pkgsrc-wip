# $NetBSD: Makefile,v 1.6 2005/04/11 21:09:48 tvierling Exp $
#

DISTNAME=	ArgoUML-0.14
PKGNAME=	argouml-0.14
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	http://argouml.tigris.org/files/documents/4/0/argouml-0.14/
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	hdp@cs.nmsu.edu
HOMEPAGE=	http://argouml.tigris.org/
COMMENT=	UML design tool environment with cognitive support

DEPENDS+=	xerces-j>=1.4.4:../../wip/xerces-j
DEPENDS+=	jakarta-log4j>=1.2.8:../../wip/jakarta-log4j

USE_JAVA=		run
USE_X11=		yes
NO_BUILD=		yes

do-configure:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		-e 's:@JAVA_HOME@:${PKG_JAVA_HOME}:g' \
		-e 's:@ARGO_HOME@:${PREFIX}/lib/java/argouml:g' \
		${FILESDIR}/argouml > ${WRKSRC}/argouml

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/argouml
	for f in antlrall argouml gef i18n nsuml ocl-argo; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$${f}.jar ${PREFIX}/lib/java/argouml; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/argouml ${PREFIX}/bin/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
