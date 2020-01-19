# $NetBSD: Makefile,v 1.8 2013/01/20 00:27:17 othyro Exp $
#

DISTNAME=	audit-system-0.01
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.NetBSD.org/support/security/
COMMENT=	Check the NetBSD base OS for known vulnerabilities
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none

ONLY_FOR_PLATFORM=	NetBSD-*-*

AS_FILES=	audit-get-ident audit-get-mtime audit-get-objdump audit-system \
		audit-system.8 audit-system.conf audit-system.conf.5
EGDIR=		${PREFIX}/share/examples/audit-system
SYSVULNDIR=	${VARBASE}/db
SCRIPT_DIR=	${PREFIX}/sbin
FETCH_TOOL=	${FTP}

BUILD_DEFS=		VARBASE
CONF_FILES+=		${EGDIR}/audit-system.conf ${PKG_SYSCONFDIR}/audit-system.conf
USE_TOOLS+=		awk cp mv ident chmod mkdir find rm echo
MAKE_DIRS=		${SYSVULNDIR}
INSTALLATION_DIRS+=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 ${EGDIR} sbin

.include "../../mk/bsd.prefs.mk"

STAT?=		/usr/bin/stat
OBJDUMP?=	/usr/bin/objdump
CKSUM?=		/usr/bin/cksum
FTP?=		/usr/bin/ftp

SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	post-configure
SUBST_FILES.tools+=	${AS_FILES}
SUBST_VARS.tools=	AWK
SUBST_VARS.tools+=	SH
SUBST_VARS.tools+=	CP
SUBST_VARS.tools+=	MV
SUBST_VARS.tools+=	RM
SUBST_VARS.tools+=	IDENT
SUBST_VARS.tools+=	OBJDUMP
SUBST_VARS.tools+=	STAT
SUBST_VARS.tools+=	CHMOD
SUBST_VARS.tools+=	MKDIR
SUBST_VARS.tools+=	FIND
SUBST_VARS.tools+=	CKSUM
SUBST_VARS.tools+=	FETCH_TOOL
SUBST_VARS.tools+=	ECHO
SUBST_VARS.tools+=	SYSVULNDIR
SUBST_VARS.tools+=	SCRIPT_DIR
SUBST_VARS.tools+=	PKG_SYSCONFDIR

do-extract:
.for f in ${AS_FILES}
	${CP} ${FILESDIR}/${f} ${WRKSRC}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/audit-system.conf ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/audit-get-ident ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/audit-get-mtime ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/audit-get-objdump ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/audit-system ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/audit-system.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/audit-system.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../mk/bsd.pkg.mk"
