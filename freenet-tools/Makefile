# $NetBSD: Makefile,v 1.3 2003/09/25 02:45:18 tvierling Exp $
#

DISTNAME=		ft-0.2.12
PKGNAME=		${DISTNAME:S/ft-/freenet-tools-/}
WRKSRC=			${WRKDIR}/ft
CATEGORIES=		security net
MASTER_SITES=		http://entropy.stop1984.com/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@duh.org
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
