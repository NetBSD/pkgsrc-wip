# $NetBSD: Makefile,v 1.2 2004/07/18 15:07:34 ppostma Exp $
#

DISTNAME=	tripwire-2.3.1-2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tripwire/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://tripwire.sourceforge.net/
COMMENT=	File and directory integrity checker

WRKSRC=		${WRKDIR}/${DISTNAME}/src/
CONFLICTS+=	tripwire-1*
ALL_TARGET=	release
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes
ONLY_FOR_PLATFORM= Linux-*-* OpenBSD-*-* FreeBSD-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "OpenBSD"
SYSPRE=i386-unknown-openbsd
.elsif ${OPSYS} == "FreeBSD"
SYSPRE=i386-unknown-freebsd
.endif

MAKE_ENV+=	SYSPRE=${SYSPRE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/${SYSPRE}/* \
		${PREFIX}/sbin/
	#TODO# make this in a foreach loop
	${INSTALL_MAN} ${WRKSRC}/../man/man4/*.4 ${PREFIX}/man/man4/
	${INSTALL_MAN} ${WRKSRC}/../man/man5/*.5 ${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/../man/man8/*.8 ${PREFIX}/man/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/share/tripwire/
	${INSTALL_DATA} ${WRKSRC}/../policy/*.txt ${PREFIX}/share/tripwire/

.include "../../mk/bsd.pkg.mk"
