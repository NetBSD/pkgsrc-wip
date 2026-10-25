# $NetBSD$

# The upstream tarball is the whole monorepo (future-agi-<ver>) but this
# package only builds the gateway (agentcc-gateway). Keep the version in one
# place (VERSION below); DISTNAME and PKGNAME are derived from it so updating
# is a one-line change and `make fetch` keeps working.
VERSION=	1.54.0
DISTNAME=	future-agi-${VERSION}
PKGNAME=	agentcc-gateway-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=future-agi/}
GITHUB_PROJECT=	future-agi
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/future-agi/future-agi/
COMMENT=	OpenAI-compatible LLM gateway with routing, guardrails, and caching
LICENSE=	apache-2.0

# The gateway is a Go module (github.com/futureagi/agentcc-gateway) that lives
# inside the future-agi monorepo tarball under agentcc-gateway/.
WRKSRC=		${WRKDIR}/${DISTNAME}/agentcc-gateway

MAKE_ENV+=		CGO_ENABLED=0
GO_BUILD_PATTERN=	./cmd/agentcc

USE_LANGUAGES=	# none

EGDIR=			share/examples/agentcc

CONF_FILES+=		${EGDIR}/agentcc.conf ${PKG_SYSCONFDIR}/agentcc.conf
RCD_SCRIPTS=		agentcc

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${FILESDIR}/agentcc.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/agentcc.conf
	${INSTALL_DATA} ${FILESDIR}/agentcc-failover.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/agentcc-failover.conf
	${INSTALL_DATA} ${WRKSRC}/config.example.yaml \
		${DESTDIR}${PREFIX}/${EGDIR}/config.example.yaml
	${INSTALL_DATA} ${WRKSRC}/config.license_auth.example.yaml \
		${DESTDIR}${PREFIX}/${EGDIR}/config.license_auth.example.yaml

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

# PAX tool variable is not being set by go-module.mk's USE_TOOLS+= pax in
# this pkgsrc version; set it explicitly for the do-install step.
PAX=		/bin/pax

# patches/ contains fixes not yet upstream:
#   - patch-internal_routing_failover.go: round-robin/weighted routing was
#     biased when failover is enabled (router selected twice per request).
#   - patch-internal_server_handlers.go: wire ExecuteWithFirst into the
#     non-stream and streaming failover paths.
# Regenerate with: diff -u ... > patches/patch-...  then `make distinfo`.
