# $NetBSD: Makefile,v 1.2 2014/04/07 08:46:15 thomasklausner Exp $

# The distname is weird: it is only the version without the package name...
DISTNAME=	${VERSION}
PKGNAME=	${PYPKGPREFIX}-apsw-${VERSION}
VERSION=	3.8.4.2-r1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/rogerbinns/apsw/archive/

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://rogerbinns.github.io/apsw/
COMMENT=	Python wrapper for SQLite
LICENSE=	2-clause-bsd # from http://opensource.org/licenses/alphabetical
# as mentioned in the LICENSE file.

DIST_SUBDIR=	py-apsw
WRKSRC=		${WRKDIR}/apsw-${VERSION}
USE_LANGUAGES+=	c

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.8.3
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
