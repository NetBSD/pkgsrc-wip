# $NetBSD: Makefile,v 1.1.1.1 2008/07/03 21:55:39 adrian_p Exp $
#

DISTNAME=	audit-system-0.01
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/support/security/
COMMENT=	Verifier for NetBSD packages and complete pkgsrc tree

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes
NO_MTREE=	yes
USE_LANGUAGES=	# none

#ONLY_FOR_PLATFORM=	NetBSD-*-*

AS_FILES=	audit-get-ident audit-get-mtime audit-get-objdump audit-system \
		audit-system.8

USE_TOOLS+=	awk cp mv ident

.include "../../mk/bsd.prefs.mk"

STAT?=		/usr/bin/stat
OBJDUMP?=	/usr/bin/objdump

SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	post-configure
SUBST_FILES.tools+=	audit-get-ident audit-get-mtime audit-get-objdump
SUBST_FILES.tools+=	audit-system
SUBST_SED.tools=	-e "s|@AWK@|${AWK}|g"
SUBST_SED.tools+=	-e "s|@SH@|${SH}|g"
SUBST_SED.tools+=	-e "s|@CP@|${CP}|g"
SUBST_SED.tools+=	-e "s|@MV@|${MV}|g"
SUBST_SED.tools+=	-e "s|@IDENT@|${IDENT}|g"
SUBST_SED.tools+=	-e "s|@OBJDUMP@|${OBJDUMP}|g"
SUBST_SED.tools+=	-e "s|@STAT@|${STAT}|g"

do-extract:
.	for f in ${AS_FILES}
		${CP} ${FILESDIR}/${f} ${WRKSRC}
.	endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/audit-get-ident ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/audit-get-mtime ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/audit-get-objdump ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/audit-get-system ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
