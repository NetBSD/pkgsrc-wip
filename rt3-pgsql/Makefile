# $NetBSD: Makefile,v 1.4 2004/07/02 21:08:40 roelants Exp $
#

PKGNAME=		${DISTNAME:S/-/-pgsql-/}

# Postgresql dependencies
DEPENDS+=	p5-DBD-postgresql>=1.22:../../databases/p5-DBD-postgresql

RT_DB_TYPE=		Pg
DB_DBA?=		postgres

.include "Makefile.common"
