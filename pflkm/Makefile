# $NetBSD: Makefile,v 1.11 2004/06/09 22:54:06 ppostma Exp $

DISTNAME=		pf-lkm-20040607
CATEGORIES=		security ipv6
MASTER_SITES=		http://nedbsd.nl/~ppostma/pf/

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://nedbsd.nl/~ppostma/pf-lkm.html
COMMENT=		OpenBSD PF loadable kernel module for NetBSD

ONLY_FOR_PLATFORM=	NetBSD-2.0*-*

USE_PKGINSTALL=		yes
USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes

PKG_USERS=		_pflogd:nogroup::pflogd\\ pseudo-user:${VARBASE}/empty:/sbin/nologin

RCD_SCRIPTS=		pf pflogd
CONF_FILES=		${PREFIX}/share/examples/${PKGBASE}/pf.conf ${PKG_SYSCONFDIR}/pf.conf
CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/pf.os ${PKG_SYSCONFDIR}/pf.os

post-patch:
.for f in sbin/pfctl/pfctl_parser.h usr.sbin/authpf/pathnames.h
	@${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}.orig
	@${SED} -e 's!@PREFIX@!${PREFIX}!g' < ${WRKSRC}/${f}.orig > \
	    ${WRKSRC}/${f}
.endfor

pre-install:
.if !exists(${PREFIX}/lkm)
	@${INSTALL_DATA_DIR} ${PREFIX}/lkm
.endif
.if !exists(${PREFIX}/include/net)
	@${INSTALL_DATA_DIR} ${PREFIX}/include/net
.endif
.if !exists(${VARBASE}/empty)
	@${INSTALL_DATA_DIR} ${VARBASE}/empty
.endif
.if !exists(${PREFIX}/share/examples/${PKGBASE})
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/pf.conf ${PREFIX}/share/examples/${PKGBASE}/pf.conf
	${INSTALL_DATA} ${WRKSRC}/etc/pf.os ${PREFIX}/share/examples/${PKGBASE}/pf.os

.include "../../mk/bsd.pkg.mk"
