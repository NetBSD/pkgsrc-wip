# $NetBSD: Makefile,v 1.77 2018/12/09 18:52:45 adam Exp $

PKGNAME=		${DISTNAME:S/-/-clientonly-/}

COMMENT=		Backup Archiving REcovery Open Sourced - client

CONFLICTS=		bareos-[0-9]* bacula-[0-9]* bacula-clientonly-[0-9]*

PATCHDIR=		../../wip/bareos/patches
FILESDIR=		../../wip/bareos/files
DISTINFO_FILE=		../../wip/bareos/distinfo

PLIST_SRC=		PLIST.client

CMAKE_ARGS?=
CMAKE_ARGS+=		-Dclient-only=true

RCD_SCRIPTS=		bareos-fd

.include "../../wip/bareos/Makefile.common"

CONFIG_TEMPLATES!=	${EGREP} "^"${CONFIG_TEMPLATE_PATH:Q} PLIST.client 2>/dev/null | sed -e 's/ /\\ /g'
CONF_FILES?=

.for l in ${CONFIG_TEMPLATES}
CONF_FILES+=	${l} ${PKG_SYSCONFDIR}${l:S/^${CONFIG_TEMPLATE_PATH}//}
.endfor

BUILD_DEFS+=	VARBASE # to keep pkglint happy

MAKE_DIRS?=
MAKE_DIRS+=	${CONFIG_TEMPLATES:H:O:u:S/^${CONFIG_TEMPLATE_PATH}/${PKG_SYSCONFDIR}/}
MAKE_DIRS+=	${VARBASE}/db/${PKG_SYSCONFSUBDIR}
MAKE_DIRS+=	${VARBASE}/db/${PKG_SYSCONFSUBDIR}/working
