# $NetBSD: Makefile,v 1.6 2008/02/26 19:32:49 cheusov Exp $

DISTNAME=	xmms-skins-0.10
CATEGORIES=	meta-pkgs audio
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.xmms.org/skins.php
COMMENT=	Skins for XMMS

PKG_DESTDIR_SUPPORT=	user-destdir

SKINS=		AdamAmp Chaos CherryBest Cobalt CoolBlue Cracked Eclipse \
		Fire HelixSawfish LinuxDotCom m2n MarbleX maXMMS nixamp \
		NoerdAmp-SE Plume Sword UltrafinaSEM VegetalBlues WinampX

.for skin in ${SKINS}
DEPENDS+=	xmms-skin-${skin}-[0-9]*:../../wip/xmms-skin-${skin}
.endfor

EXTRACT_ONLY=	# empty

META_PACKAGE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
