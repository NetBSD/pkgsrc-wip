# $NetBSD: Makefile,v 1.29 2012/09/28 23:21:48 asau Exp $
#

DISTNAME=		Firebird-2.1.1.17910-0
PKGNAME=		firebird-2.1.1
PKGREVISION=		2
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=firebird/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		nel@soraneko.com, adam.hoka@gmail.com
HOMEPAGE=		http://www.firebirdsql.org/
COMMENT=		SQL database, opensource version of InterBase

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
#RCD_SCRIPTS=		000.firebird.sh

CONFIGURE_ARGS+=	--with-editline \
			--with-system-editline \
			--with-system-icu \
			--sysconfdir=${PKG_SYSCONFDIR} \
			--libexecdir=${PREFIX}/libexec \
			--datadir=${PREFIX}/${FBHOME}

USE_TOOLS+=		gmake

# FBUSER	username of the database administrator
# FBGROUP	group of the database administrator
# FBHOME	home directory of the database administrator and location of
#		the databases and Firebird itself
#

FBUSER?=		firebird
FBGROUP?=		firebird
FBHOME?=		firebird

BUILD_DEFS+=		FBHOME

PKG_GROUPS=		${FBGROUP}
PKG_USERS=		${FBUSER}:${FBGROUP}
PKG_GECOS.${FBUSER}=	Firebird Database Administrator
PKG_HOME.${FBUSER}=	${PREFIX}/${FBHOME}
PKG_SHELL.${FBUSER}=	${SH}

EGDIR=			${PREFIX}/share/examples/firebird
CONF_FILES+=		${EGDIR}/firebird.conf ${PKG_SYSCONFDIR}/firebird.conf

post-extract:
	${MKDIR} ${WRKSRC}/gen

# Till they fix the install phase.
#
.include "Makefile.install"
.include "Makefile.script"

.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
