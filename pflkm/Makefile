# $NetBSD: Makefile,v 1.8 2004/06/09 09:21:25 ppostma Exp $

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

PKG_USERS=		_pflogd:nogroup:60:pflogd\\ pseudo-user:/var/empty:/sbin/nologin

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
.if !exists(/var/empty)
	@${INSTALL_DATA_DIR} /var/empty
.endif

post-install:
.if !exists(${PREFIX}/etc/pf.os)
	${INSTALL_DATA} ${WRKSRC}/etc/pf.os ${PREFIX}/etc
.endif
.if !exists(${PREFIX}/etc/pf.conf)
	${INSTALL_DATA} ${WRKSRC}/etc/pf.conf ${PREFIX}/etc
.endif

.include "../../mk/bsd.pkg.mk"
