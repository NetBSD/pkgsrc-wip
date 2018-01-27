# $NetBSD: Makefile,v 1.13 2012/09/24 16:56:38 asau Exp $
#

DISTNAME=	ArgoUML-0.14
PKGNAME=	argouml-0.14
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://argouml.tigris.org/files/documents/4/0/argouml-0.14/

MAINTAINER=	hdp@cs.nmsu.edu
HOMEPAGE=	http://argouml.tigris.org/
COMMENT=	UML design tool environment with cognitive support

#DEPENDS+=	xerces-j>=1.4.4:../../textproc/xerces-j
DEPENDS+=	xerces-j>=1.2.0:../../textproc/xerces-j
DEPENDS+=	jakarta-log4j-1.3a>=8:../../wip/jakarta-log4j

USE_JAVA=	run
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

do-configure:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		-e 's:@JAVA_HOME@:${PKG_JAVA_HOME}:g' \
		-e 's:@ARGO_HOME@:${PREFIX}/lib/java/argouml:g' \
		${FILESDIR}/argouml > ${WRKSRC}/argouml

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java/argouml
	for f in antlrall argouml gef i18n nsuml ocl-argo; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$${f}.jar ${DESTDIR}${PREFIX}/lib/java/argouml; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/argouml ${DESTDIR}${PREFIX}/bin/

.include "../../mk/java-vm.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
