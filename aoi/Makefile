# $NetBSD: Makefile,v 1.3 2012/06/13 06:24:12 othyro Exp $
#

BASENAME=		aoi
PKGVERSION=		2.4.1
PKGNAME=		${BASENAME}-${PKGVERSION}
CATEGORIES=		graphics java
DISTNAME=		${PKGNAME:S/-//:S/.//g}
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aoi/}
EXTRACT_SUFX=		.zip

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://aoi.sourceforge.net/
COMMENT=		Open source 3D modelling and rendering studio based on Java
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/ArtOfIllusion${PKGVERSION_NOREV:S/.//}
USE_JAVA=		run
USE_JAVA2=		yes
USE_TOOLS+=		printf

PKG_JVMS_ACCEPTED=	jdk14 sun-jdk14 sun-jdk15

DATADIR=		lib/java/${PKGNAME}/
DOCSDIR=		share/doc/${PKGNAME}/
INSTALLATION_DIRS=	bin ${DOCSDIR} ${DATADIR} ${DATADIR}/Icons \
			${DATADIR}/Plugins ${DATADIR}/Plugins/Help \
			${DATADIR}/Scripts ${DATADIR}/Scripts/Objects \
			${DATADIR}/Scripts/Startup ${DATADIR}/Scripts/Tools

do-build:
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/${DATADIR}/ArtOfIllusion.jar \"\$$@\"\\n" > ${WRKSRC}/${BASENAME:Q}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aoi.sh ${PREFIX}/bin/aoi
	( cd ${WRKSRC} ; \
		${INSTALL_DATA} ArtOfIllusion.jar ${PREFIX}/${DATADIR} ; \
		${INSTALL_DATA} Icons/* ${PREFIX}/${DATADIR}/Icons ; \
		${INSTALL_DATA} Plugins/*.jar ${PREFIX}/${DATADIR}/Plugins ; \
		${INSTALL_DATA} Plugins/Help/* ${PREFIX}/${DATADIR}/Plugins/Help ; \
		${INSTALL_DATA} Scripts/Objects/* ${PREFIX}/${DATADIR}/Scripts/Objects ; \
		${INSTALL_DATA} Scripts/Startup/* ${PREFIX}/${DATADIR}/Scripts/Startup ; \
		${INSTALL_DATA} Scripts/Tools/* ${PREFIX}/${DATADIR}/Scripts/Tools ; \
		${INSTALL_DATA} HISTORY LICENSE README ${PREFIX}/${DOCSDIR} )

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
