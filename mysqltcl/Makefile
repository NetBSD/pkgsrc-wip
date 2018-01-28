# $NetBSD: Makefile,v 1.5 2012/11/14 00:16:12 othyro Exp $

DISTNAME=		mysqltcl-3.02
CATEGORIES=		databases
MASTER_SITES=		http://www.xdobry.de/mysqltcl/

MAINTAINER=		alchow@users.sourceforge.net

HOMEPAGE=		http://www.xdobry.de/mysqltcl/
COMMENT=		Tcl Mysql Interface


GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
DIST_SUBDIR=		${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tclinclude=${BUILDLINK_PREFIX.tcl}/include/tcl/generic
CONFIGURE_ARGS+=	--with-mysql-include=${LOCALBASE}/include/mysql
CONFIGURE_ARGS+=	--with-mysql-lib=${LOCALBASE}/lib/mysql
CONFIGURE_ARGS+=	--libdir=${LOCALBASE}/lib/tcl

LIBS +=			${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
