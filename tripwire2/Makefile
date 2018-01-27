# $NetBSD: Makefile,v 1.11 2012/11/25 23:32:31 othyro Exp $
#

DISTNAME=	tripwire-2.3.1-2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tripwire/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/tripwire/
COMMENT=	File and directory integrity checker

WRKSRC=			${WRKDIR}/${DISTNAME}/src/
CONFLICTS+=		tripwire-1*
BUILD_TARGET=		release
USE_TOOLS+=		gmake
ONLY_FOR_PLATFORM=	Linux-*-* OpenBSD-*-* FreeBSD-*-*

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "OpenBSD")
SYSPRE=	i386-unknown-openbsd
.endif
.if (${OPSYS} == "FreeBSD")
SYSPRE=	i386-unknown-freebsd
.endif

MAKE_ENV+=	SYSPRE=${SYSPRE:Q}

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man4 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/${SYSPRE}/* \
		${DESTDIR}${PREFIX}/sbin/
	#TODO# make this in a foreach loop
	${INSTALL_MAN} ${WRKSRC}/../man/man4/*.4 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/
	${INSTALL_MAN} ${WRKSRC}/../man/man5/*.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN} ${WRKSRC}/../man/man8/*.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/tripwire/
	${INSTALL_DATA} ${WRKSRC}/../policy/*.txt ${DESTDIR}${PREFIX}/share/tripwire/

.include "../../mk/bsd.pkg.mk"
