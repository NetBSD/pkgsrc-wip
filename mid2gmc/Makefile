# $NetBSD: Makefile,v 1.3 2012/10/03 14:12:48 asau Exp $
#

DISTNAME=		mid2gmc-0-3
PKGNAME=		mid2gmc-0.3
CATEGORIES=		audio
MASTER_SITES=		http://www.geocities.com/SiliconValley/Software/8918/linux/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Guenthers Midi DeCompiler, convert midi to text

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/mid2gmc

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mid2gmc ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
