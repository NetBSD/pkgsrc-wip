# $NetBSD: Makefile,v 1.19 2008/03/10 03:28:26 hoka_adam Exp $
#

DISTNAME=		Firebird-2.0.3.12981-1
PKGNAME=		firebird-2.0.3
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=firebird/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		nel@soraneko.com
HOMEPAGE=		http://www.firebirdsql.org/
COMMENT=		SQL database, opensource version of InterBase

PKG_DESTDIR_SUPPORT+=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
#RCD_SCRIPTS=            000.firebird.sh
#CONFIGURE_SCRIPT=	./autogen.sh
CONFIGURE_ARGS+=	--libdir=${PREFIX}/firebird
USE_TOOLS+=		gm4:run gmake autoheader autoconf chgrp chown

# FBUSER	username of the database administrator
# FBGROUP	group of the database administrator
# FBHOME	home directory of the database administrator and location of
#		the databases and Firebird itself
#

FBUSER?=		firebird
FBGROUP?=		firebird
FBHOME?=		${PREFIX}/${FBUSER}
BUILD_DEFS+=		FBHOME

PKG_GROUPS=             ${FBGROUP}
PKG_USERS=              ${FBUSER}:${FBGROUP}
PKG_GECOS.${FBUSER}=    Firebird Database Administrator
PKG_HOME.${FBUSER}=     ${FBHOME}
PKG_SHELL.${FBUSER}=    ${SH}

LDFLAGS+= ${COMPILER_RPATH_FLAG}${PREFIX}/lib/firebird/UDF
LDFLAGS+= ${COMPILER_RPATH_FLAG}${PREFIX}/lib/firebird

INSTALLATION_DIRS+=	bin share/examples/firebird firebird/help \
			include lib/firebird lib/firebird/UDF share/doc/firebird

BUILDDIR=		${WRKSRC}/gen/firebird

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} autogen.sh

do-install:
	${INSTALL_PROGRAM} ${BUILDDIR}/bin/* ${DESTDIR}${PREFIX}/bin

	cp -R ${BUILDDIR}/examples/*  ${DESTDIR}${PREFIX}/share/examples/firebird

	#copyIfExists $BuiltFBDir/help/help.gbak $DestDir/firebird/help
	${INSTALL_DATA} ${BUILDDIR}/help/help.fdb ${DESTDIR}${PREFIX}/firebird/help

	${INSTALL_DATA} ${BUILDDIR}/firebird.msg ${DESTDIR}${PREFIX}/firebird/firebird.msg
	${INSTALL_DATA} ${BUILDDIR}/security2.fdb ${DESTDIR}${PREFIX}/firebird/security2.fdb.sample

	${INSTALL_DATA} ${BUILDDIR}/include/*.h ${DESTDIR}${PREFIX}/include

	${INSTALL_LIB} ${BUILDDIR}/lib/* ${DESTDIR}${PREFIX}/lib/firebird

	${INSTALL_LIB} ${BUILDDIR}/intl/libfbintl.so ${DESTDIR}${PREFIX}/lib/firebird
	${INSTALL_LIB} ${BUILDDIR}/UDF/* ${DESTDIR}${PREFIX}/lib/firebird/UDF
	${INSTALL_LIB} ${BUILDDIR}/../../extern/icu/source/lib/* ${DESTDIR}${PREFIX}/lib/firebird

	# Copy the sql-declarations into the UDF-directory
	${INSTALL_DATA} ${BUILDDIR}/../../src/extlib/ib_udf.sql ${DESTDIR}${PREFIX}/lib/firebird/UDF
	${INSTALL_DATA} ${BUILDDIR}/../../src/extlib/fbudf/fbudf.sql ${DESTDIR}${PREFIX}/lib/firebird/UDF

	cp -R ${BUILDDIR}/../../doc/*  ${DESTDIR}${PREFIX}/share/doc/firebird/

.include "../../mk/bsd.pkg.mk"
