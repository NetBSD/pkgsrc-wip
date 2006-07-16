# $NetBSD: Makefile,v 1.8 2006/07/16 16:08:39 shattered Exp $
#

DISTNAME=	tripwire-2.3.1-2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tripwire/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://sourceforge.net/projects/tripwire/
COMMENT=	File and directory integrity checker

WRKSRC=		${WRKDIR}/${DISTNAME}/src/
CONFLICTS+=	tripwire-1*
BUILD_TARGET=	release
USE_TOOLS+=	gmake
ONLY_FOR_PLATFORM= Linux-*-* OpenBSD-*-* FreeBSD-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "OpenBSD"
SYSPRE=i386-unknown-openbsd
.elsif ${OPSYS} == "FreeBSD"
SYSPRE=i386-unknown-freebsd
.endif

MAKE_ENV+=	SYSPRE=${SYSPRE:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/${SYSPRE}/* \
		${PREFIX}/sbin/
	#TODO# make this in a foreach loop
	${INSTALL_MAN} ${WRKSRC}/../man/man4/*.4 ${PREFIX}/${PKGMANDIR}/man4/
	${INSTALL_MAN} ${WRKSRC}/../man/man5/*.5 ${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN} ${WRKSRC}/../man/man8/*.8 ${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/share/tripwire/
	${INSTALL_DATA} ${WRKSRC}/../policy/*.txt ${PREFIX}/share/tripwire/

.include "../../mk/bsd.pkg.mk"
