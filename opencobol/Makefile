# $NetBSD: Makefile,v 1.1.1.1 2009/10/14 10:21:25 rodo6510 Exp $
#

DISTNAME=	open-cobol-1.0
CATEGORIES=	lang
MASTER_SITES=	http://mesh.dl.sourceforge.net/project/open-cobol/open-cobol/1.0/

MAINTAINER=	rodo@zlug.org
HOMEPAGE=	http://mesh.dl.sourceforge.net/project/open-cobol/open-cobol/1.0/
COMMENT=	Open-source COBOL compiler
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=             msgfmt
USE_LANGUAGES=          c c++
INFO_FILES=             yes

TEST_TARGET=            check

CONFIGURE_ARGS+=        --without-readline
CONFIGURE_ARGS+=        --with-lfs
CONFIGURE_ARGS+=	--with-db=${PREFIX}

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
#.if ${BDB_TYPE} != "db1"
#CONFIGURE_ARGS+=        --with-db
#.endif

.include "../../mk/bsd.pkg.mk"
