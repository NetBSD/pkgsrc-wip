# $NetBSD$

PKGNAME=	vlogscli-${VICTORIALOGS_VERS}

COMMENT=	Interactive command-line tool for querying VictoriaLogs

GOFLAGS+=		-ldflags ' \
			-X github.com/VictoriaMetrics/VictoriaMetrics/lib/buildinfo.Version=${PKGBASE}-${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./app/${PKGBASE}

.include "../../wip/victorialogs/Makefile.common"

.include "../../mk/bsd.pkg.mk"
