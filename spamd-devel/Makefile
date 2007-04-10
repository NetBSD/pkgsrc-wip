# $NetBSD: Makefile,v 1.1.1.1 2007/04/10 18:27:25 jeremy-c-reed Exp $

DISTNAME=		spamd-20070405
CATEGORIES=		mail
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.benzedrine.cx/relaydb.html
COMMENT=		OpenBSD spam deferral daemons and tools

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-* FreeBSD-*-* DragonFly-*-*

NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/src

SPAMD_HOME=		${VARBASE}/chroot/spamd
OWN_DIRS=		${SPAMD_HOME}

CPPFLAGS+=		-DPATH_SPAMD_HOME=\"${SPAMD_HOME}\"
CPPFLAGS+=		-DPATH_SPAMD_DB=\"${VARBASE}/db/spamd\"
CPPFLAGS+=		-DPATH_PFCTL=\"${PFCTL}\"
CPPFLAGS+=		-DPATH_SPAMD_CONF=\"${SPAMD_CONF}\"
CPPFLAGS+=		-DPATH_SPAMD_ALLOWEDDOMAINS=\"${PKG_SYSCONFDIR}/spamd.alloweddomains\"
# Makefile.inc is not being used since it is not in ..
CPPFLAGS+=		-include ${WRKSRC}/compat.h
MAKE_ENV+=		WARNS=1
MAKE_ENV+=		NOGCCERROR=yes


PKG_GROUPS=		_spamd
PKG_USERS=		_spamd:_spamd
PKG_GECOS._spamd=	Spam Daemon User
PKG_HOME._spamd=	${SPAMD_HOME}

RCD_SCRIPTS=		pfspamd

SPAMD_CONF=		${PKG_SYSCONFDIR}/spamd.conf
CONF_FILES=		${PREFIX}/share/examples/spamd/spamd.conf ${SPAMD_CONF}

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	libexec/spamd/spamd.8
SUBST_FILES.fix+=	libexec/spamd-setup/spamd-setup.8
SUBST_SED.fix=		-e 's,/etc/mail/spamd.conf,${SPAMD_CONF},g'
SUBST_MESSAGE.fix=	Fixing configuration paths.

INSTALLATION_DIRS+=	libexec sbin ${PKGMANDIR}/cat5 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 share/examples/spamd

do-extract:
	@${CP} -R ${FILESDIR}/src ${WRKSRC}

do-install:
	${INSTALL_MAN} ${WRKSRC}/share/man/man5/spamd.conf.5 ${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/share/man/man5/spamd.conf.cat5 ${PREFIX}/${PKGMANDIR}/cat5/spamd.conf.0
	${INSTALL_MAN} ${WRKSRC}/libexec/spamd/spamd.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/libexec/spamd/spamd.cat8 ${PREFIX}/${PKGMANDIR}/cat8/spamd.0
	${INSTALL_MAN} ${WRKSRC}/libexec/spamd-setup/spamd-setup.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/libexec/spamd-setup/spamd-setup.cat8 ${PREFIX}/${PKGMANDIR}/cat8/spamd-setup.0
	${INSTALL_MAN} ${WRKSRC}/usr.sbin/spamdb/spamdb.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/usr.sbin/spamdb/spamdb.cat8 ${PREFIX}/${PKGMANDIR}/cat8/spamdb.0
	${INSTALL_MAN} ${WRKSRC}/libexec/spamlogd/spamlogd.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/libexec/spamlogd/spamlogd.cat8 ${PREFIX}/${PKGMANDIR}/cat8/spamlogd.0

	${INSTALL_PROGRAM} ${WRKSRC}/libexec/spamd-setup/spamd-setup ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/libexec/spamd/spamd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/usr.sbin/spamdb/spamdb ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/libexec/spamlogd/spamlogd ${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/etc/mail/spamd.conf ${PREFIX}/share/examples/spamd

.include "../../security/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
