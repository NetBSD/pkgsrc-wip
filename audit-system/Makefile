# $NetBSD: Makefile,v 1.2 2008/07/04 20:11:44 adrian_p Exp $
#

DISTNAME=	audit-system-0.01
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/support/security/
COMMENT=	Check the NetBSD base OS for known vulnerabilities

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes
NO_MTREE=	yes
USE_LANGUAGES=	# none

#ONLY_FOR_PLATFORM=	NetBSD-*-*

AS_FILES=	audit-get-ident audit-get-mtime audit-get-objdump audit-system \
		audit-system.8 audit-system.conf
EGDIR=		${PREFIX}/share/examples/audit-system
SYSVULNDIR=	${VARBASE}/db
SCRIPT_DIR=	${PREFIX}/sbin
FETCH_TOOL=	${FTP}

BUILD_DEFS=	VARBASE
CONF_FILES+=	${EGDIR}/audit-system.conf ${PKG_SYSCONFDIR}/audit-system.conf
USE_TOOLS+=	awk cp mv ident chmod mkdir find rm echo
MAKE_DIRS=	${SYSVULNDIR}

.include "../../mk/bsd.prefs.mk"

STAT?=		/usr/bin/stat
OBJDUMP?=	/usr/bin/objdump
#CKSUM?=	/usr/bin/cksum -a
CKSUM?=		/usr/pkg/bin/digest
FTP?=		/usr/bin/ftp

SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	post-configure
SUBST_FILES.tools+=	audit-get-ident audit-get-mtime audit-get-objdump
SUBST_FILES.tools+=	audit-system audit-system.conf
SUBST_SED.tools=	-e "s|@AWK@|${AWK}|g"
SUBST_SED.tools+=	-e "s|@SH@|${SH}|g"
SUBST_SED.tools+=	-e "s|@CP@|${CP}|g"
SUBST_SED.tools+=	-e "s|@MV@|${MV}|g"
SUBST_SED.tools+=	-e "s|@RM@|${RM}|g"
SUBST_SED.tools+=	-e "s|@IDENT@|${IDENT}|g"
SUBST_SED.tools+=	-e "s|@OBJDUMP@|${OBJDUMP}|g"
SUBST_SED.tools+=	-e "s|@STAT@|${STAT}|g"
SUBST_SED.tools+=	-e "s|@CHMOD@|${CHMOD}|g"
SUBST_SED.tools+=	-e "s|@MKDIR@|${MKDIR}|g"
SUBST_SED.tools+=	-e "s|@FIND@|${FIND}|g"
SUBST_SED.tools+=	-e "s|@CKSUM@|${CKSUM}|g"
SUBST_SED.tools+=	-e "s|@FETCH_TOOL@|${FETCH_TOOL}|g"
SUBST_SED.tools+=	-e "s|@ECHO@|${ECHO}|g"
SUBST_SED.tools+=	-e "s|@SYSVULNDIR@|${SYSVULNDIR}|g"
SUBST_SED.tools+=	-e "s|@SCRIPT_DIR@|${SCRIPT_DIR}|g"
SUBST_SED.tools+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"

do-extract:
.	for f in ${AS_FILES}
		${CP} ${FILESDIR}/${f} ${WRKSRC}
.	endfor

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}

	${INSTALL_DATA} ${WRKSRC}/audit-system.conf ${EGDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/audit-get-ident ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/audit-get-mtime ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/audit-get-objdump ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/audit-system ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
