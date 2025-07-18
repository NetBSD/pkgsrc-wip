# $NetBSD$

PKGNAME=	vlogscli-${VICTORIALOGS_VERS}

COMMENT=	Interactive command-line tool for querying VictoriaLogs

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/VictoriaMetrics/VictoriaMetrics/lib/buildinfo.Version=vlogscli-${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./app/vlogscli

.include "../../wip/victorialogs/Makefile.common"

.include "../../mk/bsd.pkg.mk"
