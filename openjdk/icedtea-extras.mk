# $NetBSD: icedtea-extras.mk,v 1.2 2009/10/06 18:33:17 tnn2 Exp $

# Needed to extract icedtea
EXTRACT_USING=			gtar

ICEDTEA=			icedtea-1.11
ICEDTEA_TGZ=			${ICEDTEA}.tar.gz
SITES.${ICEDTEA_TGZ}=		http://icedtea.classpath.org/download/source/
DISTFILES+=			${ICEDTEA_TGZ}
EXTRACT_ONLY+=			${ICEDTEA_TGZ}

XALAN=				xalan-j_2_7_1
XALAN_TGZ=			${XALAN}-src.tar.gz
SITES.${XALAN_TGZ}=		${MASTER_SITE_APACHE:=xml/xalan-j/}
DISTFILES+=			${XALAN_TGZ}
EXTRACT_ONLY+=			${XALAN_TGZ}

XERCES=				xerces-2_9_1
XERCES_TGZ=			Xerces-J-src.2.9.1.tar.gz
SITES.${XERCES_TGZ}=		${MASTER_SITE_APACHE:=xerces/j/source/}
DISTFILES+=			${XERCES_TGZ}
EXTRACT_ONLY+=			${XERCES_TGZ}

XERCES_TOOLS_TGZ=		Xerces-J-tools.2.9.1.tar.gz
SITES.${XERCES_TOOLS_TGZ}=	${MASTER_SITE_APACHE:=xerces/j/source/}
DISTFILES+=			${XERCES_TOOLS_TGZ}
EXTRACT_ONLY+=			${XERCES_TOOLS_TGZ}

RHINO=				rhino1_7R2
RHINO_TGZ=			${RHINO}.zip
SITES.${RHINO_TGZ}=		${MASTER_SITE_MOZILLA:=js/}
DISTFILES+=			${RHINO_TGZ}
EXTRACT_ONLY+=			${RHINO_TGZ}

${WRKDIR}/${XALAN}/build/xalan.jar:
	cd ${WRKDIR}/xalan-j_2_7_1 && ${SETENV} ${MAKE_ENV} ant

${WRKDIR}/${XERCES}/build/xercesImpl.jar:
	cd ${WRKDIR}/xerces-2_9_1 && ${SETENV} ${MAKE_ENV} ant jar

${WRKDIR}/${ICEDTEA}/Makefile: ${WRKDIR}/${XALAN}/build/xalan.jar ${WRKDIR}/${XERCES}/build/xercesImpl.jar
	cd ${WRKDIR}/${ICEDTEA} && \
	  ${SETENV} ${CONFIGURE_ENV} ac_cv_path_MD5SUM=${PREFIX}/gmd5sum \
	  LDFLAGS="${LDFLAGS} -Wl,-R${PREFIX}/lib" \
	  ${CONFIG_SHELL} ./configure \
	  --with-jdk-home=${BUILDDIR}/j2sdk-image \
	  --with-xalan2-jar=${WRKDIR}/${XALAN}/build/xalan.jar \
	  --with-xalan2-serializer-jar=${WRKDIR}/${XALAN}/build/serializer.jar \
	  --with-xerces2-jar=${WRKDIR}/${XERCES}/build/xercesImpl.jar \
	  --with-rhino=${WRKDIR}/${RHINO}/js.jar

${WRKDIR}/${ICEDTEA}/IcedTeaPlugin.so: ${WRKDIR}/${ICEDTEA}/Makefile
	cd ${WRKDIR}/${ICEDTEA} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} IcedTeaPlugin.so

post-extract: ${WRKDIR}/${XERCES}/tools

${WRKDIR}/${XERCES}/tools:
	mv ${WRKDIR}/tools ${WRKDIR}/${XERCES}/.

post-extract: apply-icedtea-patches
.PHONY: apply-icedtea-patches
apply-icedtea-patches:
	cd ${WRKDIR} && patch -z orig-icedtea < ${WRKDIR}/${ICEDTEA}/patches/icedtea-plugin.patch
	cd ${WRKDIR} && patch -z orig-post-icedtea < ${FILESDIR}/patch-manual-ma
	cd ${WRKDIR} && patch -z orig-post-icedtea < ${FILESDIR}/patch-manual-mb
	cd ${WRKDIR} && patch -z orig-post-icedtea < ${FILESDIR}/patch-manual-mc

${WRKDIR}/stage3-done: ${WRKDIR}/${ICEDTEA}/IcedTeaPlugin.so

# XXX most of these are probably not needed for the plugin build,
# but configure needs them
BUILD_DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils
USE_TOOLS+=	gawk pkg-config
.include "../../devel/xulrunner/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
