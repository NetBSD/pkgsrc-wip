# $NetBSD: Makefile,v 1.5 2012/11/19 15:01:53 christtrekker Exp $
#

DISTNAME=	etoile-${VERSN}
CATEGORIES=	meta-pkgs gnustep x11
MASTER_SITES=	http://download.gna.org/etoile/
VERSN=		0.4.1

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://etoileos.com/
COMMENT=	Desktop environment built on GNUstep
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Etoile-${VERSN}
USE_LANGUAGES=	objc

MAKE_FILE=	GNUmakefile

DEPENDS+=	etoile-core>=${VERSN}:../../wip/etoile-core
DEPENDS+=	etoile-services>=${VERSN}:../../wip/etoile-services
# DictionaryReader
# Font Manager
# Melodie
# StepChat
# TypeWriter
# Vindaloo
.include "../../misc/Addresses/buildlink3.mk"

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
