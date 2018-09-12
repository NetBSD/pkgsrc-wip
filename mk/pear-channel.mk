# $NetBSD: pear-channel.mk,v 1.3 2012/10/08 14:00:39 asau Exp $
#
# PEAR channel package templates
#
# PEAR_CHANNEL
#    Channel name
# PEAR_CHANNEL_ALIAS
#    Channel alias name
# PEAR_CHANNEL_VERSION
#    Channel description revision

PEAR_CHANNEL_ALIAS?=	${PEAR_CHANNEL:S/./_/g}
DISTNAME?=		channel.xml
PKGNAME?=		${PHP_PKG_PREFIX}-pear-channel-${PEAR_CHANNEL_ALIAS}-${PEAR_CHANNEL_VERSION}
CATEGORIES=		devel
MASTER_SITES?=		http://${PEAR_CHANNEL}/
DIST_SUBDIR?=		pear/channels/${PEAR_CHANNEL}/${PKGVERSION_NOREV}
EXTRACT_SUFX?=		# empty

HOMEPAGE?=		http://${PEAR_CHANNEL}/
COMMENT?=		Adds ${PEAR_CHANNEL} channel to PEAR

DEPENDS+=		${PHP_PKG_PREFIX}-pear-[0-9]*:../../lang/pear

NO_BUILD=		yes

USE_LANGUAGES=		# empty

PEAR_CHANNELS_SUBDIR=	share/pear/channels

INSTALLATION_DIRS+=	${PEAR_CHANNELS_SUBDIR}

PEAR_CHANNEL_VERSION?=	1

FILES_SUBST+=	PEAR_CMD=${PREFIX}/bin/pear
FILES_SUBST+=	PEAR_CHANNELS_SUBDIR=${PEAR_CHANNELS_SUBDIR}
FILES_SUBST+=	PEAR_CHANNEL=${PEAR_CHANNEL}
INSTALL_TEMPLATES+=	../../wip/mk/pear-channel.tmpl
DEINSTALL_TEMPLATES+=	../../wip/mk/pear-channel.tmpl

.if !exists(${CURDIR}/DESCR)
DESCR_SRC=	${WRKDIR}/DESCR_SRC
do-extract:	pear-channel-descr
.endif

do-extract:	pear-channel-extract

do-install:	pear-channel-install

pear-channel-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKDIR}

pear-channel-descr:
	${ECHO} ${COMMENT} > ${DESCR_SRC}

pear-channel-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/${PEAR_CHANNELS_SUBDIR}/${PEAR_CHANNEL}

GENERATE_PLIST+=	${ECHO} ${PEAR_CHANNELS_SUBDIR}/${PEAR_CHANNEL};

.include "../../lang/php/phpversion.mk"
