# $NetBSD$

PKGNAME=	${DISTNAME:tl}

COMMENT=	Fast, cost-effective monitoring solution and time series database

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/VictoriaMetrics/VictoriaMetrics/lib/buildinfo.Version=victoria-metrics-${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./app/victoria-metrics

.include "../../wip/victoriametrics/Makefile.common"

.include "../../mk/bsd.pkg.mk"
