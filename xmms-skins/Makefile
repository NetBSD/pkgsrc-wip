# $NetBSD: Makefile,v 1.9 2012/10/08 14:00:39 asau Exp $

DISTNAME=	xmms-skins-0.10
CATEGORIES=	meta-pkgs audio
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.xmms.org/skins.php
COMMENT=	Skins for XMMS

SKINS=		AdamAmp Chaos CherryBest Cobalt CoolBlue Cracked Eclipse \
		Fire HelixSawfish LinuxDotCom m2n MarbleX maXMMS nixamp \
		NoerdAmp-SE Plume Sword UltrafinaSEM VegetalBlues WinampX

.for skin in ${SKINS}
DEPENDS+=	xmms-skin-${skin}-[0-9]*:../../wip/xmms-skin-${skin}
.endfor

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
