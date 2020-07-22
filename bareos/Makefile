# $NetBSD: Makefile,v 1.77 2018/12/09 18:52:45 adam Exp $

CONFLICTS=		bareos-clientonly-[0-9]* bacula-clientonly-[0-9]* bacula-[0-9]*

COMMENT=		Backup Archiving REcovery Open Sourced

PLIST_SRC=		PLIST.common

RCD_SCRIPTS=		bareos bareos-dir bareos-sd bareos-fd

# For make_catalog_backup.pl.in.
USE_TOOLS+=		perl:run

.include "options.mk"
.include "Makefile.common"

# XXX keep pkglint happy - already defined in Makefile.common
BUILD_DEFS+=		VARBASE

# spool directory
MAKE_DIRS_PERMS+=	${VARBASE}/${PKG_SYSCONFSUBDIR} \
			${REAL_ROOT_USER} ${BAREOS_GROUP} 0770

post-install: # should go away once we find out how  to set the run link path in CMakefiles
	${LN} -fs ${PKG_SYSCONFSUBDIR}/backends/libbareossd-gentape.so ${DESTDIR:Q}/${BAREOS_LIBDIR:Q}/libbareossd-gentape.so

CONFIG_TEMPLATES!=	${EGREP} "^"${CONFIG_TEMPLATE_PATH:Q} PLIST.common 2>/dev/null | sed -e 's/ /\\ /g'
CONF_FILES?=

.for l in ${CONFIG_TEMPLATES}
CONF_FILES+=	${l} ${PKG_SYSCONFDIR}${l:S/^${CONFIG_TEMPLATE_PATH}//}
.endfor

MAKE_DIRS?=
MAKE_DIRS+=	${CONFIG_TEMPLATES:H:O:u:S/^${CONFIG_TEMPLATE_PATH}/${PKG_SYSCONFDIR}/}
MAKE_DIRS+=	${VARBASE}/db/${PKG_SYSCONFSUBDIR}
MAKE_DIRS+=	${VARBASE}/db/${PKG_SYSCONFSUBDIR}/bsr
MAKE_DIRS+=	${VARBASE}/db/${PKG_SYSCONFSUBDIR}/storage
MAKE_DIRS+=	${VARBASE}/db/${PKG_SYSCONFSUBDIR}/working
