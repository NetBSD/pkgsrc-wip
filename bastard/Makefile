# $NetBSD: Makefile,v 1.8 2005/11/20 18:51:50 rillig Exp $
#

DISTNAME=		bastard-0.17-pre
PKGNAME=		bastard-0.17
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bastard/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://bastard.sourceforge.net/
COMMENT=		Disassembler for ELF x86 binarys

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/bastard_src-0.17

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
