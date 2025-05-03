# $NetBSD$

DISTNAME=	geoipupdate-7.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=maxmind/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxmind/geoipupdate
COMMENT=	GeoIP update client
LICENSE=	apache-2.0 OR mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.defaultConfigFile=${PKG_SYSCONFDIR}/GeoIP.conf \
			-X main.defaultDatabaseDirectory=${PREFIX}/share/GeoIP \
			-X main.version=${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./cmd/geoipupdate

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
