# $NetBSD: Makefile,v 1.10 2012/10/01 20:24:51 asau Exp $
#

DISTNAME=		charva-1.1.0
PKGNAME=		java-charva-1.1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.pitman.co.za/projects/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.pitman.co.za/projects/charva/
COMMENT=		Java Windowing Toolkit for Text Terminals

USE_JAVA=		yes
USE_TOOLS+=		gmake

do-build:
	${RM} -f c/src/libTerminal.so
	cd ${WRKSRC}/c/src/ && \
	${CC} -Wl,-R ${PREFIX}/lib -shared -fpic -lncurses \
		${CFLAGS} -I ${JAVA_HOME}/include/ \
		-I ${PREFIX}/include/ Toolkit.c -o libTerminal.so

INSTALLATION_DIRS=	lib share/classpath

do-install:
	${INSTALL_DATA} ${WRKSRC}/java/dist/lib/charva.jar \
		${DESTDIR}${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/c/src/libTerminal.so \
		${DESTDIR}${PREFIX}/lib/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
