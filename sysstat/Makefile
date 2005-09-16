# $NetBSD: Makefile,v 1.1.1.1 2005/09/16 00:26:07 jeremy-c-reed Exp $
#

DISTNAME=		sysstat-6.0.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/status/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://perso.wanadoo.fr/sebastien.godard/
COMMENT=		System performance tools for Linux

USE_TOOLS+=		gmake
# uses msgfmt

USE_PKGINSTALL=		YES

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
