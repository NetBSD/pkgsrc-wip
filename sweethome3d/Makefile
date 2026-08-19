# $NetBSD$

DISTNAME=	SweetHome3D-7.5-src
PKGNAME=	sweethome3d-7.5
CATEGORIES=	cad java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sweethome3d/SweetHome3D-source/SweetHome3D-7.5-src/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sweethome3d.com/
COMMENT=	Interior design application for 2D home planning
LICENSE=	gnu-gpl-v2

USE_JAVA=	yes
USE_JAVA2=	8
USE_LANGUAGES=	# none

TOOL_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant

INSTALLATION_DIRS=	bin lib/sweethome3d share/doc/sweethome3d \
			share/icons/hicolor/32x32/apps \
			share/icons/hicolor/48x48/apps

# Patch gluegen-rt.jar to recognize NetBSD in JOGL OS detection.
# Without this, PlatformPropsImpl.getOSTypeImpl() throws RuntimeException
# on NetBSD because "netbsd" is not in its OS list.
do-build:
	mkdir -p ${WRKSRC}/patch-build/jogamp/common/os
	${CP} ${FILESDIR}/PlatformPropsImpl.java ${WRKSRC}/patch-build/jogamp/common/os/
	${PKG_JAVA_HOME}/bin/javac -cp ${WRKSRC}/lib/java3d-1.6/gluegen-rt.jar \
		-d ${WRKSRC}/patch-build \
		${WRKSRC}/patch-build/jogamp/common/os/PlatformPropsImpl.java
	cd ${WRKSRC}/patch-build && ${PKG_JAVA_HOME}/bin/jar uf \
		${WRKSRC}/lib/java3d-1.6/gluegen-rt.jar \
		jogamp/common/os/PlatformPropsImpl.class \
		'jogamp/common/os/PlatformPropsImpl$$1.class' \
		'jogamp/common/os/PlatformPropsImpl$$2.class' \
		'jogamp/common/os/PlatformPropsImpl$$3.class'
	cd ${WRKSRC} && ${PREFIX}/bin/ant jarExecutable

do-install:
	${INSTALL_DATA} ${WRKSRC}/install/SweetHome3D-${PKGVERSION_NOREV}.jar \
		${DESTDIR}${PREFIX}/lib/sweethome3d/SweetHome3D.jar
	${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT \
		${DESTDIR}${PREFIX}/share/doc/sweethome3d/
	${INSTALL_DATA} ${WRKSRC}/COPYING.TXT \
		${DESTDIR}${PREFIX}/share/doc/sweethome3d/
	${ECHO} '#!${SH}' > ${WRKSRC}/sweethome3d.sh
	${ECHO} 'exec ${PKG_JAVA_HOME}/bin/java --add-opens=java.desktop/java.awt=ALL-UNNAMED --add-opens=java.desktop/sun.awt=ALL-UNNAMED -Dcom.eteks.sweethome3d.no3D=true -Xmx1024m -jar ${PREFIX}/lib/sweethome3d/SweetHome3D.jar "$$@"' \
		>> ${WRKSRC}/sweethome3d.sh
	${INSTALL_SCRIPT} ${WRKSRC}/sweethome3d.sh \
		${DESTDIR}${PREFIX}/bin/sweethome3d
	${INSTALL_DATA} ${WRKSRC}/deploy/SweetHome3DIcon32x32.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/32x32/apps/sweethome3d.png
	${INSTALL_DATA} ${WRKSRC}/deploy/SweetHome3DIcon48x48.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/sweethome3d.png

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
