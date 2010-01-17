# $NetBSD: Makefile,v 1.16 2010/01/17 12:03:25 thomasklausner Exp $

DISTNAME=	fdm-1.6
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fdm/}

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://fdm.sourceforge.net/
COMMENT=	Mail fetching, filtering and delivering program

PKG_DESTDIR_SUPPORT=	user-destdir
NO_CONFIGURE=		yes

# Makefile
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile...
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile=	-e 's/ -I-//'
SUBST_SED.makefile+=	-e "s,/man/,/${PKGMANDIR}/,"
SUBST_SED.makefile+=	-e 's/-g bin -o root/-o ${BINOWN} -g ${BINGRP}/'

#
# Linux-dependant changes.
#
.include "../../mk/bsd.prefs.mk" # This defines ${OPSYS}
.if ${OPSYS} == "Linux"
SUBST_SED.makefile+=	-e 's|^SRCS=.*.c|& compat/strlcpy.c compat/strlcat.c compat/strtonum.c|'

CFLAGS+= -DNO_STRLCPY -DNO_STRLCAT -DNO_STRTONUM -D_GNU_SOURCE
CFLAGS+= -DNO_SETRESUID -DNO_SETRESGID -DNO_SETPROCTITLE -DNO_QUEUE_H -DNO_TREE_H
LDFLAGS+= -lresolv
.endif

#
# Paths
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Fixing common paths..
SUBST_FILES.paths=	fdm.h fdm.1 fdm.conf.5 MANUAL examples/f-terbeck.conf
SUBST_SED.paths=	-e "s,/etc,${PKG_SYSCONFDIR},"

##
# Options
##
PKG_OPTIONS_VAR=	PKG_OPTIONS.fdm
PKG_SUPPORTED_OPTIONS=	pcre courier-auth
PKG_SUGGESTED_OPTIONS=	pcre

# Options handling framework
.include "../../mk/bsd.options.mk"

# COURIER
.if !empty(PKG_OPTIONS:Mcourier-auth)
.include "../../security/courier-authlib/buildlink3.mk"
CFLAGS+= -DCOURIER
.endif

# PCRE
.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
CFLAGS+= -DPCRE
LDFLAGS+= -lpcre
.endif

##
# Installation directories and configuration files
##
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS=	bin share/examples ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${EGDIR}
CONF_FILES=		${EGDIR}/fdm.conf.sample ${PKG_SYSCONFDIR}/fdm.conf

# Sample configuration files
post-install:
	${INSTALL_DATA} ${FILESDIR}/fdm.conf ${DESTDIR}${EGDIR}/fdm.conf.sample
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${EGDIR}

.include "../../databases/tdb/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
