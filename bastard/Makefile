# $NetBSD: Makefile,v 1.3 2004/01/25 02:11:33 grantbeattie Exp $
#

DISTNAME=		bastard-0.17-pre
WRKSRC=			${WRKDIR}/bastard_src-0.17
CATEGORIES=		wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bastard/}
EXTRACT_SUFX=	.tgz

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://bastard.sourceforge.net/
COMMENT=		Disassembler for ELF x86 binarys

USE_BUILDLINK2= YES
USE_GNU_TOOLS+=	make

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
