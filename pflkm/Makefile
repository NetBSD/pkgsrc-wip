# $NetBSD: Makefile,v 1.15 2004/06/14 15:36:04 ppostma Exp $

DISTNAME=		pf-lkm-20040607
CATEGORIES=		security ipv6
MASTER_SITES=		http://nedbsd.nl/~ppostma/pf/

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://nedbsd.nl/~ppostma/pf-lkm.html
COMMENT=		OpenBSD PF loadable kernel module for NetBSD

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-*

USE_PKGINSTALL=		yes
USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes

PKG_USERS=		_pflogd:nogroup::pflogd\\ pseudo-user:${VARBASE}/chroot/pflogd:/sbin/nologin

RCD_SCRIPTS=		pf pflogd
PKG_SYSCONFSUBDIR=	pf
CONF_FILES=		${PREFIX}/share/examples/${PKGBASE}/pf.conf \
			${PKG_SYSCONFDIR}/pf.conf
CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/pf.os \
			${PKG_SYSCONFDIR}/pf.os

pre-install:
.if !exists(${PREFIX}/lkm)
	@${INSTALL_DATA_DIR} ${PREFIX}/lkm
.endif
.if !exists(${PREFIX}/include/net)
	@${INSTALL_DATA_DIR} ${PREFIX}/include/net
.endif
.if !exists(${VARBASE}/chroot/pflogd)
	@${INSTALL_DATA_DIR} ${VARBASE}/chroot/pflogd
.endif
.if !exists(${PREFIX}/share/examples/${PKGBASE})
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/pf.conf \
		${PREFIX}/share/examples/${PKGBASE}/pf.conf
	${INSTALL_DATA} ${WRKSRC}/etc/pf.os \
		${PREFIX}/share/examples/${PKGBASE}/pf.os

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	sbin/pfctl/pfctl_parser.h usr.sbin/authpf/pathnames.h
SUBST_SED.path=		-e 's,/etc/pf.os,${PKG_SYSCONFDIR}/pf.os,g'
SUBST_SED.path+=	-e 's,/etc/authpf/authpf.conf,${PKG_SYSCONFDIR}/authpf.conf,g'
SUBST_SED.path+=	-e 's,/etc/authpf/authpf.allow,${PKG_SYSCONFDIR}/authpf.allow,g'
SUBST_SED.path+=	-e 's,/etc/authpf/authpf.rules,${PKG_SYSCONFDIR}/authpf.rules,g'
SUBST_SED.path+=	-e 's,/etc/authpf/authpf.problem,${PKG_SYSCONFDIR}/authpf.problem,g'
SUBST_SED.path+=	-e 's,/etc/authpf/authpf.message,${PKG_SYSCONFDIR}/authpf.message,g'
SUBST_SED.path+=	-e 's,/etc/authpf/users,${PKG_SYSCONFDIR}/users,g'
SUBST_SED.path+=	-e 's,/etc/authpf/banned,${PKG_SYSCONFDIR}/banned,g'
SUBST_SED.path+=	-e 's,/usr/sbin/authpf,${PREFIX}/sbin/authpf,g'
SUBST_SED.path+=	-e 's,/sbin/pfctl,${PREFIX}/sbin/pfctl,g'
SUBST_MESSAGE.path=	"Fixing hardcoded dirs."

.include "../../mk/bsd.pkg.mk"
