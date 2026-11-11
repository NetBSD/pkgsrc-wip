# $NetBSD$

DISTNAME=	lwjgl2-2.9.5
CATEGORIES=	games java graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jMonkeyEngine/}
GITHUB_PROJECT=	lwjgl2
GITHUB_TAG=	v2.9.5

MAINTAINER=	netbsd_pkgsrc@siriushq.org
HOMEPAGE=	https://legacy.lwjgl.org
COMMENT=	Lightweight Java Game Library v2 (LWJGL 2)
LICENSE=	modified-bsd

USE_LANGUAGES=		c java
USE_JAVA=		build
PKG_JVMS_ACCEPTED=	openjdk8
TOOL_DEPENDS+=		apache-ant-[0-9]*:../../devel/apache-ant
INSTALLATION_DIRS=	lib share/lwjgl2

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${PREFIX}/bin/ant \
	generate-all compile compile_native jars

do-install:
	${INSTALL_LIB} \
		${WRKSRC}/libs/netbsd/*.so \
		${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} \
		${WRKSRC}/libs/*.jar \
		${DESTDIR}${PREFIX}/share/lwjgl2/

# Additional target to verify the installation works correctly.  This
# can be ran by a user to test their binaries, but is not intended to
# be an automated test.  `make lwjgl-test` opens a window and hangs
# if the user has run `make install` already.
lwjgl-test:
	${PKG_JAVA_HOME}/bin/java \
		-cp "${PREFIX}/share/lwjgl2/*" \
		org.lwjgl.test.WindowCreationTest 

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
