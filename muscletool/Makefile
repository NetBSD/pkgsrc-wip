# $NetBSD: Makefile,v 1.2 2006/10/29 08:32:48 shattered Exp $

DISTNAME=		muscletool-2.1.0
CATEGORIES=		security
MASTER_SITES=	http://alioth.debian.org/download.php/1434/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.musclecard.com/
COMMENT=		Personalization tool for MuscleCard enabled smartcards

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../wip/libmusclecard/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
