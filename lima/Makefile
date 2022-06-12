# $NetBSD$

DISTNAME=	lima-0.11.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lima-vm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lima-vm/lima
COMMENT=	Linux virtual machines for running containerd
LICENSE=	apache-2.0

# Avoid to invoke/use git
MAKE_FLAGS+=	VERSION=${GITHUB_TAG}

USE_TOOLS+=	gmake

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
