# $NetBSD: Makefile,v 1.3 2007/05/16 21:26:30 cheusov Exp $

DISTNAME=	xmms-skins-0.10
CATEGORIES=	meta-pkgs audio
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.xmms.org/skins.php
COMMENT=	Skins for XMMS

SKINS=		AdamAmp Cracked Eclipse Fire HelixSawfish LinuxDotCom \
		Plume UltrafinaSEM VegetalBlues nixamp

.for skin in ${SKINS}
DEPENDS+=	xmms-skin-${skin}-[0-9]*:../../wip/xmms-skin-${skin}
.endfor

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
