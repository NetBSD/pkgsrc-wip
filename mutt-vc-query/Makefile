# $NetBSD: Makefile,v 1.1.1.1 2003/09/08 10:41:04 bjan2 Exp $

DISTNAME=	mutt_vc_query-002
CATEGORIES=	databases
MASTER_SITES=	http://osdn.dl.sourceforge.net/sourceforge/rolo/

MAINTAINER=	bjan+pkgsrc@bjan.net
HOMEPAGE=	http://rolo.sf.net/
COMMENT=	Mutt query interface for rolo

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

.include "../../wip/libvc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
