# $NetBSD$

DISTNAME=	opensmalltak-vm
PKGNAME=	squeak5-vm-${GITHUB_TAG}
PKGVERSION=	5.0-${GITHUB_TAG}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenSmalltalk/}
GITHUB_PROJECT=	opensmalltalk-vm
GITHUB_TAG=	202312181441

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opensmalltalk.org/
COMMENT=	Cross-platform VM for Squeak, Pharo, Cuis, and Newspeak
LICENSE=	mit

ONLY_FOR_PLATFORM=	NetBSD-[0-9]*-x86_64
CONFLICTS+=		squeak-vm-[0-9]*

USE_LANGUAGES=	c
USE_TOOLS+=	autoreconf autoconf automake pkg-config bash pax
AUTOCONF_REQD=	2.69
USE_LIBTOOL=	yes

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-build
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		platforms/unix/plugins/SqueakSSL/openssl_overlay.h
SUBST_FILES.fix-paths+=		platforms/unix/config/configure.ac
SUBST_SED.fix-paths=		-e "s,@pkglibdir@,${PREFIX}/lib,g"

SUBST_CLASSES+=		sccs
SUBST_STAGE.sccs=	pre-build
SUBST_MESSAGE.sccs=	Set version infomation to the VM.
SUBST_FILES.sccs=	platforms/Cross/vm/sqSCCSVersion.h
SUBST_FILES.sccs+=	platforms/Cross/plugins/sqPluginsSCCSVersion.h
SUBST_SED.sccs=		-e "s,\$$Rev,\$$Rev: ${GITHUB_TAG} ,g"
SUBST_SED.sccs+=	-e "s,\$$Date,\$$Date: Mon 18 Dec 2023 15:41:18 +0100 ,g"
SUBST_SED.sccs+=	-e "s,\$$URL,\$$URL: `${ID} -un`@`${HOSTNAME_CMD}`:${WRKSRC} ,g"
SUBST_SED.sccs+=	-e "s,\$$CommitHash,\$$CommitHash: cc2dd9090 ,g"

INSTALLATION_DIRS+=	bin

NOT_PAX_MPROTECT_SAFE+=	lib/squeak/${PKGVERSION}-64bit/squeak

pre-build:
	cd ${WRKSRC}/platforms/unix/config && ${MAKE_PROGRAM}

do-build:
	cd ${WRKSRC}/building/linux64x64/squeak.cog.spur/build && yes | ${BASH} ./mvm

do-install:
	cd ${WRKSRC}/products/sqcogspur64linuxht && find bin -type f | while read file; do \
		${INSTALL_SCRIPT} $$file ${DESTDIR}${PREFIX}/$$file; \
	done
	cd ${WRKSRC}/products/sqcogspur64linuxht && find lib -type d | while read dir; do \
		${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/$$dir; \
	done
	cd ${WRKSRC}/products/sqcogspur64linuxht && find lib -type f -name "squeak" | while read file; do \
		${INSTALL_LIB} $$file ${DESTDIR}${PREFIX}/$$file; \
	done
	cd ${WRKSRC}/products/sqcogspur64linuxht && find lib -type f -name "*.so" | while read file; do \
		${INSTALL_LIB} $$file ${DESTDIR}${PREFIX}/$$file; \
	done
	cd ${WRKSRC}/products/sqcogspur64linuxht && find lib -type f -name "*.a" | while read file; do \
		${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/$$file; \
	done
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s spur64 squeak

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
