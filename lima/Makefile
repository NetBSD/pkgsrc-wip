# $NetBSD$

DISTNAME=	lima-0.11.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lima-vm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lima-vm/lima
COMMENT=	Linux virtual machines for running containerd
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

# Avoid to invoke/use git
MAKE_FLAGS+=	VERSION=${GITHUB_TAG}

.include "../../lang/go/go-vars.mk"
.include "../../mk/bsd.prefs.mk"

#
# XXX: When using UEFI instead of legacy BIOS on NetBSD with NVMM QEMU aborts as
# XXX: follows:
# XXX:
# XXX: qemu-system-x86_64: NVMM: Mem Assist Failed [gpa=0xfffffff0]
# XXX: qemu-system-x86_64: NVMM: Failed to execute a VCPU.
# XXX:
# XXX: Force legacy BIOS to avoid that.
#
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=			legacy-bios
SUBST_STAGE.legacy-bios=	pre-configure
SUBST_MESSAGE.legacy-bios=	Force to use legacy BIOS on NetBSD
SUBST_FILES.legacy-bios+=	examples/default.yaml
SUBST_SED.legacy-bios+=		-e 's/legacyBIOS: null/legacyBIOS: true/'
.endif

do-build:
	cd ${WRKSRC} && \
	${RUN} ${_ULIMIT_CMD} \
	${PKGSRC_SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
			${BUILD_TARGET}

do-install:
	${RUN} cd ${WRKSRC}/_output && ${PAX} -rw bin ${DESTDIR}${PREFIX}
	${RUN} cd ${WRKSRC}/_output && ${PAX} -rw share ${DESTDIR}${PREFIX}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
