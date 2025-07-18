# $NetBSD$

PKGNAME=	${DISTNAME:tl}

COMMENT=	Fast and easy to use database for logs

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/VictoriaMetrics/VictoriaMetrics/lib/buildinfo.Version=victoria-logs-${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./app/victoria-logs

.include "../../wip/victorialogs/Makefile.common"

.include "../../mk/bsd.pkg.mk"
