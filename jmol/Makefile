# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:42 othyro Exp $
#

DISTNAME=	Jmol-12.0.12-binary
PKGNAME=	${DISTNAME:S/J/j/S/-binary//}
CATEGORIES=	biology java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jmol/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://jmol.sourceforge.net/
COMMENT=	Jmol: an open-source Java viewer for chemical structures in 3D
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/jmol-12.0.12

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-*

USE_JAVA2=		yes
PKG_JVMS_ACCEPTED=	sun-jdk7

JMOL_HOME=	${PREFIX}/share/jmol
JMOL_FILES=	Jmol.jar JmolApplet.jar           \
			JmolApplet0.jar 		    \
			JmolApplet0_*.jar	            \
			JmolAppletSigned0_*.jar	    \
			JmolData.jar Jmol.js

INSTALLATION_DIRS=	bin ${JMOL_HOME}

do-install:
	${INSTALL_SCRIPT}  ${WRKSRC}/jmol.sh ${DESTDIR}${PREFIX}/bin/jmol
.for  j in ${JMOL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${j}  ${DESTDIR}${JMOL_HOME}
.endfor

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
