# $NetBSD: Makefile,v 1.1.1.1 2003/05/07 21:52:11 poppnk Exp $

DISTNAME=	WEPCrack-0.0.10
WRKSRC=		${WRKDIR}/
CATEGORIES=	security
MASTER_SITES=	http://belnet.dl.sourceforge.net/sourceforge/wepcrack/ \
		http://heanet.dl.sourceforge.net/sourceforge/ap-utils/ \
		http://twtelecom.dl.sourceforge.net/sourceforge/ap-utils/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://wepcrack.sourceforge.net/
COMMENT=	Open source tool for breaking 802.11 WEP secret keys

USE_GMAKE=	yes
MAKE_ENV+=	WRKSRC="${WRKSRC}"
USE_PERL5=	yes
REPLACE_PERL=	${WRKSRC}/*.pl

.include	"../../mk/bsd.pkg.mk"
