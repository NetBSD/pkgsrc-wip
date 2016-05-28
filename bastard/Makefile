# $NetBSD: Makefile,v 1.11 2012/09/24 17:14:27 asau Exp $
#

DISTNAME=		bastard-0.17-pre
PKGNAME=		bastard-0.17
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bastard/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bastard.sourceforge.net/
COMMENT=		Disassembler for ELF x86 binarys


USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/bastard_src-0.17

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
