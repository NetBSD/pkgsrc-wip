# $NetBSD: Makefile,v 1.3 2010/01/06 04:52:16 christtrekker Exp $
#

DISTNAME=	etoile-0.4.1
CATEGORIES=	meta-pkgs gnustep x11
MASTER_SITES=	http://download.gna.org/etoile/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://etoileos.com/
COMMENT=	Desktop environment built on GNUstep
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Etoile-0.4.1
USE_LANGUAGES=	objc

MAKE_FILE=	GNUmakefile

DEPENDS+=	etoile-core:../../gnustep/etoile-core
DEPENDS+=	etoile-services:../../gnustep/etoile-services
# DictionaryReader
# Font Manager
# Melodie
# StepChat
# TypeWriter
# Vindaloo
.include "../../misc/Addresses/buildlink3.mk"

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
