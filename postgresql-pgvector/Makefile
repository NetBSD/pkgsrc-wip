# $NetBSD: Makefile,v 0.6.2 2024/03/26 22:17:34 arai Exp $

DISTNAME=	pgvector-0.6.2
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=pgvector/}
GITHUB_PROJECT=	pgvector
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc@brianewell.com
HOMEPAGE=	https://github.com/pgvector/pgvector
COMMENT=	Open-source vector similarity search for Postgres
LICENSE=	postgresql-license

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_TOOLS+=	gmake

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
