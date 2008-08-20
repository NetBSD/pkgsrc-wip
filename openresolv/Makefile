# $NetBSD: Makefile,v 1.4 2008/08/20 13:33:57 rsmarples Exp $
#

DISTNAME=		openresolv-1.6
CATEGORIES=		net
MASTER_SITES=		http://roy.marples.name/openresolv/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://roy.marples.name/openresolv/
COMMENT=		Framework for managing /etc/resolv.conf

USE_LANGUAGES=		# none

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_SYSCONFSUBDIR=	resolvconf
EGDIR=			${PREFIX}/share/examples/resolvconf

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR} \
			SYSCONFDIR=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

OWN_DIRS=		${PKG_SYSCONFDIR}/update.d
OWN_DIRS+=		${PKG_SYSCONFDIR}/resolv.conf.d
CONF_FILES=		${EGDIR}/resolv.conf.d/head \
			${PKG_SYSCONFDIR}/resolv.conf.d/head

CONF_FILES_PERMS=
.for s in libc dnsmasq named
CONF_FILES_PERMS+=	${EGDIR}/update.d/${s} ${PKG_SYSCONFDIR}/update.d/${s} \
			${ROOT_USER} ${ROOT_GROUP} 0755
.endfor

.include "../../mk/bsd.pkg.mk"
