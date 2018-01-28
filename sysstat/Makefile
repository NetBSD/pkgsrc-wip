# $NetBSD: Makefile,v 1.6 2012/10/07 16:23:22 asau Exp $
#

DISTNAME=		sysstat-6.0.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/status/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://perso.orange.fr/sebastien.godard/
COMMENT=		System performance tools for Linux


USE_TOOLS+=		gmake
# uses msgfmt
ONLY_FOR_PLATFORM=	Linux-*-*

MAKE_ENV+=		SA_DIR=${VARBASE}/log/sa
MAKE_ENV+=		SA_LIB_DIR=${PREFIX}/libexec/sa
MAKE_ENV+=		DOC_DIR=${PREFIX}/share/doc/sysstat
MAKE_ENV+=		NLS_DIR=${PREFIX}/${PKGLOCALEDIR}/locale
MAKE_ENV+=		SYSCONFIG_DIR=${PREFIX}/share/examples/sysstat
MAKE_ENV+=		MAN_DIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		MAN_GROUP=${MANGRP}
MAKE_ENV+=		IOCONF=${PKG_SYSCONFDIR}/sysstat/sysstat.ioconf

CONF_FILES=		${PREFIX}/share/examples/sysstat/sysstat.ioconf \
				${PKG_SYSCONFDIR}/sysstat/sysstat.ioconf

OWN_DIRS+=		${PKG_SYSCONFDIR}/sysstat

.include "../../mk/bsd.pkg.mk"
