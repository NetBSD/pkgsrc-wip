# $NetBSD: Makefile,v 1.8 2005/10/23 12:20:46 rillig Exp $
#

DISTNAME=	ArgoUML-0.14
PKGNAME=	argouml-0.14
CATEGORIES=	devel
MASTER_SITES=	http://argouml.tigris.org/files/documents/4/0/argouml-0.14/

MAINTAINER=	hdp@cs.nmsu.edu
HOMEPAGE=	http://argouml.tigris.org/
COMMENT=	UML design tool environment with cognitive support

DEPENDS+=	xerces-j>=1.4.4:../../textproc/xerces-j
DEPENDS+=	jakarta-log4j>=1.2.8:../../wip/jakarta-log4j

USE_JAVA=		run
NO_BUILD=		yes
WRKSRC=		${WRKDIR}

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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
