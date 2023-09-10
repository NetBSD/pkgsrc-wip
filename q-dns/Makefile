# $NetBSD$

DISTNAME=	q-dns-0.12.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=natesales/}
GITHUB_PROJECT=	q
GITHUB_TAG=	v${PKGVERSION_NOREV}
GIT_COMMIT=	20119b4c88d1af96acd0a4c4dceb3082c80d28c3

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://github.com/natesales/q
COMMENT=	Tiny and feature-rich command line DNS client
LICENSE=	gnu-gpl-v3

.include "go-modules.mk"

GO_BUILD_DATE_cmd=	${DATE} -u '+%Y-%m-%dT%H:%M:%SZ'
GO_BUILD_PATTERN+=	-ldflags ' \
			-X "main.version=${PKGVERSION_NOREV}" \
			-X "main.commit=${GIT_COMMIT}" \
			-X "main.date=${GO_BUILD_DATE_cmd:sh}"'

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
