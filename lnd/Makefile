# $NetBSD$

DISTNAME=	lnd-source-v0.7.1-beta
PKGNAME=	${DISTNAME:S/source-v//:S/-beta/beta/}
PKGREVISION=	5
DISTFILES=	${DEFAULT_DISTFILES} vendor.tar.gz
SITES.vendor.tar.gz = \
    ${MASTER_SITE_GITHUB:=lightningnetwork/${GITHUB_PROJECT}/releases/download/${DISTNAME:S/lnd-source-//}}/

CATEGORIES=	finance

MASTER_SITES=	${MASTER_SITE_GITHUB:=lightningnetwork/}
GITHUB_RELEASE=	v0.7.1-beta
GITHUB_PROJECT=	lnd

MAINTAINER=	kaypkgsrc@mailbox.org
HOMEPAGE=	https://lightning.network
COMMENT=	Lightning Network Daemon

LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/lightningnetwork/lnd

LND_GO_FLAGS+=	-v -mod=vendor -ldflags
LND_GO_FLAGS+=	-X ${GO_SRCPATH}/buildCommit=${DISTNAME:S/lnd-source-//}

post-extract:
	${MKDIR} ${WRKDIR}/${DISTNAME}

# XXX: should GO111MODULE go here? It's required according to the official build instructions
# (see: https://github.com/lightningnetwork/lnd/releases)
#
# TODO: This fix (https://github.com/btcsuite/btcwallet/issues/638) has not been included
# in v0.7.1-beta yet, so it will need patching to build.
#
do-build:
	${RUN} ${PKGSRC_SETENV} ${MAKE_ENV} \
		GO111MODULE=on ${GO} install ${LND_GO_FLAGS} ${GO_BUILD_PATTERN} ./cmd/lnd
	${RUN} ${PKGSRC_SETENV} ${MAKE_ENV} \
		GO111MODULE=on ${GO} install ${LND_GO_FLAGS} ${GO_BUILD_PATTERN} ./cmd/lncli

# XXX: untested, build is not working
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/cmd/lnd ${DESTDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/cmd/lncli ${DESTDIR}/${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

# TODO: bmake patch is broken, because stuff is not moved to GO_SRCPATH (it should, right?)
# on extract.
