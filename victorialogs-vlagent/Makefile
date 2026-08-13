# $NetBSD$

PKGNAME=	vlagent-${VICTORIALOGS_VERS}

COMMENT=	Agent for collecting logs storing them in VictoriaLogs

GOFLAGS+=		-ldflags ' \
			-X github.com/VictoriaMetrics/VictoriaMetrics/lib/buildinfo.Version=vlagent-${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./app/vlagent

.include "../../wip/victorialogs/Makefile.common"

.include "../../mk/bsd.pkg.mk"
