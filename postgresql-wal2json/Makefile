# $NetBSD$

PKGVERSION=	2.3
GITHUB_PROJECT=	wal2json
GITHUB_TAG=	${GITHUB_PROJECT}_${PKGVERSION:C/\./_/}
DISTNAME=	${GITHUB_PROJECT}_${PKGVERSION:C/\./_/}
PKGNAME=	postgresql${PGSQL_VERSION}-${GITHUB_PROJECT}-${PKGVERSION}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=eulerto/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	otis@NetBSD.org
HOMEPAGE=	https://github.com/eulerto/wal2json
COMMENT=	Plugin to decode PostgreSQL WAL to JSON
LICENSE=	modified-bsd

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
