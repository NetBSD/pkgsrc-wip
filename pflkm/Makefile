# $NetBSD: Makefile,v 1.10 2004/06/09 17:49:36 ppostma Exp $

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

PKG_USERS=		_pflogd:nogroup::pflogd\\ pseudo-user:/var/empty:/sbin/nologin

RCD_SCRIPTS=		pf pflogd
CONF_FILES=		${WRKSRC}/etc/pf.conf ${PKG_SYSCONFDIR}/pf.conf

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

post-install:
.if !exists(${PREFIX}/etc/pf.os)
	${INSTALL_DATA} ${WRKSRC}/etc/pf.os ${PREFIX}/etc
.endif

.include "../../mk/bsd.pkg.mk"
