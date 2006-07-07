# $NetBSD: Makefile,v 1.1.1.1 2006/07/07 19:26:40 thomasklausner Exp $

DISTNAME=		muscletool-2.1.0
CATEGORIES=		security
MASTER_SITES= 		http://alioth.debian.org/download.php/1434/

MAINTAINER=             evaldo@gardenali.biz
HOMEPAGE=		http://www.musclecard.com/
COMMENT=		Personalization tool for MuscleCard enabled smartcards

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../wip/libmusclecard/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
