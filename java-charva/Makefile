# $NetBSD: Makefile,v 1.2 2004/03/24 00:00:02 poppnk Exp $
#

DISTNAME=		charva-1.0.1
PKG_NAME=		java-charva-1.0.1
CATEGORIES=		wip
MASTER_SITES=		http://www.pitman.co.za/projects/charva/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.pitman.co.za/projects/charva/
COMMENT=		Java Windowing Toolkit for Text Terminals

USE_JAVA=		YES
USE_BUILDLINK3=		yes
# XXX TODO XXX
.include "../../devel/ncurses/buildlink3.mk"
NO_BUILDLINK=	#defined
USE_GNU_TOOLS+=		make

do-build:
	${RM} -f c/src/libTerminal.so
	cd ${WRKSRC}/c/src/ && \
	${CC} -Wl,-R ${PREFIX}/lib -shared -fpic -lncurses \
		${CFLAGS} -I ${JAVA_HOME}/include/ \
		-I ${PREFIX}/include/ Toolkit.c -o libTerminal.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/java/lib/charva.jar \
		${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/c/src/libTerminal.so \
		${PREFIX}/lib/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
