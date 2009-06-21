# $NetBSD: Makefile,v 1.1.1.1 2009/06/21 06:17:39 othyro Exp $
#

DISTNAME=	high-pass
PKGNAME=	gimp-${DISTNAME}-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/
EXTRACT_SUFX=	.scm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://registry.gimp.org/files/
COMMENT=	General purpose high-pass filter plugin for GIMP

WRKSRC=		${WRKDIR}/high-pass.scm
#USE_LANGUAGES=	# none

DEPENDS+=	gimp>=2.0:../../graphics/gimp

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	share/gimp/2.0/scripts

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${PREFIX}/share/gimp/2.0/scripts

.include "../../mk/bsd.pkg.mk"
