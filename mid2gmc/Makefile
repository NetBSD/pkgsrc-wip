# $NetBSD: Makefile,v 1.1.1.1 2005/01/07 16:08:31 bencollver Exp $
#

DISTNAME=		mid2gmc-0-3
PKGNAME=		mid2gmc-0.3
CATEGORIES=		audio
MASTER_SITES=		http://www.geocities.com/SiliconValley/Software/8918/linux/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Guenthers Midi DeCompiler, convert midi to text

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/mid2gmc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mid2gmc ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
