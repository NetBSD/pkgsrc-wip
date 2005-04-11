# $NetBSD: Makefile,v 1.6 2005/04/11 21:10:07 tvierling Exp $
#

DISTNAME=		bastard-0.17-pre
WRKSRC=			${WRKDIR}/bastard_src-0.17
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bastard/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://bastard.sourceforge.net/
COMMENT=		Disassembler for ELF x86 binarys

USE_GNU_TOOLS+=	make

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
