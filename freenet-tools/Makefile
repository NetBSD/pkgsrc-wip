# $NetBSD: Makefile,v 1.1.1.1 2003/07/04 20:08:00 tvierling Exp $
#

DISTNAME=		ft-0.2.11
PKGNAME=		${DISTNAME:S/ft-/freenet-tools-/}
WRKSRC=			${WRKDIR}/ft
CATEGORIES=		wip
MASTER_SITES=		http://entropy.stop1984.com/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@pobox.com
HOMEPAGE=		http://entropy.stop1984.com/
COMMENT=		Freenet Tools, freesite manipulation tools for Freenet and Entropy

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

MAKE_FLAGS+=		CC=${CC:Q} LD=${CC:Q} CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ft ${PREFIX}/bin/freenet-tools
.for f in fcpchk fcpdel fcpget fcpgetsite fcphello fcpkey fcpput fcpputsite
	${LN} -s -f freenet-tools ${PREFIX}/bin/$f
.endfor

.include "../../mk/bsd.pkg.mk"
