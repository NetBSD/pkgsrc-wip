# $NetBSD$

DISTNAME=	VictoriaLogs-1.26.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=VictoriaMetrics/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/VictoriaMetrics/VictoriaLogs/
COMMENT=	Fast and easy to use database for logs
LICENSE=	apache-2.0

MAKE_ENV+=	CGO_ENABLED=0

WRKSRC=		${WRKDIR}/${DISTNAME}

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/VictoriaMetrics/VictoriaMetrics/lib/buildinfo.Version=""'
GO_BUILD_PATTERN+=	./app/victoria-logs

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
