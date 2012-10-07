# $NetBSD: Makefile,v 1.2 2012/10/07 14:53:44 asau Exp $
#

DISTNAME=	bdb-0.6.5
CATEGORIES=	databases
MASTER_SITES=	http://rubyforge.org/frs/download.php/56887/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/bdb/
COMMENT=	Ruby interface to Berkley DB
LICENSE=	ruby-license

DIST_SUBDIR=	ruby

USE_LANGUAGES=	c c++
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS+=	--with-db-unique=no
CONFIGURE_ARGS+=	--with-db-version=${BDB_LIBS:S/-ldb//:Q}
CONFIGURE_ARGS+=	--with-db-include=${BDBBASE}/include/${BDB_TYPE}
CONFIGURE_ARGS+=	--with-db-lib=${BDBBASE}/lib

BDB_ACCEPTED=	db4 db3 db2

.include "../../lang/ruby/modules.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
