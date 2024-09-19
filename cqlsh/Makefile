# $NetBSD: Makefile,v 1.78 2021/05/09 09:00:32 leot Exp $

DISTNAME=	cqlsh-6.0.0b4
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cqlsh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jeffwidman/cqlsh
COMMENT=	Command-line client for running CQL commands on Cassandra
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cassandra-driver-[0-9]*:../../databases/py-cassandra-driver
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=			# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-cassandra-driver

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
